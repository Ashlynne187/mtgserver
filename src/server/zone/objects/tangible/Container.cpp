/*
 *	server/zone/objects/tangible/Container.cpp generated by engine3 IDL compiler 0.60
 */

#include "Container.h"

#include "server/zone/objects/scene/SceneObject.h"

#include "server/zone/Zone.h"

#include "server/zone/templates/SharedObjectTemplate.h"

/*
 *	ContainerStub
 */

Container::Container() : TangibleObject(DummyConstructorParameter::instance()) {
	_impl = new ContainerImplementation();
	_impl->_setStub(this);
}

Container::Container(DummyConstructorParameter* param) : TangibleObject(param) {
}

Container::~Container() {
}


void Container::loadTemplateData(SharedObjectTemplate* templateData) {
	if (_impl == NULL) {
		throw ObjectNotLocalException(this);

	} else
		((ContainerImplementation*) _impl)->loadTemplateData(templateData);
}

void Container::initializeTransientMembers() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 6);

		method.executeWithVoidReturn();
	} else
		((ContainerImplementation*) _impl)->initializeTransientMembers();
}

int Container::canAddObject(SceneObject* object, int containmentType, String& errorDescription) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 7);
		method.addObjectParameter(object);
		method.addSignedIntParameter(containmentType);
		method.addAsciiParameter(errorDescription);

		return method.executeWithSignedIntReturn();
	} else
		return ((ContainerImplementation*) _impl)->canAddObject(object, containmentType, errorDescription);
}

void Container::sendContainerObjectsTo(SceneObject* player) {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 8);
		method.addObjectParameter(player);

		method.executeWithVoidReturn();
	} else
		((ContainerImplementation*) _impl)->sendContainerObjectsTo(player);
}

bool Container::isContainerOject() {
	if (_impl == NULL) {
		if (!deployed)
			throw ObjectNotDeployedException(this);

		DistributedMethod method(this, 9);

		return method.executeWithBooleanReturn();
	} else
		return ((ContainerImplementation*) _impl)->isContainerOject();
}

/*
 *	ContainerImplementation
 */

ContainerImplementation::ContainerImplementation(DummyConstructorParameter* param) : TangibleObjectImplementation(param) {
	_initializeImplementation();
}


ContainerImplementation::~ContainerImplementation() {
}


void ContainerImplementation::finalize() {
}

void ContainerImplementation::_initializeImplementation() {
	_setClassHelper(ContainerHelper::instance());

	_serializationHelperMethod();
}

void ContainerImplementation::_setStub(DistributedObjectStub* stub) {
	_this = (Container*) stub;
	TangibleObjectImplementation::_setStub(stub);
}

DistributedObjectStub* ContainerImplementation::_getStub() {
	return _this;
}

ContainerImplementation::operator const Container*() {
	return _this;
}

void ContainerImplementation::lock(bool doLock) {
	_this->lock(doLock);
}

void ContainerImplementation::lock(ManagedObject* obj) {
	_this->lock(obj);
}

void ContainerImplementation::rlock(bool doLock) {
	_this->rlock(doLock);
}

void ContainerImplementation::wlock(bool doLock) {
	_this->wlock(doLock);
}

void ContainerImplementation::wlock(ManagedObject* obj) {
	_this->wlock(obj);
}

void ContainerImplementation::unlock(bool doLock) {
	_this->unlock(doLock);
}

void ContainerImplementation::runlock(bool doLock) {
	_this->runlock(doLock);
}

void ContainerImplementation::_serializationHelperMethod() {
	TangibleObjectImplementation::_serializationHelperMethod();

	_setClassName("Container");

}

ContainerImplementation::ContainerImplementation() {
	_initializeImplementation();
	// server/zone/objects/tangible/Container.idl(55):  		Logger.setLoggingName("Container");
	Logger::setLoggingName("Container");
}

bool ContainerImplementation::isContainerOject() {
	// server/zone/objects/tangible/Container.idl(77):  		return true;
	return true;
}

/*
 *	ContainerAdapter
 */

ContainerAdapter::ContainerAdapter(ContainerImplementation* obj) : TangibleObjectAdapter(obj) {
}

Packet* ContainerAdapter::invokeMethod(uint32 methid, DistributedMethod* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		initializeTransientMembers();
		break;
	case 7:
		resp->insertSignedInt(canAddObject((SceneObject*) inv->getObjectParameter(), inv->getSignedIntParameter(), inv->getAsciiParameter(_param2_canAddObject__SceneObject_int_String_)));
		break;
	case 8:
		sendContainerObjectsTo((SceneObject*) inv->getObjectParameter());
		break;
	case 9:
		resp->insertBoolean(isContainerOject());
		break;
	default:
		return NULL;
	}

	return resp;
}

void ContainerAdapter::initializeTransientMembers() {
	((ContainerImplementation*) impl)->initializeTransientMembers();
}

int ContainerAdapter::canAddObject(SceneObject* object, int containmentType, String& errorDescription) {
	return ((ContainerImplementation*) impl)->canAddObject(object, containmentType, errorDescription);
}

void ContainerAdapter::sendContainerObjectsTo(SceneObject* player) {
	((ContainerImplementation*) impl)->sendContainerObjectsTo(player);
}

bool ContainerAdapter::isContainerOject() {
	return ((ContainerImplementation*) impl)->isContainerOject();
}

/*
 *	ContainerHelper
 */

ContainerHelper* ContainerHelper::staticInitializer = ContainerHelper::instance();

ContainerHelper::ContainerHelper() {
	className = "Container";

	DistributedObjectBroker::instance()->registerClass(className, this);
}

void ContainerHelper::finalizeHelper() {
	ContainerHelper::finalize();
}

DistributedObject* ContainerHelper::instantiateObject() {
	return new Container(DummyConstructorParameter::instance());
}

DistributedObjectServant* ContainerHelper::instantiateServant() {
	return new ContainerImplementation(DummyConstructorParameter::instance());
}

DistributedObjectAdapter* ContainerHelper::createAdapter(DistributedObjectStub* obj) {
	DistributedObjectAdapter* adapter = new ContainerAdapter((ContainerImplementation*) obj->_getImplementation());

	obj->_setClassName(className);
	obj->_setClassHelper(this);

	adapter->setStub(obj);

	return adapter;
}

