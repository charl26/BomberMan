//
// Created by Charl THERON on 2017/08/15.
//

#ifndef BOMBERMAN_LOGICMANAGER_HPP
#define BOMBERMAN_LOGICMANAGER_HPP


#include "AbstractEntity.hpp"

class EventManager;

class LogicManager {
	void movePlayer(int direction);
	void moveGhost();
	void moveExplosion();

};


#endif //BOMBERMAN_LOGICMANAGER_HPP
