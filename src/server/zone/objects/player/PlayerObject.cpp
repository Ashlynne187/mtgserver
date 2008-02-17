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

/*
 *	server/zone/objects/player/PlayerObject.cpp generated by Engine3 IDL compiler 0.51
 */

#include "../scene/SceneObject.h"

#include "Player.h"

#include "../../Zone.h"

#include "../waypoint/WaypointObject.h"

#include "PlayerObject.h"

#include "PlayerObjectImplementation.h"

/*
 *	PlayerObjectStub
 */

PlayerObject::PlayerObject() : SceneObject(NULL) {
}

PlayerObject::PlayerObject(ORBObjectServant* obj) : SceneObject(obj) {
}

PlayerObject::PlayerObject(PlayerObject& ref) : SceneObject(ref) {
}

PlayerObject::~PlayerObject() {
}

PlayerObject* PlayerObject::clone() {
	return new PlayerObject(*this);
}


void PlayerObject::sendToOwner() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 6);

		invocation.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->sendToOwner();
}

void PlayerObject::sendTo(Player* player, bool doClose) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 7);
		invocation.addObjectParameter(player);
		invocation.addBooleanParameter(doClose);

		invocation.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->sendTo(player, doClose);
}

void PlayerObject::addExperience(const string& xpType, int xp, bool updateClient) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 8);
		invocation.addAsciiParameter(xpType);
		invocation.addSignedIntParameter(xp);
		invocation.addBooleanParameter(updateClient);

		invocation.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->addExperience(xpType, xp, updateClient);
}

void PlayerObject::removeExperience(const string& xpType, int xp, bool updateClient) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 9);
		invocation.addAsciiParameter(xpType);
		invocation.addSignedIntParameter(xp);
		invocation.addBooleanParameter(updateClient);

		invocation.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->removeExperience(xpType, xp, updateClient);
}

bool PlayerObject::setCharacterBit(unsigned int bit, bool updateClient) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 10);
		invocation.addUnsignedIntParameter(bit);
		invocation.addBooleanParameter(updateClient);

		return invocation.executeWithBooleanReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->setCharacterBit(bit, updateClient);
}

bool PlayerObject::clearCharacterBit(unsigned int bit, bool updateClient) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 11);
		invocation.addUnsignedIntParameter(bit);
		invocation.addBooleanParameter(updateClient);

		return invocation.executeWithBooleanReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->clearCharacterBit(bit, updateClient);
}

void PlayerObject::setForcePower(unsigned int fp, bool updateClient) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 12);
		invocation.addUnsignedIntParameter(fp);
		invocation.addBooleanParameter(updateClient);

		invocation.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->setForcePower(fp, updateClient);
}

void PlayerObject::setForcePowerMax(int fp) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 13);
		invocation.addSignedIntParameter(fp);

		invocation.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->setForcePowerMax(fp);
}

void PlayerObject::setForceRegen(int fp) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 14);
		invocation.addSignedIntParameter(fp);

		invocation.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->setForceRegen(fp);
}

unsigned int PlayerObject::getForcePower() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 15);

		return invocation.executeWithUnsignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getForcePower();
}

unsigned int PlayerObject::getForcePowerMax() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 16);

		return invocation.executeWithUnsignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getForcePowerMax();
}

unsigned int PlayerObject::getForceRegen() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 17);

		return invocation.executeWithUnsignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getForceRegen();
}

bool PlayerObject::isJedi() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 18);

		return invocation.executeWithBooleanReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->isJedi();
}

bool PlayerObject::isOnFullForce() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 19);

		return invocation.executeWithBooleanReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->isOnFullForce();
}

unsigned int PlayerObject::getCharacterBitmask() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 20);

		return invocation.executeWithUnsignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getCharacterBitmask();
}

int PlayerObject::getWaypointListSize() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 21);

		return invocation.executeWithSignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getWaypointListSize();
}

unsigned int PlayerObject::getJediState() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 22);

		return invocation.executeWithUnsignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getJediState();
}

WaypointObject* PlayerObject::getWaypoint(unsigned long long id) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 23);
		invocation.addUnsignedLongParameter(id);

		return (WaypointObject*) invocation.executeWithObjectReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getWaypoint(id);
}

void PlayerObject::addWaypoint(WaypointObject* wp, bool updateClient) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 24);
		invocation.addObjectParameter(wp);
		invocation.addBooleanParameter(updateClient);

		invocation.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->addWaypoint(wp, updateClient);
}

bool PlayerObject::removeWaypoint(WaypointObject* wp, bool updateClient) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 25);
		invocation.addObjectParameter(wp);
		invocation.addBooleanParameter(updateClient);

		return invocation.executeWithBooleanReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->removeWaypoint(wp, updateClient);
}

void PlayerObject::updateWaypoint(WaypointObject* wp) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 26);
		invocation.addObjectParameter(wp);

		invocation.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->updateWaypoint(wp);
}

Player* PlayerObject::getPlayer() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 27);

		return (Player*) invocation.executeWithObjectReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getPlayer();
}

void PlayerObject::setCurrentTitle(string& nTitle, bool updateClient) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 28);
		invocation.addAsciiParameter(nTitle);
		invocation.addBooleanParameter(updateClient);

		invocation.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->setCurrentTitle(nTitle, updateClient);
}

void PlayerObject::setTitle(string& temptitle) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 29);
		invocation.addAsciiParameter(temptitle);

		invocation.executeWithVoidReturn();
	} else
		((PlayerObjectImplementation*) _impl)->setTitle(temptitle);
}

string& PlayerObject::getCurrentTitle() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 30);

		invocation.executeWithAsciiReturn(_return_getCurrentTitle);
		return _return_getCurrentTitle;
	} else
		return ((PlayerObjectImplementation*) _impl)->getCurrentTitle();
}

unsigned int PlayerObject::getExperienceListCount() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 31);

		return invocation.executeWithUnsignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getExperienceListCount();
}

unsigned int PlayerObject::getNewExperienceListCount(int cnt) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 32);
		invocation.addSignedIntParameter(cnt);

		return invocation.executeWithUnsignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getNewExperienceListCount(cnt);
}

unsigned int PlayerObject::getWaypointListCount() {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 33);

		return invocation.executeWithUnsignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getWaypointListCount();
}

unsigned int PlayerObject::getNewWaypointListCount(int cnt) {
	 if (!deployed)
		throw ObjectNotDeployedException(this);

	if (_impl == NULL) {
		ORBMethodInvocation invocation(this, 34);
		invocation.addSignedIntParameter(cnt);

		return invocation.executeWithUnsignedIntReturn();
	} else
		return ((PlayerObjectImplementation*) _impl)->getNewWaypointListCount(cnt);
}

/*
 *	PlayerObjectAdapter
 */

PlayerObjectAdapter::PlayerObjectAdapter(PlayerObjectImplementation* obj) : SceneObjectAdapter(obj) {
}

Packet* PlayerObjectAdapter::invokeMethod(uint32 methid, ORBMethodInvocation* inv) {
	Packet* resp = new MethodReturnMessage(0);

	switch (methid) {
	case 6:
		sendToOwner();
		break;
	case 7:
		sendTo((Player*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 8:
		addExperience(inv->getAsciiParameter(_param0_addExperience__string_int_bool_), inv->getSignedIntParameter(), inv->getBooleanParameter());
		break;
	case 9:
		removeExperience(inv->getAsciiParameter(_param0_removeExperience__string_int_bool_), inv->getSignedIntParameter(), inv->getBooleanParameter());
		break;
	case 10:
		resp->insertBoolean(setCharacterBit(inv->getUnsignedIntParameter(), inv->getBooleanParameter()));
		break;
	case 11:
		resp->insertBoolean(clearCharacterBit(inv->getUnsignedIntParameter(), inv->getBooleanParameter()));
		break;
	case 12:
		setForcePower(inv->getUnsignedIntParameter(), inv->getBooleanParameter());
		break;
	case 13:
		setForcePowerMax(inv->getSignedIntParameter());
		break;
	case 14:
		setForceRegen(inv->getSignedIntParameter());
		break;
	case 15:
		resp->insertInt(getForcePower());
		break;
	case 16:
		resp->insertInt(getForcePowerMax());
		break;
	case 17:
		resp->insertInt(getForceRegen());
		break;
	case 18:
		resp->insertBoolean(isJedi());
		break;
	case 19:
		resp->insertBoolean(isOnFullForce());
		break;
	case 20:
		resp->insertInt(getCharacterBitmask());
		break;
	case 21:
		resp->insertSignedInt(getWaypointListSize());
		break;
	case 22:
		resp->insertInt(getJediState());
		break;
	case 23:
		resp->insertLong(getWaypoint(inv->getUnsignedLongParameter())->_getORBObjectID());
		break;
	case 24:
		addWaypoint((WaypointObject*) inv->getObjectParameter(), inv->getBooleanParameter());
		break;
	case 25:
		resp->insertBoolean(removeWaypoint((WaypointObject*) inv->getObjectParameter(), inv->getBooleanParameter()));
		break;
	case 26:
		updateWaypoint((WaypointObject*) inv->getObjectParameter());
		break;
	case 27:
		resp->insertLong(getPlayer()->_getORBObjectID());
		break;
	case 28:
		setCurrentTitle(inv->getAsciiParameter(_param0_setCurrentTitle__string_bool_), inv->getBooleanParameter());
		break;
	case 29:
		setTitle(inv->getAsciiParameter(_param0_setTitle__string_));
		break;
	case 30:
		resp->insertAscii(getCurrentTitle());
		break;
	case 31:
		resp->insertInt(getExperienceListCount());
		break;
	case 32:
		resp->insertInt(getNewExperienceListCount(inv->getSignedIntParameter()));
		break;
	case 33:
		resp->insertInt(getWaypointListCount());
		break;
	case 34:
		resp->insertInt(getNewWaypointListCount(inv->getSignedIntParameter()));
		break;
	default:
		return NULL;
	}

	return resp;
}

void PlayerObjectAdapter::sendToOwner() {
	return ((PlayerObjectImplementation*) impl)->sendToOwner();
}

void PlayerObjectAdapter::sendTo(Player* player, bool doClose) {
	return ((PlayerObjectImplementation*) impl)->sendTo(player, doClose);
}

void PlayerObjectAdapter::addExperience(const string& xpType, int xp, bool updateClient) {
	return ((PlayerObjectImplementation*) impl)->addExperience(xpType, xp, updateClient);
}

void PlayerObjectAdapter::removeExperience(const string& xpType, int xp, bool updateClient) {
	return ((PlayerObjectImplementation*) impl)->removeExperience(xpType, xp, updateClient);
}

bool PlayerObjectAdapter::setCharacterBit(unsigned int bit, bool updateClient) {
	return ((PlayerObjectImplementation*) impl)->setCharacterBit(bit, updateClient);
}

bool PlayerObjectAdapter::clearCharacterBit(unsigned int bit, bool updateClient) {
	return ((PlayerObjectImplementation*) impl)->clearCharacterBit(bit, updateClient);
}

void PlayerObjectAdapter::setForcePower(unsigned int fp, bool updateClient) {
	return ((PlayerObjectImplementation*) impl)->setForcePower(fp, updateClient);
}

void PlayerObjectAdapter::setForcePowerMax(int fp) {
	return ((PlayerObjectImplementation*) impl)->setForcePowerMax(fp);
}

void PlayerObjectAdapter::setForceRegen(int fp) {
	return ((PlayerObjectImplementation*) impl)->setForceRegen(fp);
}

unsigned int PlayerObjectAdapter::getForcePower() {
	return ((PlayerObjectImplementation*) impl)->getForcePower();
}

unsigned int PlayerObjectAdapter::getForcePowerMax() {
	return ((PlayerObjectImplementation*) impl)->getForcePowerMax();
}

unsigned int PlayerObjectAdapter::getForceRegen() {
	return ((PlayerObjectImplementation*) impl)->getForceRegen();
}

bool PlayerObjectAdapter::isJedi() {
	return ((PlayerObjectImplementation*) impl)->isJedi();
}

bool PlayerObjectAdapter::isOnFullForce() {
	return ((PlayerObjectImplementation*) impl)->isOnFullForce();
}

unsigned int PlayerObjectAdapter::getCharacterBitmask() {
	return ((PlayerObjectImplementation*) impl)->getCharacterBitmask();
}

int PlayerObjectAdapter::getWaypointListSize() {
	return ((PlayerObjectImplementation*) impl)->getWaypointListSize();
}

unsigned int PlayerObjectAdapter::getJediState() {
	return ((PlayerObjectImplementation*) impl)->getJediState();
}

WaypointObject* PlayerObjectAdapter::getWaypoint(unsigned long long id) {
	return ((PlayerObjectImplementation*) impl)->getWaypoint(id);
}

void PlayerObjectAdapter::addWaypoint(WaypointObject* wp, bool updateClient) {
	return ((PlayerObjectImplementation*) impl)->addWaypoint(wp, updateClient);
}

bool PlayerObjectAdapter::removeWaypoint(WaypointObject* wp, bool updateClient) {
	return ((PlayerObjectImplementation*) impl)->removeWaypoint(wp, updateClient);
}

void PlayerObjectAdapter::updateWaypoint(WaypointObject* wp) {
	return ((PlayerObjectImplementation*) impl)->updateWaypoint(wp);
}

Player* PlayerObjectAdapter::getPlayer() {
	return ((PlayerObjectImplementation*) impl)->getPlayer();
}

void PlayerObjectAdapter::setCurrentTitle(string& nTitle, bool updateClient) {
	return ((PlayerObjectImplementation*) impl)->setCurrentTitle(nTitle, updateClient);
}

void PlayerObjectAdapter::setTitle(string& temptitle) {
	return ((PlayerObjectImplementation*) impl)->setTitle(temptitle);
}

string& PlayerObjectAdapter::getCurrentTitle() {
	return ((PlayerObjectImplementation*) impl)->getCurrentTitle();
}

unsigned int PlayerObjectAdapter::getExperienceListCount() {
	return ((PlayerObjectImplementation*) impl)->getExperienceListCount();
}

unsigned int PlayerObjectAdapter::getNewExperienceListCount(int cnt) {
	return ((PlayerObjectImplementation*) impl)->getNewExperienceListCount(cnt);
}

unsigned int PlayerObjectAdapter::getWaypointListCount() {
	return ((PlayerObjectImplementation*) impl)->getWaypointListCount();
}

unsigned int PlayerObjectAdapter::getNewWaypointListCount(int cnt) {
	return ((PlayerObjectImplementation*) impl)->getNewWaypointListCount(cnt);
}

/*
 *	PlayerObjectHelper
 */

PlayerObjectHelper::PlayerObjectHelper() {
	className = "PlayerObject";

	ObjectRequestBroker::instance()->registerClass(className, this);
}

void PlayerObjectHelper::finalizeHelper() {
	PlayerObjectHelper::finalize();
}

ORBObject* PlayerObjectHelper::instantiateObject() {
	return new PlayerObject();
}

ORBObjectAdapter* PlayerObjectHelper::createAdapter(ORBObjectServant* obj) {
	ORBObjectAdapter* adapter = new PlayerObjectAdapter((PlayerObjectImplementation*) obj);

	ORBObjectStub* stub = new PlayerObject(obj);
	stub->_setORBClassName(className);
	stub->_setClassHelper(this);

	adapter->setStub(stub);

	obj->_setStub(stub);

	return adapter;
}

/*
 *	PlayerObjectServant
 */

PlayerObjectServant::PlayerObjectServant() : SceneObjectImplementation() {
	_classHelper = PlayerObjectHelper::instance();
}

PlayerObjectServant::~PlayerObjectServant() {
}

void PlayerObjectServant::_setStub(ORBObjectStub* stub) {
	_this = (PlayerObject*) stub;
	SceneObjectServant::_setStub(stub);
}

ORBObjectStub* PlayerObjectServant::_getStub() {
	return _this;
}

