/*
 * LightsaberCrystalComponentImplementation.cpp
 *
 *      Author: Katherine
 */

#include "engine/engine.h"
#include "server/zone/objects/player/sui/messagebox/SuiMessageBox.h"
#include "server/zone/objects/tangible/component/lightsaber/LightsaberCrystalComponent.h"
#include "server/zone/packets/object/ObjectMenuResponse.h"
#include "server/zone/objects/tangible/wearables/WearableContainerObject.h"
#include "server/zone/packets/scene/AttributeListMessage.h"
#include "server/zone/objects/player/PlayerObject.h"
#include "server/zone/objects/player/sui/callbacks/LightsaberCrystalTuneSuiCallback.h"
#include "server/zone/objects/tangible/weapon/WeaponObject.h"
#include "server/zone/managers/stringid/StringIdManager.h"
#include "server/zone/managers/loot/LootManager.h"
#include "server/zone/ZoneServer.h"

void LightsaberCrystalComponentImplementation::initializeTransientMembers() {
	ComponentImplementation::initializeTransientMembers();

	setLoggingName("LightsaberCrystalComponent");
}

void LightsaberCrystalComponentImplementation::notifyLoadFromDatabase() {
	// Randomize item level and stats for existing crystals based on original quality value
	// TODO: Remove this on a server wipe when old variables are removed
	if (minimumDamage != maximumDamage || itemLevel == 0) {
		if (quality == POOR)
			itemLevel = 1 + System::random(38); // 1-39
		else if (quality == FAIR)
			itemLevel = 40 + System::random(29); // 40-69
		else if (quality == GOOD)
			itemLevel = 70 + System::random(29); // 70-99
		else if (quality == QUALITY)
			itemLevel = 100 + System::random(39); // 100-139
		else if (quality == SELECT)
			itemLevel = 140 + System::random(79); // 140-219
		else if (quality == PREMIUM)
			itemLevel = 220 + System::random(109); // 220-329
		else
			itemLevel = 330 + System::random(20);

		attackSpeed = 0.0;
		minimumDamage = 0;
		maximumDamage = 0;
		sacHealth = 0;
		sacAction = 0;
		sacMind = 0;
		woundChance = 0;
		forceCost = 0;
		floatForceCost = 0.0;

	}

	TangibleObjectImplementation::notifyLoadFromDatabase();
}

void LightsaberCrystalComponentImplementation::loadTemplateData(SharedObjectTemplate* templateData) {
	TangibleObjectImplementation::loadTemplateData(templateData);

}
int LightsaberCrystalComponentImplementation::getCrystalQuality() {
	if (itemLevel < 40)
		return POOR;
	else if (itemLevel < 70)
		return FAIR;
	else if (itemLevel < 100)
		return GOOD;
	else if (itemLevel < 140)
		return QUALITY;
	else if (itemLevel < 220)
		return SELECT;
	else if (itemLevel < 330)
		return PREMIUM;
	else
		return FLAWLESS;
}

int LightsaberCrystalComponentImplementation::getRandomizedStat(int min, int max, int itemLevel) {
	bool invertedValues = false;
	int invertedMin = min;
	int invertedMax = max;

	if (min > max) {
		int temp = min;
		min = max;
		max = temp;

		invertedValues = true;
	}

	float avgLevel = (float)(itemLevel - 60) / 220.f;

	float midLevel = min + ((max - min) * avgLevel);

	if (midLevel < min) {
		max += (midLevel - min);
		midLevel = min;
	}

	if (midLevel > max) {
		min += (midLevel - max);
		midLevel = max;
	}

	int randMin = min + System::random((int)(midLevel + 0.5f) - min);
	int randMax = (int)(midLevel + 0.5f) + System::random(max - midLevel);

	int result = randMin + System::random(randMax - randMin);

	if (invertedValues)
		result = invertedMin + (invertedMax - result);

	return result;
}

float LightsaberCrystalComponentImplementation::getRandomizedStat(float min, float max, int itemLevel) {
	bool invertedValues = false;
	float invertedMin = min;
	float invertedMax = max;

	if (min > max) {
		float temp = min;
		min = max;
		max = temp;

		invertedValues = true;
	}

	float avgLevel = (float)(itemLevel - 60) / 220.f;

	float midLevel = min + ((max - min) * avgLevel);

	if (midLevel < min) {
		max += (midLevel - min);
		midLevel = min;
	}

	if (midLevel > max) {
		min += (midLevel - max);
		midLevel = max;
	}

	float randMin = System::getMTRand()->rand(midLevel - min) + min;
	float randMax = System::getMTRand()->rand(max - midLevel) + midLevel;

	float result = System::getMTRand()->rand(randMax - randMin) + randMin;

	if (invertedValues)
		result = invertedMin + (invertedMax - result);

	return result;
}

void LightsaberCrystalComponentImplementation::fillAttributeList(AttributeListMessage* alm, CreatureObject* object) {
	TangibleObjectImplementation::fillAttributeList(alm, object);

	PlayerObject* player = object->getPlayerObject();
	if (object->hasSkill("force_title_jedi_rank_01") || player->isPrivileged()) {
		if (ownerID == 0) {
			StringBuffer str;
			str << "\\#pcontrast2 UNTUNED";
			alm->insertAttribute("crystal_owner", str);
		} else {
			alm->insertAttribute("crystal_owner", ownerName);
		}

		//if (getColor() != 31) {
			StringBuffer str3;
			str3 << "@jedi_spam:saber_color_" << getColor();
			alm->insertAttribute("color", str3);
		//} else {
			if (ownerID != 0 || player->isPrivileged()) {
				alm->insertAttribute("mindamage", damage);
				alm->insertAttribute("maxdamage", damage);
				alm->insertAttribute("wpn_attack_speed", attackSpeed);
				alm->insertAttribute("wpn_wound_chance", woundChance);
				alm->insertAttribute("wpn_attack_cost_health", sacHealth);
				alm->insertAttribute("wpn_attack_cost_action", sacAction);
				alm->insertAttribute("wpn_attack_cost_mind", sacMind);
				alm->insertAttribute("forcecost", (float)getForceCost());

				// For debugging
				if (player->isPrivileged()) {
					StringBuffer str;
					str << "@jedi_spam:crystal_quality_" << getQuality();
					alm->insertAttribute("challenge_level", itemLevel);
					alm->insertAttribute("crystal_quality", str);
				}
			 	else {
					StringBuffer str;
					str << "@jedi_spam:crystal_quality_" << getQuality();
					alm->insertAttribute("crystal_quality", str);
				}
		}
	}
}

void LightsaberCrystalComponentImplementation::fillObjectMenuResponse(ObjectMenuResponse* menuResponse, CreatureObject* player) {
	if (ownerID == 0 && player->hasSkill("force_title_jedi_rank_01") && hasPlayerAsParent(player)) {
		String text = "@jedi_spam:tune_crystal";
		menuResponse->addRadialMenuItem(128, 3, text);
	}

	PlayerObject* ghost = player->getPlayerObject();
	if (ghost != nullptr && ghost->isPrivileged()) {
		menuResponse->addRadialMenuItem(129, 3, "Staff Commands");

		//if (getColor() == 31)
			menuResponse->addRadialMenuItemToRadialID(129, 130, 3, "Recalculate Stats");

		if (ownerID != 0)
			menuResponse->addRadialMenuItemToRadialID(129, 131, 3, "Untune Crystal");
	}

	ComponentImplementation::fillObjectMenuResponse(menuResponse, player);
}

int LightsaberCrystalComponentImplementation::handleObjectMenuSelect(CreatureObject* player, byte selectedID) {
	if (selectedID == 128 && player->hasSkill("force_title_jedi_rank_01") && hasPlayerAsParent(player) && ownerID == 0) {
		ManagedReference<SuiMessageBox*> suiMessageBox = new SuiMessageBox(player, SuiWindowType::TUNE_CRYSTAL);

		suiMessageBox->setPromptTitle("@jedi_spam:confirm_tune_title");
		suiMessageBox->setPromptText("@jedi_spam:confirm_tune_prompt");
		suiMessageBox->setCancelButton(true, "Cancel");
		suiMessageBox->setUsingObject(_this.getReferenceUnsafeStaticCast());
		suiMessageBox->setCallback(new LightsaberCrystalTuneSuiCallback(player->getZoneServer()));

		player->getPlayerObject()->addSuiBox(suiMessageBox);
		player->sendMessage(suiMessageBox->generateMessage());
	}

	PlayerObject* ghost = player->getPlayerObject();
	if (ghost != nullptr && ghost->isPrivileged()){
			if (selectedID == 130) {

			} else if (selectedID == 131 && ownerID != 0) {
				ownerID = 0;

			String tuneName = StringIdManager::instance()->getStringId(objectName.getFullPath().hashCode()).toString();
			if (getCustomObjectName().toString().contains("(Exceptional)"))
				tuneName = tuneName + " (Exceptional)\\#.";
			else if (getCustomObjectName().toString().contains("(Legendary)"))
				tuneName = tuneName + " (Legendary)\\#.";
			else
				tuneName = tuneName + "\\#.";
		}
	}

	return 0;
}

bool LightsaberCrystalComponentImplementation::hasPlayerAsParent(CreatureObject* player) {
	ManagedReference<SceneObject*> wearableParent = getParentRecursively(SceneObjectType::WEARABLECONTAINER);
	SceneObject* inventory = player->getSlottedObject("inventory");
	SceneObject* bank = player->getSlottedObject("bank");

	// Check if crystal is inside a wearable container in bank or inventory
	if (wearableParent != nullptr) {
		ManagedReference<WearableContainerObject*> wearable = cast<WearableContainerObject*>(wearableParent.get());

		if (wearable != nullptr) {
			SceneObject* parentOfWearableParent = wearable->getParent().get();

			if (parentOfWearableParent == inventory || parentOfWearableParent == bank)
				return true;
		}
	} else {
		// Check if crystal is in inventory or bank
		SceneObject* thisParent = getParent().get();

		if (thisParent == inventory || thisParent == bank)
			return true;
	}
	return false;
}

void LightsaberCrystalComponentImplementation::tuneCrystal(CreatureObject* player) {
	if(!player->hasSkill("force_title_jedi_rank_01") || !hasPlayerAsParent(player)) {
		return;
	}

	if (ownerID == 0) {


		ownerID = player->getObjectID();
		ownerName = player->getDisplayedName();

		// Color code is lime green.
		String tuneName = StringIdManager::instance()->getStringId(objectName.getFullPath().hashCode()).toString();
		if (getCustomObjectName().toString().contains("(Exceptional)"))
			tuneName = "\\#00FF00" + tuneName + " (Exceptional) (tuned)\\#.";
		else if (getCustomObjectName().toString().contains("(Legendary)"))
			tuneName = "\\#00FF00" + tuneName + " (Legendary) (tuned)\\#.";
		else
			tuneName = "\\#00FF00" + tuneName + " (tuned)\\#.";

		setCustomObjectName(tuneName, true);
		player->notifyObservers(ObserverEventType::TUNEDCRYSTAL, _this.getReferenceUnsafeStaticCast(), 0);
		player->sendSystemMessage("@jedi_spam:crystal_tune_success");
	}
}

void LightsaberCrystalComponentImplementation::updateCrystal(int value){
	byte type = 0x02;
	setCustomizationVariable(type, value, true);
}

void LightsaberCrystalComponentImplementation::updateCraftingValues(CraftingValues* values, bool firstUpdate) {
	int colorMax = values->getMaxValue("color");
	int color = values->getCurrentValue("color");
		int finalColor;

	if (colorMax > 11) 
		finalColor = colorMax;
	else 
		finalColor = Math::min(color, 11);

	setColor(finalColor);
	updateCrystal(finalColor);

	int minStat = values->getMinValue("mindamage");
	int maxStat = values->getMaxValue("mindamage");
	int minDamage = getRandomizedStat(minStat,maxStat, itemLevel);

	minStat = values->getMinValue("maxdamage");
	maxStat = values->getMaxValue("maxdamage");
	int maxDamage = getRandomizedStat(minStat,maxStat, itemLevel);

	damage = getRandomizedStat(minDamage, maxDamage, itemLevel);
	if (damage > maxStat)
		damage = maxStat;

	minStat = values->getMinValue("hitpoints");
	maxStat = values->getMaxValue("hitpoints");
	maxCondition = getRandomizedStat(minStat, maxStat, itemLevel);
	if (maxCondition > maxStat)
		maxCondition = maxStat;

	minStat = values->getMinValue("attackhealthcost");
	maxStat = values->getMaxValue("attackhealthcost");
	sacHealth = getRandomizedStat(minStat, maxStat, itemLevel);
	if (sacHealth < maxStat)
		sacHealth = maxStat;

	minStat = values->getMinValue("attackactioncost");
	maxStat = values->getMaxValue("attackactioncost");
	sacAction = getRandomizedStat(minStat, maxStat, itemLevel);
	if (sacAction < maxStat)
		sacAction = maxStat;

	minStat = values->getMinValue("attackmindcost");
	maxStat = values->getMaxValue("attackmindcost");
	sacMind = getRandomizedStat(minStat, maxStat, itemLevel);
	if (sacMind < maxStat)
		sacMind = maxStat;

	minStat = values->getMinValue("woundchance");
	maxStat = values->getMaxValue("woundchance");
	woundChance = getRandomizedStat(minStat, maxStat, itemLevel);
	if (woundChance > maxStat)
		woundChance = maxStat;

	float minFloatStat = values->getMinValue("attackspeed");
	float maxFloatStat = values->getMaxValue("attackspeed");
	attackSpeed = Math::getPrecision(getRandomizedStat(minFloatStat, maxFloatStat, itemLevel), 2);
	if (attackSpeed < maxFloatStat)
		attackSpeed = maxFloatStat;

	minFloatStat = values->getMinValue("forcecost");
	maxFloatStat = values->getMaxValue("forcecost");
	floatForceCost = Math::getPrecision(getRandomizedStat(minFloatStat, maxFloatStat, itemLevel), 1);
	if (floatForceCost < maxFloatStat)
		floatForceCost = maxFloatStat;

	quality = getCrystalQuality();

	ComponentImplementation::updateCraftingValues(values, firstUpdate);
}

int LightsaberCrystalComponentImplementation::inflictDamage(TangibleObject* attacker, int damageType, float damage, bool destroy, bool notifyClient) {
	if (isDestroyed()) {
		return 0;
	}

	TangibleObjectImplementation::inflictDamage(attacker, damageType, damage, destroy, notifyClient);

	if (isDestroyed()) {
		ManagedReference<WeaponObject*> weapon = cast<WeaponObject*>(_this.getReferenceUnsafeStaticCast()->getParent().get()->getParent().get().get());

		if (weapon != nullptr) {
			weapon->setAttackSpeed(weapon->getAttackSpeed() - getAttackSpeed());
			weapon->setMinDamage(weapon->getMinDamage() - getDamage());
			weapon->setMaxDamage(weapon->getMaxDamage() - getDamage());
			weapon->setHealthAttackCost(weapon->getHealthAttackCost() - getSacHealth());
			weapon->setActionAttackCost(weapon->getActionAttackCost() - getSacAction());
			weapon->setMindAttackCost(weapon->getMindAttackCost() - getSacMind());
			weapon->setWoundsRatio(weapon->getWoundsRatio() - getWoundChance());
			weapon->setForceCost(weapon->getForceCost() - getForceCost());

			if (getColor() != 31 && weapon->isEquipped()) {
				ManagedReference<CreatureObject*> parent = cast<CreatureObject*>(weapon->getParent().get().get());
				ManagedReference<SceneObject*> inventory = parent->getSlottedObject("inventory");
				inventory->transferObject(weapon, -1, true, true);
				parent->sendSystemMessage("@jedi_spam:lightsaber_no_color"); //That lightsaber can not be used until it has a color-modifying Force crystal installed.
				}
			}
		}

		return 0;
}
