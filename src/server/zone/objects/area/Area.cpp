/*
 *	server/zone/objects/area/Area.cpp generated by engine3 IDL compiler 0.55
 */

#include "Area.h"

#include "AreaImplementation.h"

/*
 *	AreaStub
 */

Area::Area(float x, float y, float radius) : ManagedObject(DummyConstructorParameter::instance()) {
	_impl = new AreaImplementation(x, y, radius);
	_impl->_setStub(this);
}

Area::Area(DummyConstructorParameter* param) : ManagedObject(param) {
}

Area::~Area() {
}

bool Area::containsPoint(float x, float y) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);
		method.addFloatParameter(x);
		method.addFloatParameter(y);

		return method.executeWithBooleanReturn();
	} else
		return ((AreaImplementation*) _impl)->containsPoint(x, y);
}

float Area::getX() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);

		return method.executeWithFloatReturn();
	} else
		return ((AreaImplementation*) _impl)->getX();
}

float Area::getY() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);

		return method.executeWithFloatReturn();
	} else
		return ((AreaImplementation*) _impl)->getY();
}

float Area::getRadius() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithFloatReturn();
	} else
		return ((AreaImplementation*) _impl)->getRadius();
}

/*
 *	AreaAdapter
 */

AreaAdapter::AreaAdapter(AreaImplementation* obj) : ManagedObjectAdapter(obj) {
}

Packet* AreaAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		resp->insertBoolean(containsPoint(inv->getFloatParameter(), inv->getFloatParameter()));
		break;
	case 7:
		resp->insertFloat(getX());
		break;
	case 8:
		resp->insertFloat(getY());
		break;
	case 9:
		resp->insertFloat(getRadius());
		break;
	default:
		return NULL;
	}

	return resp;
}

bool AreaAdapter::containsPoint(float x, float y) {
	return ((AreaImplementation*) impl)->containsPoint(x, y);
}

float AreaAdapter::getX() {
	return ((AreaImplementation*) impl)->getX();
}

float AreaAdapter::getY() {
	return ((AreaImplementation*) impl)->getY();
}

float AreaAdapter::getRadius() {
	return ((AreaImplementation*) impl)->getRadius();
}

/*
 *	AreaHelper
 */

AreaHelper* AreaHelper::staticInitializer = AreaHelper::instance();

AreaHelper::AreaHelper() {
	className = "Area";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void AreaHelper::finalizeHelper() {
	AreaHelper::finalize();
}

DistributedObject* AreaHelper::instantiateObject() {
	return new Area(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* AreaHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new AreaAdapter((AreaImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

/*
 *	AreaServant
 */

AreaServant::AreaServant() : ManagedObjectImplementation() {
	_classHelper = AreaHelper::instance();
}

AreaServant::~AreaServant() {
}

void AreaServant::_setStub(DistributedObjectStub* stub) {
	_this = (Area*) stub;
	ManagedObjectServant::_setStub(stub);
}

DistributedObjectStub* AreaServant::_getStub() {
	return _this;
}

