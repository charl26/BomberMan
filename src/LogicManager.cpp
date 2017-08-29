//
// Created by Charl THERON on 2017/08/15.
//

#include <cstdlib>
#include "LogicManager.hpp"
#include "EventManager.hpp"

void LogicManager::moveExplosion() {

}

/**
 * @brief Retrieve a object by the coordinates
 * @param coordX the X coordinates
 * @param coordY the Y coordinates
 * @return if there is a collision it will return the - Object that it has collied with else it will return - NULL
 */
AbstractEntity *const &LogicManager::retrieveObjectByCoordinates(signed short int coordX, signed short int coordY) {
	EventManager eventManager;
	const std::vector<AbstractEntity *> &objects = eventManager.getObjects();

	for (auto object : objects) {
		if (object->getXPos() == coordX && object->getYPos() == coordY) {
			return object;
		}
	}
	return nullptr;
}

/**
 * @param ghost takes in a ghost to workout which is the best move for it based on it position
 * @param bomberMan to check where the bomberman is to move closer to the player
 * @return a int base direction for the ghost to move (0 = NoMOVE) ( 1 = UP ) ( 2 = DOWN ) ( 3 = LEFT ) ( 4 = RIGHT )
 */

int LogicManager::getGhostDirectionToMove(const Ghost &ghost, const Bomberman &bomberMan) {
	if (ghost.getXPos() > bomberMan.getXPos()) {
		if (retrieveObjectByCoordinates(static_cast<short>(ghost.getXPos() - 1), ghost.getYPos()) == nullptr) {
			return (LEFT);
		}
	} else if (ghost.getXPos() < bomberMan.getXPos()) {
		if (retrieveObjectByCoordinates(static_cast<short>(ghost.getXPos() + 1), ghost.getYPos()) == nullptr) {
			return (RIGHT);
		}
	} else {
		if (ghost.getYPos() > bomberMan.getYPos()) {
			if (retrieveObjectByCoordinates((ghost.getXPos()), static_cast<short>(ghost.getYPos() + 1)) == nullptr) {
				return (UP);
			}
		} else if (ghost.getYPos() < bomberMan.getYPos()) {
			if (retrieveObjectByCoordinates((ghost.getXPos()), static_cast<short>(ghost.getYPos() + 1)) == nullptr) {
				return (DOWN);
			}
		}
	}
	return (0);
}

