//
// Created by Charl THERON on 2017/08/15.
//

#ifndef BOMBERMAN_LOGICMANAGER_HPP
#define BOMBERMAN_LOGICMANAGER_HPP


#include "AbstractEntity.hpp"
#include "Ghost.hpp"

class EventManager;

class LogicManager {
	int LogicManager::moveGhost(const Ghost &ghost);
	void moveExplosion();

	int smartMonsterMove(const Ghost &ghost);
};


#endif
