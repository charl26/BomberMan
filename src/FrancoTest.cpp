//
// Created by Franco on 2017/08/18.
//

#include <iostream>
#include "EventManager.hpp"

/**
 * @brief Iterates through the map and draws every object with ascii characters to provide a visual representation of
 * the 2D array map.
 */

void TestDrawEventManagerConstructorObjects() {
    auto *eventManager = new EventManager();
    int mapRows;
    int mapCol;

    mapRows = sizeof(eventManager->map) / sizeof(eventManager->map[0]);
    mapCol = sizeof(eventManager->map[0]) / sizeof(eventManager->map[0][0]);

    for (int x{}; x < mapRows; x++) {
        for (int y{}; y < mapCol; y++) {
            switch (eventManager->map[x][y]) {
                case EMPTYTILE: {
                    std::cout << "  ";
                    break;
                }
                case PLAYER: {
                    std::cout << "..";
                    break;
                }
                case GHOST: {
                    std::cout << "O-";
                    break;
                }
                case BOMB: {
                    std::cout << "**";
                    break;
                }
                case EXPLOSION: {
                    std::cout << "++";
                    break;
                }
                case BRICK: {
                    std::cout << "BB";
                    break;
                }
                case BRICKWITHPWR: {
                    std::cout << "BP";
                    break;
                }
                case SOLIDBRICK: {
                    std::cout << "[]";
                    break;
                }
                case DOOR: {
                    std::cout << "{}";
                    break;
                }
                case BOMBCOUNTPWR: {
                    std::cout << "*^";
                    break;
                }
                case FLAMESIZEPWR: {
                    std::cout << "+^";
                    break;
                }
                case PLAYERSPEEDPWR: {
                    std::cout << ".^";
                    break;
                }
                default: {
                    break;
                }
            }
        }
        std::cout << std::endl;
    }
    delete (eventManager);
}

/**
 * @brief Tests the objects in the objects list against the map objects by reading the map and
 * iterating through the objects list the same way as when objects were created. Then it tries to match the map
 * object types to the object's type. If they do not match, the test fails.
 */

void TestEventManagerConstructor() {
    auto *eventManager = new EventManager();
    int mapRows;
    int mapCol;
    int i = -1;
    bool objectPass = true;

    mapRows = sizeof(eventManager->map) / sizeof(eventManager->map[0]);
    mapCol = sizeof(eventManager->map[0]) / sizeof(eventManager->map[0][0]);

    for (int x{}; x < mapRows; x++) {
        for (int y{}; y < mapCol; y++) {
            switch (eventManager->map[x][y]) {
                case EMPTYTILE: {
                    break;
                }
                case PLAYER: {
                    break;
                }
                case GHOST: {
                    i++;
                    if (eventManager->getObjects()[i]->getType() != GHOST) {
                        objectPass = false;
                    }
                    break;
                }
                case BRICK: {
                    i++;
                    if (eventManager->getObjects()[i]->getType() != BRICK) {
                        objectPass = false;
                    }
                    break;
                }
                case BRICKWITHPWR: {
                    i++;
                    if (eventManager->getObjects()[i]->getType() != BRICKWITHPWR) {
                        objectPass = false;
                    }
                    break;
                }
                case SOLIDBRICK: {
                    i++;
                    if (eventManager->getObjects()[i]->getType() != SOLIDBRICK) {
                        objectPass = false;
                    }
                    break;
                }
                case DOOR: {
                    i++;
                    if (eventManager->getObjects()[i]->getType() != DOOR) {
                        objectPass = false;
                    }
                    break;
                }
                case BOMBCOUNTPWR: {
                    i++;
                    if (eventManager->getObjects()[i]->getType() != BOMBCOUNTPWR) {
                        objectPass = false;
                    }
                    break;
                }
                case FLAMESIZEPWR: {
                    i++;
                    if (eventManager->getObjects()[i]->getType() != FLAMESIZEPWR) {
                        objectPass = false;
                    }
                    break;
                }
                case PLAYERSPEEDPWR: {
                    i++;
                    if (eventManager->getObjects()[i]->getType() != PLAYERSPEEDPWR) {
                        objectPass = false;
                    }
                    break;
                }
                default: {
                    break;
                }
            }
        }
    }

    std::cout << "Object Generation Test: " << objectPass << std::endl;
    delete (eventManager);
}

/**
 * @brief Tests the coordinates of every object in the objects list against the map coordinates by reading the map and
 * iterating through the objects list the same way as when objects were created. Then it tries to match the map
 * x and y to the object's x and y. If they do not match, the test fails.
 */

void TestEventManagerConstructorCoordinates() {
    auto *eventManager = new EventManager();
    int mapRows;
    int mapCol;
    int i = -1;
    bool coordPass = true;

    mapRows = sizeof(eventManager->map) / sizeof(eventManager->map[0]);
    mapCol = sizeof(eventManager->map[0]) / sizeof(eventManager->map[0][0]);

    for (int x{}; x < mapRows; x++) {
        for (int y{}; y < mapCol; y++) {
            switch (eventManager->map[x][y]) {
                case EMPTYTILE: {
                    break;
                }
                case PLAYER: {
                    if (eventManager->getBomberman()->getXPos() != x && eventManager->getBomberman()->getYPos() != y) {
                        coordPass = false;
                    }
                    break;
                }
                case GHOST: {
                    i++;
                    if (eventManager->getObjects()[i]->getXPos() != x &&
                        eventManager->getObjects()[i]->getYPos() != y) {
                        coordPass = false;
                    }
                    break;
                }
                case BRICK: {
                    i++;
                    if (eventManager->getObjects()[i]->getXPos() != x &&
                        eventManager->getObjects()[i]->getYPos() != y) {
                        coordPass = false;
                    }
                    break;
                }
                case BRICKWITHPWR: {
                    i++;
                    if (eventManager->getObjects()[i]->getXPos() != x &&
                        eventManager->getObjects()[i]->getYPos() != y) {
                        coordPass = false;
                    }
                    break;
                }
                case SOLIDBRICK: {
                    i++;
                    if (eventManager->getObjects()[i]->getXPos() != x &&
                        eventManager->getObjects()[i]->getYPos() != y) {
                        coordPass = false;
                    }
                    break;
                }
                case DOOR: {
                    i++;
                    if (eventManager->getObjects()[i]->getXPos() != x &&
                        eventManager->getObjects()[i]->getYPos() != y) {
                        coordPass = false;
                    }
                    break;
                }
                case BOMBCOUNTPWR: {
                    i++;
                    if (eventManager->getObjects()[i]->getXPos() != x &&
                        eventManager->getObjects()[i]->getYPos() != y) {
                        coordPass = false;
                    }
                    break;
                }
                case FLAMESIZEPWR: {
                    i++;
                    if (eventManager->getObjects()[i]->getXPos() != x &&
                        eventManager->getObjects()[i]->getYPos() != y) {
                        coordPass = false;
                    }
                    break;
                }
                case PLAYERSPEEDPWR: {
                    i++;
                    if (eventManager->getObjects()[i]->getXPos() != x &&
                        eventManager->getObjects()[i]->getYPos() != y) {
                        coordPass = false;
                    }
                    break;
                }
                default: {
                    break;
                }
            }
        }
    }

    std::cout << "Object coordinate Test: " << coordPass << std::endl;
    delete (eventManager);
}

/**
 * @brief Tests collision between all objects, making sure that the correct actions are taken when a collision occurs.
 */

void TestEventManagerPerformCollision() {
    auto *eventManager = new EventManager();
    bool playerPowerUpCollisionResult;

    /*
     * PLAYER COLLISION WITH BOMB COUNT POWER UP TEST
     */

    auto *bombCountPowerUp = new PowerUP();

    bombCountPowerUp->setType(BOMBCOUNTPWR);
    bombCountPowerUp->setAnimation(POWERANIM);
    bombCountPowerUp->setEffect(BOMCOUNTINC);
    bombCountPowerUp->setXPos(15);
    bombCountPowerUp->setYPos(15);

    eventManager->getPowerups().push_back(bombCountPowerUp);
    eventManager->performCollision(PLAYER, bombCountPowerUp);

    if (!(playerPowerUpCollisionResult = (eventManager->getPowerUp(bombCountPowerUp) == nullptr))) {
        std::cout << "Collision: Player -> Power up | Result: " << playerPowerUpCollisionResult << std::endl;
        return;
    }

    /*
    * PLAYER COLLISION WITH FLAME SIZE POWER UP TEST
    */

    auto *flameSizePowerUp = new PowerUP();

    flameSizePowerUp->setType(FLAMESIZEPWR);
    flameSizePowerUp->setAnimation(POWERANIM);
    flameSizePowerUp->setEffect(FLAMESIZEINC);
    flameSizePowerUp->setXPos(16);
    flameSizePowerUp->setYPos(16);

    eventManager->getPowerups().push_back(flameSizePowerUp);
    eventManager->performCollision(PLAYER, flameSizePowerUp);

    if (!(playerPowerUpCollisionResult = (eventManager->getPowerUp(flameSizePowerUp) == nullptr))) {
        std::cout << "Collision: Player -> Power up | Result: " << playerPowerUpCollisionResult << std::endl;
        return;
    }

    /*
    * PLAYER COLLISION WITH PLAYER SPEED POWER UP TEST
    */

    auto *playerSpeedPowerUp = new PowerUP();

    playerSpeedPowerUp->setType(PLAYERSPEEDPWR);
    playerSpeedPowerUp->setAnimation(POWERANIM);
    playerSpeedPowerUp->setEffect(PLAYERSPEEDINC);
    playerSpeedPowerUp->setXPos(17);
    playerSpeedPowerUp->setYPos(17);

    eventManager->getPowerups().push_back(playerSpeedPowerUp);
    eventManager->performCollision(PLAYER, playerSpeedPowerUp);

    if (!(playerPowerUpCollisionResult = (eventManager->getPowerUp(playerSpeedPowerUp) == nullptr))) {
        std::cout << "Collision: Player -> Power up | Result: " << playerPowerUpCollisionResult << std::endl;
        return;
    }
    std::cout << "Collision: Player -> Power up | Result: " << playerPowerUpCollisionResult << std::endl;
}
