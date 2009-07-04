/*
Copyright (C) 2007 <SWGEmu>

This File is part of Core3.

This program is free software; you can redistribute
it and/or modify it under the terms of the GNU Lesser
General Public License as published by the Free Software
Foundation; either version 2 of the License,
or (at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.
See the GNU Lesser General Public License for
more details.

You should have received a copy of the GNU Lesser General
Public License along with this program; if not, write to
the Free Software Foundation, Inc., 51 Franklin St, Fifth Floor, Boston, MA 02110-1301 USA

Linking Engine3 statically or dynamically with other modules
is making a combined work based on Engine3.
Thus, the terms and conditions of the GNU Lesser General Public License
cover the whole combination.

In addition, as a special exception, the copyright holders of Engine3
give you permission to combine Engine3 program with free software
programs or libraries that are released under the GNU LGPL and with
code included in the standard release of Core3 under the GNU LGPL
license (or modified versions of such code, with unchanged license).
You may copy and distribute such a system following the terms of the
GNU LGPL for Engine3 and the licenses of the other code concerned,
provided that you include the source code of that other code when
and as the GNU LGPL requires distribution of source code.

Note that people who make modified versions of Engine3 are not obligated
to grant this special exception for their modified versions;
it is their choice whether to do so. The GNU Lesser General Public License
gives permission to release a modified version without this exception;
this exception also makes it possible to release a modified version
which carries forward this exception.
*/


#include "Pharmaceutical.h"
#include "PharmaceuticalImplementation.h"

#include "../../../objects.h"

PharmaceuticalImplementation::PharmaceuticalImplementation(uint64 oid, uint32 tempCRC, const UnicodeString& n, const String& tempn, int mptype)
		: PharmaceuticalServant(oid, PHARMACEUTICAL) {

	objectCRC = tempCRC;

	customName = n;
	stfName = tempn;

	setMedpackType(mptype);
	init();
}

PharmaceuticalImplementation::PharmaceuticalImplementation(CreatureObject* creature, uint64 oid, uint32 tempCRC, const UnicodeString& n, const String& tempn, int mptype)
		: PharmaceuticalServant(oid, PHARMACEUTICAL) {

	objectCRC = tempCRC;

	customName = n;
	stfName = tempn;

	setParent((TangibleObject*) creature->getInventory(), 0xFFFFFFFF);

	setMedpackType(mptype);
	init();
}


PharmaceuticalImplementation::PharmaceuticalImplementation(CreatureObject* creature, uint32 tempCRC, const UnicodeString& n, const String& tempn, int mptype)
		: PharmaceuticalServant(creature->getNewItemID(), PHARMACEUTICAL) {

	objectCRC = tempCRC;

	customName = n;
	stfName = tempn;

	//setContainer((TangibleObject*) creature->getInventory(), 0xFFFFFFFF);

	setMedpackType(mptype);
	init();
}

PharmaceuticalImplementation::~PharmaceuticalImplementation() {
}

void PharmaceuticalImplementation::init() {
	setUsesRemaining(0);
	setMedicineUseRequired(0);
}

void PharmaceuticalImplementation::sendDeltas(Player* player) {
	TangibleObjectDeltaMessage3 * dtano3 = new TangibleObjectDeltaMessage3((TangibleObject*)_this);
	if (getUsesRemaining() == 1)
		dtano3->addIntUpdate(7,  0);
	else
		dtano3->addIntUpdate(7, getUsesRemaining()); //Update the number of charges on the pack in inventory.
	dtano3->close();
	player->sendMessage(dtano3);
}


void PharmaceuticalImplementation::generateAttributes(SceneObject* obj) {
	if (!obj->isPlayer())
		return;

	Player* player = (Player*) obj;
	AttributeListMessage* alm = new AttributeListMessage((TangibleObject*) _this);

	addAttributes(alm);

	player->sendMessage(alm);
}

void PharmaceuticalImplementation::parseItemAttributes() {
	String attr = "usesRemaining";
	setUsesRemaining(itemAttributes->getIntAttribute(attr));

	attr = "medicineUseRequired";
	setMedicineUseRequired(itemAttributes->getIntAttribute(attr));

	attr = "medpackType";
	setMedpackType(itemAttributes->getIntAttribute(attr));
}

void PharmaceuticalImplementation::addHeaderAttributes(AttributeListMessage* alm) {
	alm->insertAttribute("volume", "1");
	alm->insertAttribute("counter_uses_remaining", getUsesRemaining());

	if (craftersName != ""){
		alm->insertAttribute("crafter", craftersName);
	}

	if (craftedSerial != ""){
		alm->insertAttribute("serial_number", craftedSerial);
	}
}

void PharmaceuticalImplementation::addFooterAttributes(AttributeListMessage* alm) {
	alm->insertAttribute("healing_ability", getMedicineUseRequired());
}

void PharmaceuticalImplementation::addAttributes(AttributeListMessage* alm) {
	addHeaderAttributes(alm);
	addFooterAttributes(alm);
}

void PharmaceuticalImplementation::useCharge(Player* player) {
	setUsesRemaining(getUsesRemaining() - 1);

	if (getUsesRemaining() <= 0) {
		sendDestroyTo(player);

		Zone* zone = player->getZone();

		if (zone != NULL) {
			ZoneServer* zoneServer = zone->getZoneServer();

			ItemManager* itemManager;
			if (zoneServer != NULL && ((itemManager = zoneServer->getItemManager()) != NULL)) {
				player->removeInventoryItem(objectID);

				itemManager->deletePlayerItem(player, _this, false);

				_this->finalize();
			}
		}
	} else {
		sendDeltas(player);
	}
}
