//
// Created by Franco SCHEEPERS on 2017/08/18.
//

#include "EventManager.hpp"
#include <iostream>

EventManager::EventManager() {
    generateObjects();
}

/**
 * @brief Reads the map then creates and stores objects in their respective lists according to the data found in the
 * map.
 */

void EventManager::generateObjects() {
    int mapRows;
    int mapCol;

    mapRows = sizeof(map) / sizeof(map[0]);
    mapCol = sizeof(map[0]) / sizeof(map[0][0]);

    for (int x{}; x < mapRows; x++) {
        for (int y{}; y < mapCol; y++) {
            switch (map[x][y]) {
                case PLAYER: {
                    bomberman = new Bomberman(1, 3, false, 3, 3);
                    std::vector<Effect> activeEffects = {};

                    bomberman->setType(PLAYER);
                    bomberman->setAnimation(PLAYERANIM);
                    bomberman->setXPos(static_cast<signed short int>(x));
                    bomberman->setYPos(static_cast<signed short int>(y));
                    bomberman->setActiveEffects(activeEffects);
                    break;
                }
                case GHOST: {
                    auto *ghost = new Ghost();

                    ghost->setXPos(static_cast<signed short int>(x));
                    ghost->setYPos(static_cast<signed short int>(y));
                    ghost->setAnimation(GHOSTANIM);
                    ghost->setType(GHOST);

                    ghosts.push_back(ghost);
                    objects.push_back(dynamic_cast<AbstractEntity *>(ghost));
                    break;
                }
                case BRICK: {
                    auto *brick = new Brick(false);

                    brick->setXPos(static_cast<signed short int>(x));
                    brick->setYPos(static_cast<signed short int>(y));
                    brick->setAnimation(BRICKANIM);
                    brick->setType(BRICK);

                    bricks.push_back(brick);
                    objects.push_back(dynamic_cast<AbstractEntity *>(brick));
                    break;
                }
                case BRICKWITHPWR: {
                    auto *brick = new Brick(true);

                    brick->setXPos(static_cast<signed short int>(x));
                    brick->setYPos(static_cast<signed short int>(y));
                    brick->setAnimation(BRICKANIM);
                    brick->setType(BRICKWITHPWR);

                    bricks.push_back(brick);
                    objects.push_back(dynamic_cast<AbstractEntity *>(brick));
                    break;
                }
                case SOLIDBRICK: {
                    auto *brick = new Brick(false);

                    brick->setXPos(static_cast<signed short int>(x));
                    brick->setYPos(static_cast<signed short int>(y));
                    brick->setAnimation(BRICKANIM);
                    brick->setType(SOLIDBRICK);

                    bricks.push_back(brick);
                    objects.push_back(dynamic_cast<AbstractEntity *>(brick));
                    break;
                }
                case DOOR: {
                    auto *powerup = new PowerUP();

                    powerup->setXPos(static_cast<signed short int>(x));
                    powerup->setYPos(static_cast<signed short int>(y));
                    powerup->setEffect(NEXTLEVEL);
                    powerup->setAnimation(POWERANIM);
                    powerup->setType(DOOR);

                    powerups.push_back(powerup);
                    objects.push_back(dynamic_cast<AbstractEntity *>(powerup));
                    break;
                }
                case BOMBCOUNTPWR: {
                    auto *powerup = new PowerUP();

                    powerup->setXPos(static_cast<signed short int>(x));
                    powerup->setYPos(static_cast<signed short int>(y));
                    powerup->setEffect(BOMCOUNTINC);
                    powerup->setAnimation(POWERANIM);
                    powerup->setType(BOMBCOUNTPWR);

                    powerups.push_back(powerup);
                    objects.push_back(dynamic_cast<AbstractEntity *>(powerup));
                    break;
                }
                case FLAMESIZEPWR: {
                    auto *powerup = new PowerUP();

                    powerup->setXPos(static_cast<signed short int>(x));
                    powerup->setYPos(static_cast<signed short int>(y));
                    powerup->setEffect(FLAMESIZEINC);
                    powerup->setAnimation(POWERANIM);
                    powerup->setType(FLAMESIZEPWR);

                    powerups.push_back(powerup);
                    objects.push_back(dynamic_cast<AbstractEntity *>(powerup));
                    break;
                }
                case PLAYERSPEEDPWR: {
                    auto *powerup = new PowerUP();

                    powerup->setXPos(static_cast<signed short int>(x));
                    powerup->setYPos(static_cast<signed short int>(y));
                    powerup->setEffect(PLAYERSPEEDINC);
                    powerup->setAnimation(POWERANIM);
                    powerup->setType(PLAYERSPEEDPWR);

                    powerups.push_back(powerup);
                    objects.push_back(dynamic_cast<AbstractEntity *>(powerup));
                    break;
                }
                default: {
                    break;
                }
            }
        }
    }
}

Bomberman *EventManager::getBomberman() const {
    return bomberman;
}

void EventManager::setBomberman(Bomberman *bomberman) {
    EventManager::bomberman = bomberman;
}

const std::vector<AbstractEntity *> &EventManager::getObjects() const {
    return objects;
}

void EventManager::setObjects(const std::vector<AbstractEntity *> &objects) {
    EventManager::objects = objects;
}

const std::vector<Ghost *> &EventManager::getGhosts() const {
    return ghosts;
}

void EventManager::setGhosts(const std::vector<Ghost *> &ghosts) {
    EventManager::ghosts = ghosts;
}

const std::vector<Bomb *> &EventManager::getBombs() const {
    return bombs;
}

void EventManager::setBombs(const std::vector<Bomb *> &bombs) {
    EventManager::bombs = bombs;
}

const std::vector<Brick *> &EventManager::getBricks() const {
    return bricks;
}

void EventManager::setBricks(const std::vector<Brick *> &bricks) {
    EventManager::bricks = bricks;
}

const std::vector<Explosion *> &EventManager::getExplosions() const {
    return explosions;
}

void EventManager::setExplosions(const std::vector<Explosion *> &explosions) {
    EventManager::explosions = explosions;
}

std::vector<PowerUP *> &EventManager::getPowerups() {
    return powerups;
}

void EventManager::setPowerups(const std::vector<PowerUP *> &powerups) {
    EventManager::powerups = powerups;
}

/**
 * @brief Applies the effect of a collision between two objects.
 * @param colliderType - The Object causing the collision.
 * @param object - The Object being collided with.
 */

void EventManager::performCollision(Type colliderType, AbstractEntity *object) {
    switch (colliderType) {
        case PLAYER: {
            checkPossiblePlayerCollisions(object);
            break;
        }
        default: {
            break;
        }
    }
}

/**
 * @brief Checks possible objects that the player can collide with. If the player collided with any of these possible
 * objects, the collision is performed.
 * @param object - The object being collided with.
 */

void EventManager::checkPossiblePlayerCollisions(AbstractEntity *object) {
    switch (object->getType()) {
        case BOMBCOUNTPWR: {
            applyPowerUp(object);
            break;
        }
        case FLAMESIZEPWR: {
            applyPowerUp(object);
            break;
        }
        case PLAYERSPEEDPWR: {
            applyPowerUp(object);
        }
        case DOOR: {
            nextLevel();
            break;
        }
        default: {
            break;
        }
    }
}

/**
 * @brief Applies the effect of a power up to the player, then deletes the power up from the object list.
 * @param object - The object being collided with.
 */

void EventManager::applyPowerUp(AbstractEntity *object) {
    std::vector<Effect> activeEffects;
    PowerUP *powerUP;

    activeEffects = bomberman->getActiveEffects();
    powerUP = getPowerUp(object);

    if (powerUP != nullptr) {
        activeEffects.push_back(powerUP->getEffect());
        bomberman->setActiveEffects(activeEffects);
        erasePowerUP(dynamic_cast<AbstractEntity *>(powerUP));
    } else {
        // TODO: Throw error.
    }
}

/**
 * @brief If all the enemies on the map are dead, then the player is taken to the next level, otherwise, nothing is
 * done.
 */

void EventManager::nextLevel() {
    if (ghosts.empty()) {
        // TODO: Load next level.
    }
}

/**
 * @brief Retrieves a reference to the object being collided with.
 * @param object - The object being collided with.
 * @return - A pointer to a power up object.
 */

PowerUP *EventManager::getPowerUp(AbstractEntity *object) {
    for (int i{}; i < powerups.size(); i++) {
        if (powerups[i]->getXPos() == object->getXPos() && powerups[i]->getYPos() == object->getYPos()) {
            return (powerups[i]);
        }
    }
    return (nullptr);
}

/**
 * @brief Searches for an object in the powerups and objects lists by coordinates, then deletes it from memory and
 * erases it from the lists and map.
 * @param object - The object to be deleted.
 */

void EventManager::erasePowerUP(AbstractEntity *object) {
    map[object->getXPos()][object->getYPos()] = EMPTYTILE;
    delete (object);

    for (int i{}; i < powerups.size(); i++) {
        if (powerups[i]->getXPos() == object->getXPos() && powerups[i]->getYPos() == object->getYPos()) {
            powerups.erase(powerups.begin() + i);
        }
    }

    for (int i{}; i < objects.size(); i++) {
        if (objects[i]->getXPos() == object->getXPos() && objects[i]->getYPos() == object->getYPos()) {
            objects.erase(objects.begin() + i);
        }
    }
}
