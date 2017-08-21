//
// Created by Charl THERON on 2017/08/15.
//

#include <cstdlib>
#include "LogicManager.hpp"
#include "EventManager.hpp"

void LogicManager::moveExplosion() {

}

/**
 * @brief coordinates of the objects current position of ether the bomberman or the ghost
 * @param coordX the X coordinates
 * @param coordY the Y coordinates
 * @return if there is a collision it will return the - Object that it has collied with else it will return - NULL
 */
AbstractEntity checkCollision(signed short int coordX, signed short int coordY) {
	for (int i = 0; i < objectList.size(); i++) {
		if ((objectList[i].getXPos() == coordX) && (objectList[i].getYPos() == coordY)) {
			return (objectList[i]);
		}
	}
	return NULL;
}

/**
 * @param ghost takes in a ghost to workout which is the best move for it based on it position
 * @return a int base direction for the ghost to move (0 = NoMOVE) ( 1 = UP ) ( 2 = DOWN ) ( 3 = LEFT ) ( 4 = RIGHT )
 */

int LogicManager::moveGhost(const Ghost &ghost) {
	int direction = 0;
	if (ghost.getSmartness() == 2) {
		direction = smartMonsterMove(ghost);
	}
	return direction;
}

int LogicManager::smartMonsterMove(const Ghost &ghost) {
	int direction = 0;
	return direction;
}
