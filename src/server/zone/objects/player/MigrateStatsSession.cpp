/*
 *	server/zone/objects/player/MigrateStatsSession.cpp generated by engine3 IDL compiler 0.60
 */

#include "MigrateStatsSession.h"

#include "server/zone/objects/creature/CreatureObject.h"

#include "server/zone/objects/tangible/TangibleObject.h"

/*
 *	MigrateStatsSessionStub
 */

MigrateStatsSession::MigrateStatsSession(CreatureObject* parent) : Facade(DummyConstructorParameter::instance()) {
	MigrateStatsSessionImplementation* _implementation = new MigrateStatsSessionImplementation(parent);
	_impl = _implementation;
	_impl->_setStub(this);
}

MigrateStatsSession::MigrateStatsSession(DummyConstructorParameter* param) : Facade(param) {
}

MigrateStatsSession::~MigrateStatsSession() {
}


int MigrateStatsSession::initializeSession() {
	MigrateStatsSessionImplementation* _implementation = (MigrateStatsSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->initializeSession();
}

int MigrateStatsSession::cancelSession() {
	MigrateStatsSessionImplementation* _implementation = (MigrateStatsSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->cancelSession();
}

int MigrateStatsSession::clearSession() {
	MigrateStatsSessionImplementation* _implementation = (MigrateStatsSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->clearSession();
}

void MigrateStatsSession::setAttributeToModify(int attribute, int value) {
	MigrateStatsSessionImplementation* _implementation = (MigrateStatsSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);
		method.addSignedIntParameter(attribute);
		method.addSignedIntParameter(value);

		method.executeWithVoidReturn();
	} else
		_implementation->setAttributeToModify(attribute, value);
}

int MigrateStatsSession::getAttribtueToModify(int attribute) {
	MigrateStatsSessionImplementation* _implementation = (MigrateStatsSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 10);
		method.addSignedIntParameter(attribute);

		return method.executeWithSignedIntReturn();
	} else
		return _implementation->getAttribtueToModify(attribute);
}

void MigrateStatsSession::migrateStats() {
	MigrateStatsSessionImplementation* _implementation = (MigrateStatsSessionImplementation*) _getImplementation();
	if (_implementation == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 11);

		method.executeWithVoidReturn();
	} else
		_implementation->migrateStats();
}

DistributedObjectServant* MigrateStatsSession::_getImplementation() {
	return _impl;}

void MigrateStatsSession::_setImplementation(DistributedObjectServant* servant) {
	_impl = servant;}

/*
 *	MigrateStatsSessionImplementation
 */

MigrateStatsSessionImplementation::MigrateStatsSessionImplementation(DummyConstructorParameter* param) : FacadeImplementation(param) {
	_initializeImplementation();
}


MigrateStatsSessionImplementation::~MigrateStatsSessionImplementation() {
}


void MigrateStatsSessionImplementation::finalize() {
}

void MigrateStatsSessionImplementation::_initializeImplementation() {
	_setClassHelper(MigrateStatsSessionHelper::instance());

	_serializationHelperMethod();
}

void MigrateStatsSessionImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (MigrateStatsSession*) stub;
	FacadeImplementation::_setStub(stub);
}

DistributedObjectStub* MigrateStatsSessionImplementation::_getStub() {
	return _this;
}

MigrateStatsSessionImplementation::operator const MigrateStatsSession*() {
	return _this;
}

void MigrateStatsSessionImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void MigrateStatsSessionImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void MigrateStatsSessionImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void MigrateStatsSessionImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void MigrateStatsSessionImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void MigrateStatsSessionImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void MigrateStatsSessionImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void MigrateStatsSessionImplementation::_serializationHelperMethod() {
	FacadeImplementation::_serializationHelperMethod();

	_setClassName("MigrateStatsSession");

	addSerializableVariable("creature", &creature);
	addSerializableVariable("attributesToModify", &attributesToModify);
}

MigrateStatsSessionImplementation::MigrateStatsSessionImplementation(CreatureObject* parent) {
	_initializeImplementation();
	// server/zone/objects/player/MigrateStatsSession.idl(66):  		creature = parent;
	creature = parent;
	// server/zone/objects/player/MigrateStatsSession.idl(68):  		Logger.setLoggingName("MigrateStatsSession");
	Logger::setLoggingName("MigrateStatsSession");
	// server/zone/objects/player/MigrateStatsSession.idl(69):  		Logger.setLogging(false);
	Logger::setLogging(false);
	// server/zone/objects/player/MigrateStatsSession.idl(71):  
	for (	// server/zone/objects/player/MigrateStatsSession.idl(71):  		for (int i = 0;
	int i = 0;
	i < 9;
i = i + 1) {
	// server/zone/objects/player/MigrateStatsSession.idl(72):  			attributesToModify.add(0);
	(&attributesToModify)->add(0);
}
}

int MigrateStatsSessionImplementation::initializeSession() {
	// server/zone/objects/player/MigrateStatsSession.idl(77):  		return 0;
	return 0;
}

int MigrateStatsSessionImplementation::cancelSession() {
	// server/zone/objects/player/MigrateStatsSession.idl(81):  
	if (creature == NULL){
	// server/zone/objects/player/MigrateStatsSession.idl(82):  			return 0;
	return 0;
}

	else {
	// server/zone/objects/player/MigrateStatsSession.idl(84):  			creature.dropActiveSession(SessionFacadeType.MIGRATESTATS);
	creature->dropActiveSession(SessionFacadeType::MIGRATESTATS);
}
	// server/zone/objects/player/MigrateStatsSession.idl(87):  		return 0;
	return 0;
}

int MigrateStatsSessionImplementation::clearSession() {
	// server/zone/objects/player/MigrateStatsSession.idl(91):  		attributesToModify.removeAll();
	(&attributesToModify)->removeAll();
	// server/zone/objects/player/MigrateStatsSession.idl(93):  		return 0;
	return 0;
}

void MigrateStatsSessionImplementation::setAttributeToModify(int attribute, int value) {
	// server/zone/objects/player/MigrateStatsSession.idl(97):  		attributesToModify.set(attribute, value);
	(&attributesToModify)->set(attribute, value);
}

int MigrateStatsSessionImplementation::getAttribtueToModify(int attribute) {
	// server/zone/objects/player/MigrateStatsSession.idl(101):  		return attributesToModify.get(attribute);
	return (&attributesToModify)->get(attribute);
}

void MigrateStatsSessionImplementation::migrateStats() {
	// server/zone/objects/player/MigrateStatsSession.idl(105):  
	for (	// server/zone/objects/player/MigrateStatsSession.idl(105):  		for (int i = 0;
	int i = 0;
	i < 9;
i = i + 1) {
	// server/zone/objects/player/MigrateStatsSession.idl(106):  			int newValue = attributesToModify.get(i);
	int newValue = (&attributesToModify)->get(i);
	// server/zone/objects/player/MigrateStatsSession.idl(108):  			int originalAmount = creature.getBaseHAM(i);
	int originalAmount = creature->getBaseHAM(i);
	// server/zone/objects/player/MigrateStatsSession.idl(110):  			creature.setBaseHAM(i, newValue);
	creature->setBaseHAM(i, newValue);
	// server/zone/objects/player/MigrateStatsSession.idl(111):  			creature.setHAM(i, creature.getHAM(i) + (newValue - originalAmount));
	creature->setHAM(i, creature->getHAM(i) + (newValue - originalAmount));
	// server/zone/objects/player/MigrateStatsSession.idl(112):  			creature.setMaxHAM(i, creature.getMaxHAM(i) + (newValue - originalAmount));
	creature->setMaxHAM(i, creature->getMaxHAM(i) + (newValue - originalAmount));
}
	// server/zone/objects/player/MigrateStatsSession.idl(118):  		cancelSession();
	cancelSession();
}

/*
 *	MigrateStatsSessionAdapter
 */

MigrateStatsSessionAdapter::MigrateStatsSessionAdapter(MigrateStatsSessionImplementation* obj) : FacadeAdapter(obj) {
}

Packet* MigrateStatsSessionAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertSignedInt(initializeSession());
		break;
	case 7:
		resp->insertSignedInt(cancelSession());
		break;
	case 8:
		resp->insertSignedInt(clearSession());
		break;
	case 9:
		setAttributeToModify(inv->getSignedIntParameter(), inv->getSignedIntParameter());
		break;
	case 10:
		resp->insertSignedInt(getAttribtueToModify(inv->getSignedIntParameter()));
		break;
	case 11:
		migrateStats();
		break;
	default:
		return NULL;
	}

	return resp;
}

int MigrateStatsSessionAdapter::initializeSession() {
	return ((MigrateStatsSessionImplementation*) impl)->initializeSession();
}

int MigrateStatsSessionAdapter::cancelSession() {
	return ((MigrateStatsSessionImplementation*) impl)->cancelSession();
}

int MigrateStatsSessionAdapter::clearSession() {
	return ((MigrateStatsSessionImplementation*) impl)->clearSession();
}

void MigrateStatsSessionAdapter::setAttributeToModify(int attribute, int value) {
	((MigrateStatsSessionImplementation*) impl)->setAttributeToModify(attribute, value);
}

int MigrateStatsSessionAdapter::getAttribtueToModify(int attribute) {
	return ((MigrateStatsSessionImplementation*) impl)->getAttribtueToModify(attribute);
}

void MigrateStatsSessionAdapter::migrateStats() {
	((MigrateStatsSessionImplementation*) impl)->migrateStats();
}

/*
 *	MigrateStatsSessionHelper
 */

MigrateStatsSessionHelper* MigrateStatsSessionHelper::staticInitializer = MigrateStatsSessionHelper::instance();

MigrateStatsSessionHelper::MigrateStatsSessionHelper() {
	className = "MigrateStatsSession";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void MigrateStatsSessionHelper::finalizeHelper() {
	MigrateStatsSessionHelper::finalize();
}

DistributedObject* MigrateStatsSessionHelper::instantiateObject() {
	return new MigrateStatsSession(DummyConstructorParameter::instance());
}

DistributedObjectServant* MigrateStatsSessionHelper::instantiateServant() {
	return new MigrateStatsSessionImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* MigrateStatsSessionHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new MigrateStatsSessionAdapter((MigrateStatsSessionImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

