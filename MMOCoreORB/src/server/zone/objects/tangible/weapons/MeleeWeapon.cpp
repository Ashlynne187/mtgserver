/*
 *	server/zone/objects/tangible/weapons/MeleeWeapon.cpp generated by engine3 IDL compiler 0.55
 */

#include "MeleeWeapon.h"

#include "MeleeWeaponImplementation.h"

#include "../../creature/CreatureObject.h"

#include "Weapon.h"

/*
 *	MeleeWeaponStub
 */

MeleeWeapon::MeleeWeapon(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, int tp, bool eqp) : Weapon(DummyConstructorParameter::instance()) {
	_impl = new MeleeWeaponImplementation(oid, tempCRC, n, tempn, tp, eqp);
	_impl->_setStub(this);
}

MeleeWeapon::MeleeWeapon(CreatureObject* creature, const String& temp, const UnicodeString& n, const String& tempn, int tp, bool eqp) : Weapon(DummyConstructorParameter::instance()) {
	_impl = new MeleeWeaponImplementation(creature, temp, n, tempn, tp, eqp);
	_impl->_setStub(this);
}

MeleeWeapon::MeleeWeapon(DummyConstructorParameter* param) : Weapon(param) {
}

MeleeWeapon::~MeleeWeapon() {
}

/*
 *	MeleeWeaponAdapter
 */

MeleeWeaponAdapter::MeleeWeaponAdapter(MeleeWeaponImplementation* obj) : WeaponAdapter(obj) {
}

Packet* MeleeWeaponAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	default:
		return NULL;
	}

	return resp;
}

/*
 *	MeleeWeaponHelper
 */

MeleeWeaponHelper* MeleeWeaponHelper::staticInitializer = MeleeWeaponHelper::instance();

MeleeWeaponHelper::MeleeWeaponHelper() {
	className = "MeleeWeapon";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void MeleeWeaponHelper::finalizeHelper() {
	MeleeWeaponHelper::finalize();
}

DistributedObject* MeleeWeaponHelper::instantiateObject() {
	return new MeleeWeapon(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* MeleeWeaponHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new MeleeWeaponAdapter((MeleeWeaponImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	MeleeWeaponServant
 */

MeleeWeaponServant::MeleeWeaponServant(unsigned long long oid, unsigned int tempCRC, const UnicodeString& n, const String& tempn, bool eqp, int tp, int cat) : WeaponImplementation(oid, tempCRC, n, tempn, eqp, tp, cat) {
	_classHelper = MeleeWeaponHelper::instance();
}

MeleeWeaponServant::MeleeWeaponServant(CreatureObject* creature, const String& temp, const UnicodeString& n, const String& tempn, bool eqp, int tp, int cat) : WeaponImplementation(creature, temp, n, tempn, eqp, tp, cat) {
	_classHelper = MeleeWeaponHelper::instance();
}

MeleeWeaponServant::~MeleeWeaponServant() {
}

void MeleeWeaponServant::_setStub(DistributedObjectStub* stub) {
	_this = (MeleeWeapon*) stub;
	WeaponServant::_setStub(stub);
}

DistributedObjectStub* MeleeWeaponServant::_getStub() {
	return _this;
}

