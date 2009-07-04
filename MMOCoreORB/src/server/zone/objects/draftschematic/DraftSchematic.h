/*
 *	server/zone/objects/draftschematic/DraftSchematic.h generated by engine3 IDL compiler 0.55
 */

#ifndef DRAFTSCHEMATIC_H_
#define DRAFTSCHEMATIC_H_

#include "engine/orb/DistributedObjectBroker.h"

#include "engine/core/ManagedObject.h"

class SceneObject;

class IntangibleObject;

class Player;

class DraftSchematicIngredient;

class DraftSchematicAttribute;

class DraftSchematicValues;

class DraftSchematicExpPropGroup;

class ObjectControllerMessage;

#include "../scene/SceneObject.h"

class DraftSchematic : public SceneObject {
public:
	DraftSchematic(unsigned int oid, const String& objName, const String& StringFile, const String& StringName, unsigned int objCRC, const String& groupName, unsigned int complexity, unsigned int schematicSize, int craftingToolTab);

	DraftSchematic(DraftSchematic* draftSchematic);

	DraftSchematic* dsClone(DraftSchematic* draftSchematic);

	void destroy(Player* player);

	void sendTo(Player* player);

	void addExperimentalProperty(unsigned int groupNumber, const String& experimentalProperty, unsigned int weight, String& title, String& subtitle, float min, float max, int precision);

	void sendExperimentalPropertiesToPlayer(Player* player);

	void increaseComplexity();

	void decreaseComplexity();

	void increaseExpCounter();

	void sendIngredientsToPlayer(Player* player);

	void helperSendIngredientsToPlayer(ObjectControllerMessage* objMsg);

	void addIngredient(const String& ingredientTemplateName, const String& ingredientTitleName, const int optional, const String& resourceType, unsigned int resourceQuantity, unsigned int combineType, unsigned int contribution);

	void setTanoAttributes(String& attributes);

	void setBlueFrogAttributes(String& attributes);

	void setBlueFrogEnabled(bool enabled);

	void setXpType(String& type);

	void setXp(int x);

	void setExpCounter(int value);

	void setExpPoints(int points);

	void setExpFailure(float rate);

	void setExperimentingSkill(const String& exp);

	void setCustomizationSkill(const String& cust);

	void addCustomizationOption(const String& cust, const int value);

	void setAssemblySkill(const String& ass);

	void setResourcesWereRemoved();

	void setFinished();

	void setCrafter(Player* crafter);

	void setManufacturingLimit(int value);

	String& getTanoStfName();

	int getExpPropGroupListSize();

	DraftSchematicExpPropGroup* getExpPropGroup(int index);

	DraftSchematicExpPropGroup* cloneExpPropGroup(int index);

	unsigned int getSchematicID();

	DraftSchematicIngredient* getIngredient(int index);

	DraftSchematicIngredient* cloneIngredient(int index);

	int getIngredientListSize();

	int getRequiredIngredientCount();

	String& getGroupName();

	unsigned int getComplexity();

	unsigned int getSchematicSize();

	String& getTanoAttributes();

	String& getBlueFrogAttributes();

	bool getBlueFrogEnabled();

	int getCraftingToolTab();

	String& getXpType();

	int getXp();

	String& getExperimentingSkill();

	String& getCustomizationSkill();

	String& getCustomizationOption(const int i);

	int getCustomizationDefaultValue(const int i);

	int getCustomizationOptionCount();

	String& getAssemblySkill();

	int getExpPoints();

	int getExpCounter();

	float getExpFailure();

	Player* getCrafter();

	int getManufacturingLimit();

	DraftSchematicValues* getCraftingValues();

	bool isFinished();

	bool resourcesWereRemoved();

	void resetCraftingValues();

protected:
	DraftSchematic(DummyConstructorParameter* param);

	virtual ~DraftSchematic();

	String _return_getAssemblySkill;
	String _return_getBlueFrogAttributes;
	String _return_getCustomizationOption;
	String _return_getCustomizationSkill;
	String _return_getExperimentingSkill;
	String _return_getGroupName;
	String _return_getTanoAttributes;
	String _return_getTanoStfName;
	String _return_getXpType;

	friend class DraftSchematicHelper;
};

class DraftSchematicImplementation;

class DraftSchematicAdapter : public SceneObjectAdapter {
public:
	DraftSchematicAdapter(DraftSchematicImplementation* impl);

	Packet* invokeMethod(sys::uint32 methid, DistributedMethod* method);

	DraftSchematic* dsClone(DraftSchematic* draftSchematic);

	void destroy(Player* player);

	void sendTo(Player* player);

	void addExperimentalProperty(unsigned int groupNumber, const String& experimentalProperty, unsigned int weight, String& title, String& subtitle, float min, float max, int precision);

	void sendExperimentalPropertiesToPlayer(Player* player);

	void increaseComplexity();

	void decreaseComplexity();

	void increaseExpCounter();

	void sendIngredientsToPlayer(Player* player);

	void helperSendIngredientsToPlayer(ObjectControllerMessage* objMsg);

	void addIngredient(const String& ingredientTemplateName, const String& ingredientTitleName, const int optional, const String& resourceType, unsigned int resourceQuantity, unsigned int combineType, unsigned int contribution);

	void setTanoAttributes(String& attributes);

	void setBlueFrogAttributes(String& attributes);

	void setBlueFrogEnabled(bool enabled);

	void setXpType(String& type);

	void setXp(int x);

	void setExpCounter(int value);

	void setExpPoints(int points);

	void setExpFailure(float rate);

	void setExperimentingSkill(const String& exp);

	void setCustomizationSkill(const String& cust);

	void addCustomizationOption(const String& cust, const int value);

	void setAssemblySkill(const String& ass);

	void setResourcesWereRemoved();

	void setFinished();

	void setCrafter(Player* crafter);

	void setManufacturingLimit(int value);

	String& getTanoStfName();

	int getExpPropGroupListSize();

	DraftSchematicExpPropGroup* getExpPropGroup(int index);

	DraftSchematicExpPropGroup* cloneExpPropGroup(int index);

	unsigned int getSchematicID();

	DraftSchematicIngredient* getIngredient(int index);

	DraftSchematicIngredient* cloneIngredient(int index);

	int getIngredientListSize();

	int getRequiredIngredientCount();

	String& getGroupName();

	unsigned int getComplexity();

	unsigned int getSchematicSize();

	String& getTanoAttributes();

	String& getBlueFrogAttributes();

	bool getBlueFrogEnabled();

	int getCraftingToolTab();

	String& getXpType();

	int getXp();

	String& getExperimentingSkill();

	String& getCustomizationSkill();

	String& getCustomizationOption(const int i);

	int getCustomizationDefaultValue(const int i);

	int getCustomizationOptionCount();

	String& getAssemblySkill();

	int getExpPoints();

	int getExpCounter();

	float getExpFailure();

	Player* getCrafter();

	int getManufacturingLimit();

	DraftSchematicValues* getCraftingValues();

	bool isFinished();

	bool resourcesWereRemoved();

	void resetCraftingValues();

protected:
	String _param1_addExperimentalProperty__int_String_int_String_String_float_float_int_;
	String _param3_addExperimentalProperty__int_String_int_String_String_float_float_int_;
	String _param4_addExperimentalProperty__int_String_int_String_String_float_float_int_;
	String _param0_addIngredient__String_String_int_String_int_int_int_;
	String _param1_addIngredient__String_String_int_String_int_int_int_;
	String _param3_addIngredient__String_String_int_String_int_int_int_;
	String _param0_setTanoAttributes__String_;
	String _param0_setBlueFrogAttributes__String_;
	String _param0_setXpType__String_;
	String _param0_setExperimentingSkill__String_;
	String _param0_setCustomizationSkill__String_;
	String _param0_addCustomizationOption__String_int_;
	String _param0_setAssemblySkill__String_;
};

class DraftSchematicHelper : public DistributedObjectClassHelper, public Singleton<DraftSchematicHelper> {
	static DraftSchematicHelper* staticInitializer;

public:
	DraftSchematicHelper();

	void finalizeHelper();

	DistributedObject* instantiateObject();

	DistributedObjectAdapter* createAdapter(DistributedObjectStub* obj);

	friend class SingletonWrapper<DraftSchematicHelper>;
};

#include "../scene/SceneObjectImplementation.h"

class DraftSchematicServant : public SceneObjectImplementation {
public:
	DraftSchematic* _this;

public:
	DraftSchematicServant();
	virtual ~DraftSchematicServant();

	void _setStub(DistributedObjectStub* stub);
	DistributedObjectStub* _getStub();

};

#endif /*DRAFTSCHEMATIC_H_*/
