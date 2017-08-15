//
// Created by Charl THERON on 2017/08/15.
//

#include "LogicManager.hpp"
#include "EventManager.hpp"

void LogicManager::moveExplosion() {

}

void checkCollision (signed short int coordX, signed short int coordY) {
	for (int i = 0; i < objectList.size(); i++) {
		if ((objectList[i].getXPos() == coordX) && (objectList[i].getYPos() == coordY)) {
			performCollision(objectList[i]);
		}
	}
}

/**
 * @brief Moves the player depends on the direction of the keyhook call back
 * @param direction of player  1 -- up 2 -- down 3 -- left default -- right
 */

void LogicManager::movePlayer(int direction) {

	checkCollision(eventmanager->bomberman->getXPos(), eventmanager->bomberman->getYPos()); //Passable check for bug

	switch (direction) {
		case 1: {
			checkCollision(eventmanager->bomberman->getXPos(), eventmanager->bomberman->getYPos() - 1); //Passable check for bug
			// EventManager->MovePlayer(UP);
			break;
		}
		case 2: {
			checkCollision(eventmanager->bomberman->getXPos(), eventmanager->bomberman->getYPos() +  1); //Passable check for bug
			// EventManager->MovePlayer(DOWN);
			break;
		}
		case 3: {
			checkCollision(eventmanager->bomberman->getXPos() - 1, eventmanager->bomberman->getYPos()); //Passable check for bug
			// EventManager->MovePlayer(LEFT);
			break;
		}
		default: {
			checkCollision(eventmanager->bomberman->getXPos() + 1, eventmanager->bomberman->getYPos()); //Passable check for bug
			// EventManager->MovePlayer(RIGHT);
			break;
		}
	}
}
