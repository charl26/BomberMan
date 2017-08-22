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

    if (objectPass) {
        std::cout << "Object Generation Test: PASS" << std::endl;
    } else {
        std::cout << "Object Generation Test: FAIL" << std::endl;
    }
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

    if (coordPass) {
        std::cout << "Object coordinate Test: PASS" << std::endl;
    } else {
        std::cout << "Object coordinate Test: FAIL" << std::endl;
    }
    delete (eventManager);
}

/**
 * @brief Tests collision between all objects, making sure that the correct actions are taken when a collision occurs.
 */

void TestEventManagerPerformCollision() {
    auto *eventManager = new EventManager();
    bool playerPowerUpCollisionResult;
    bool ghostPowerUpCollisionResult;
    bool explosionPowerUpCollisionResult;

    /*
     * PLAYER COLLISION WITH BOMB COUNT POWER UP TEST
     */

    auto *pBombCountPowerUp = new PowerUP();

    pBombCountPowerUp->setType(BOMBCOUNTPWR);
    pBombCountPowerUp->setAnimation(POWERANIM);
    pBombCountPowerUp->setEffect(BOMCOUNTINC);
    pBombCountPowerUp->setXPos(15);
    pBombCountPowerUp->setYPos(15);

    eventManager->getPowerups().push_back(pBombCountPowerUp);
    eventManager->performCollision(PLAYER, pBombCountPowerUp);

    if (!(playerPowerUpCollisionResult = (eventManager->getPowerUp(pBombCountPowerUp) == nullptr))) {
        std::cout << "Collision: Player -> Power up | Result: FAIL" << std::endl;
    }

    /*
    * PLAYER COLLISION WITH FLAME SIZE POWER UP TEST
    */

    auto *pFlameSizePowerUp = new PowerUP();

    pFlameSizePowerUp->setType(FLAMESIZEPWR);
    pFlameSizePowerUp->setAnimation(POWERANIM);
    pFlameSizePowerUp->setEffect(FLAMESIZEINC);
    pFlameSizePowerUp->setXPos(16);
    pFlameSizePowerUp->setYPos(16);

    eventManager->getPowerups().push_back(pFlameSizePowerUp);
    eventManager->performCollision(PLAYER, pFlameSizePowerUp);

    if (!(playerPowerUpCollisionResult = (eventManager->getPowerUp(pFlameSizePowerUp) == nullptr))) {
        std::cout << "Collision: Player -> Power up | Result: FAIL" << std::endl;
    }

    /*
    * PLAYER COLLISION WITH PLAYER SPEED POWER UP TEST
    */

    auto *pPlayerSpeedPowerUp = new PowerUP();

    pPlayerSpeedPowerUp->setType(PLAYERSPEEDPWR);
    pPlayerSpeedPowerUp->setAnimation(POWERANIM);
    pPlayerSpeedPowerUp->setEffect(PLAYERSPEEDINC);
    pPlayerSpeedPowerUp->setXPos(17);
    pPlayerSpeedPowerUp->setYPos(17);

    eventManager->getPowerups().push_back(pPlayerSpeedPowerUp);
    eventManager->performCollision(PLAYER, pPlayerSpeedPowerUp);

    if (!(playerPowerUpCollisionResult = (eventManager->getPowerUp(pPlayerSpeedPowerUp) == nullptr))) {
        std::cout << "Collision: Player -> Power up | Result: FAIL" << std::endl;
    } else {
        std::cout << "Collision: Player -> Power up | Result: PASS" << std::endl;
    }

    /*
    * GHOST COLLISION WITH BOMB COUNT POWER UP TEST
    */

    auto *gBombCountPowerUp = new PowerUP();

    gBombCountPowerUp->setType(BOMBCOUNTPWR);
    gBombCountPowerUp->setAnimation(POWERANIM);
    gBombCountPowerUp->setEffect(BOMCOUNTINC);
    gBombCountPowerUp->setXPos(15);
    gBombCountPowerUp->setYPos(15);

    eventManager->getPowerups().push_back(gBombCountPowerUp);
    eventManager->performCollision(GHOST, gBombCountPowerUp);

    if ((ghostPowerUpCollisionResult = (eventManager->getPowerUp(gBombCountPowerUp) == nullptr))) {
        std::cout << "Collision: Ghost -> Power up | Result: FAIL" << std::endl;
    }

    delete (gBombCountPowerUp);
    eventManager->erasePowerUP(gBombCountPowerUp);

    /*
    * GHOST COLLISION WITH FLAME SIZE POWER UP TEST
    */

    auto *gFlameSizePowerUp = new PowerUP();

    gFlameSizePowerUp->setType(FLAMESIZEPWR);
    gFlameSizePowerUp->setAnimation(POWERANIM);
    gFlameSizePowerUp->setEffect(FLAMESIZEINC);
    gFlameSizePowerUp->setXPos(16);
    gFlameSizePowerUp->setYPos(16);

    eventManager->getPowerups().push_back(gFlameSizePowerUp);
    eventManager->performCollision(GHOST, gFlameSizePowerUp);

    if ((ghostPowerUpCollisionResult = (eventManager->getPowerUp(gFlameSizePowerUp) == nullptr))) {
        std::cout << "Collision: Ghost -> Power up | Result: FAIL" << std::endl;
    }
  
    delete (gFlameSizePowerUp);
    eventManager->erasePowerUP(gFlameSizePowerUp);
  
    /*
    * GHOST COLLISION WITH PLAYER SPEED POWER UP TEST
    */

    auto *gPlayerSpeedPowerUp = new PowerUP();

    gPlayerSpeedPowerUp->setType(PLAYERSPEEDPWR);
    gPlayerSpeedPowerUp->setAnimation(POWERANIM);
    gPlayerSpeedPowerUp->setEffect(PLAYERSPEEDINC);
    gPlayerSpeedPowerUp->setXPos(17);
    gPlayerSpeedPowerUp->setYPos(17);

    eventManager->getPowerups().push_back(gPlayerSpeedPowerUp);
    eventManager->performCollision(GHOST, gPlayerSpeedPowerUp);

    if ((ghostPowerUpCollisionResult = (eventManager->getPowerUp(gPlayerSpeedPowerUp) == nullptr))) {
        std::cout << "Collision: Ghost -> Power up | Result: FAIL" << std::endl;
    }

    if (ghostPowerUpCollisionResult) {
        std::cout << "Collision: Ghost -> Power up | Result: FAIL" << std::endl;
    } else {
        std::cout << "Collision: Ghost -> Power up | Result: PASS" << std::endl;
    }
  
    delete (gPlayerSpeedPowerUp);
    eventManager->erasePowerUP(gPlayerSpeedPowerUp);

    /*
    * EXPLOSION COLLISION WITH BOMB COUNT POWER UP TEST
    */

    auto *eBombCountPowerUp = new PowerUP();

    eBombCountPowerUp->setType(BOMBCOUNTPWR);
    eBombCountPowerUp->setAnimation(POWERANIM);
    eBombCountPowerUp->setEffect(BOMCOUNTINC);
    eBombCountPowerUp->setXPos(15);
    eBombCountPowerUp->setYPos(15);

    eventManager->getPowerups().push_back(eBombCountPowerUp);
    eventManager->performCollision(EXPLOSION, eBombCountPowerUp);

    if ((explosionPowerUpCollisionResult = (eventManager->getPowerUp(eBombCountPowerUp) == nullptr))) {
        std::cout << "Collision: Explosion -> Power up | Result: FAIL" << std::endl;
    }

    /*
    * EXPLOSION COLLISION WITH FLAME SIZE POWER UP TEST
    */

    auto *eFlameSizePowerUp = new PowerUP();

    eFlameSizePowerUp->setType(FLAMESIZEPWR);
    eFlameSizePowerUp->setAnimation(POWERANIM);
    eFlameSizePowerUp->setEffect(FLAMESIZEINC);
    eFlameSizePowerUp->setXPos(16);
    eFlameSizePowerUp->setYPos(16);

    eventManager->getPowerups().push_back(eFlameSizePowerUp);
    eventManager->performCollision(EXPLOSION, eFlameSizePowerUp);

    if ((explosionPowerUpCollisionResult = (eventManager->getPowerUp(eFlameSizePowerUp) == nullptr))) {
        std::cout << "Collision: Explosion -> Power up | Result: FAIL" << std::endl;
    }

    /*
    * EXPLOSION COLLISION WITH PLAYER SPEED POWER UP TEST
    */

    auto *ePlayerSpeedPowerUp = new PowerUP();

    ePlayerSpeedPowerUp->setType(PLAYERSPEEDPWR);
    ePlayerSpeedPowerUp->setAnimation(POWERANIM);
    ePlayerSpeedPowerUp->setEffect(PLAYERSPEEDINC);
    ePlayerSpeedPowerUp->setXPos(17);
    ePlayerSpeedPowerUp->setYPos(17);

    eventManager->getPowerups().push_back(ePlayerSpeedPowerUp);
    eventManager->performCollision(EXPLOSION, ePlayerSpeedPowerUp);

    if ((explosionPowerUpCollisionResult = (eventManager->getPowerUp(ePlayerSpeedPowerUp) == nullptr))) {
        std::cout << "Collision: Explosion -> Power up | Result: FAIL" << std::endl;
    }

    if (explosionPowerUpCollisionResult) {
        std::cout << "Collision: Explosion -> Power up | Result: FAIL" << std::endl;
    } else {
        std::cout << "Collision: Explosion -> Power up | Result: PASS" << std::endl;
    }

    eBombCountPowerUp->setType(BOMBCOUNTPWR);
    eBombCountPowerUp->setAnimation(POWERANIM);
    eBombCountPowerUp->setEffect(BOMCOUNTINC);
    eBombCountPowerUp->setXPos(15);
    eBombCountPowerUp->setYPos(15);

    eventManager->getPowerups().push_back(eBombCountPowerUp);
    eventManager->performCollision(EXPLOSION, eBombCountPowerUp);

    if ((explosionPowerUpCollisionResult = (eventManager->getPowerUp(eBombCountPowerUp) == nullptr))) {
        std::cout << "Collision: Explosion -> Power up | Result: FAIL" << std::endl;
    }

    delete (eBombCountPowerUp);
    eventManager->erasePowerUP(eBombCountPowerUp);

    /*
    * EXPLOSION COLLISION WITH FLAME SIZE POWER UP TEST
    */

    auto *eFlameSizePowerUp = new PowerUP();

    eFlameSizePowerUp->setType(FLAMESIZEPWR);
    eFlameSizePowerUp->setAnimation(POWERANIM);
    eFlameSizePowerUp->setEffect(FLAMESIZEINC);
    eFlameSizePowerUp->setXPos(16);
    eFlameSizePowerUp->setYPos(16);

    eventManager->getPowerups().push_back(eFlameSizePowerUp);
    eventManager->performCollision(EXPLOSION, eFlameSizePowerUp);

    if ((explosionPowerUpCollisionResult = (eventManager->getPowerUp(eFlameSizePowerUp) == nullptr))) {
        std::cout << "Collision: Explosion -> Power up | Result: FAIL" << std::endl;
    }

    delete (eFlameSizePowerUp);
    eventManager->erasePowerUP(eFlameSizePowerUp);

    /*
    * EXPLOSION COLLISION WITH PLAYER SPEED POWER UP TEST
    */

    auto *ePlayerSpeedPowerUp = new PowerUP();

    ePlayerSpeedPowerUp->setType(PLAYERSPEEDPWR);
    ePlayerSpeedPowerUp->setAnimation(POWERANIM);
    ePlayerSpeedPowerUp->setEffect(PLAYERSPEEDINC);
    ePlayerSpeedPowerUp->setXPos(17);
    ePlayerSpeedPowerUp->setYPos(17);

    eventManager->getPowerups().push_back(ePlayerSpeedPowerUp);
    eventManager->performCollision(EXPLOSION, ePlayerSpeedPowerUp);

    if ((explosionPowerUpCollisionResult = (eventManager->getPowerUp(ePlayerSpeedPowerUp) == nullptr))) {
        std::cout << "Collision: Explosion -> Power up | Result: FAIL" << std::endl;
    }

    if (explosionPowerUpCollisionResult) {
        std::cout << "Collision: Explosion -> Power up | Result: FAIL" << std::endl;
    } else {
        std::cout << "Collision: Explosion -> Power up | Result: PASS" << std::endl;
    }

    delete (ePlayerSpeedPowerUp);
    eventManager->erasePowerUP(ePlayerSpeedPowerUp);
}
