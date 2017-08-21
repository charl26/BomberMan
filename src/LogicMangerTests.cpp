//
// Created by Charl THERON on 2017/08/18.
//

#include <iostream>
#include "LogicManager.hpp"
#include "EventManager.hpp"

bool testLogicManger() {
	EventManager eventManager;
	LogicManager logicManager;

	const std::vector<AbstractEntity *> &objects = eventManager.getObjects();
	AbstractEntity *testObject = logicManager.retrieveObjectByCoordinates(2, 0);
	if (nullptr != testObject) {
		std::cout << "TEST1 PASSED : COLLIDED WITH A Object" << std::endl;
	} else {
		std::cout << "TEST1 FAILED : PLAYER DIDN'T COLLIDED WITH A Object" << std::endl;
	}
	if (SOLIDBRICK == testObject->getType()) {
		std::cout << "TEST2 PASSED : THE TYPE OF OBJECT THAT THE PLAYER COLLIDED WITH IS A WALL" << std::endl;
	} else {
		std::cout << "TEST2 FAILED : PLAYER DIDN'T COLLIDED WITH A WALL" << std::endl;
	}

	testObject = logicManager.retrieveObjectByCoordinates(2, 1);
	if (nullptr == testObject) {
		std::cout << "TEST3 PASSED : PLAYER DIDN'T COLLIDED WITH A Object" << std::endl;
	} else {
		std::cout << "TEST3 FAILED : COLLIDED WITH A Object" << std::endl;

	}
}