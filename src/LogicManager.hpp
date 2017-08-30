//
// Created by Charl THERON on 2017/08/15.
//

#ifndef BOMBERMAN_LOGICMANAGER_HPP
#define BOMBERMAN_LOGICMANAGER_HPP


#include "AbstractEntity.hpp"
#include "Ghost.hpp"
#include "Bomberman.hpp"

class EventManager;

class LogicManager {
public:
	int getGhostDirectionToMove(const Ghost &ghost, const Bomberman &bomberMan);
	AbstractEntity *const & retrieveObjectByCoordinates(signed short int coordX, signed short int coordY);
	void moveExplosion();

};

#endif
