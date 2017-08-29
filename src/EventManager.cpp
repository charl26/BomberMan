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
                    auto *powerUp = new PowerUP();

                    brick->setXPos(static_cast<signed short int>(x));
                    brick->setYPos(static_cast<signed short int>(y));
                    brick->setAnimation(BRICKANIM);
                    brick->setType(BRICKWITHPWR);

                    powerUp->setXPos(static_cast<signed short int>(x));
                    powerUp->setYPos(static_cast<signed short int>(y));
                    powerUp->setType(BOMBCOUNTPWR);
                    powerUp->setEffect(BOMCOUNTINC);
                    powerUp->setAnimation(POWERANIM);

                    bricks.push_back(brick);
                    powerups.push_back(powerUp);
                    objects.push_back(dynamic_cast<AbstractEntity *>(brick));
                    objects.push_back(dynamic_cast<AbstractEntity *>(powerUp));
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

std::vector<Ghost *> &EventManager::getGhosts() {
    return ghosts;
}

void EventManager::setGhosts(const std::vector<Ghost *> &ghosts) {
    EventManager::ghosts = ghosts;
}

std::vector<Bomb *> &EventManager::getBombs() {
    return bombs;
}

void EventManager::setBombs(const std::vector<Bomb *> &bombs) {
    EventManager::bombs = bombs;
}

std::vector<Brick *> &EventManager::getBricks() {
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

short EventManager::getLevel() const {
    return level;
}

void EventManager::setLevel(short level) {
    EventManager::level = level;
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
        case GHOST: {
            checkPossibleGhostCollisions(object);
            break;
        }
        case EXPLOSION: {
            checkPossibleExplosionCollisions(object);
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
            break;
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
 * @brief Checks possible objects that ghosts can collide with. If a ghost collided with any of these possible
 * objects, the collision is performed.
 * @param object - The object being collided with.
 */

void EventManager::checkPossibleGhostCollisions(AbstractEntity *object) {
    switch (object->getType()) {
        case PLAYER: {
            killPlayer();
            break;
        }
        default: {
            break;
        }
    }
}

/**
 * @brief Checks possible objects that explosions can collide with. If an explosion collided with any of these possible
 * objects, the collision is performed.
 * @param object - The object being collided with.
 */

void EventManager::checkPossibleExplosionCollisions(AbstractEntity *object) {
    switch (object->getType()) {
        case PLAYER: {
            killPlayer();
            break;
        }
        case GHOST: {
            eraseGhost(object);
            break;
        }
        case BOMB: {
            auto *explosion = new Explosion(bomberman->getXBombRange(), bomberman->getYBombRange());

            explosion->setXPos(object->getXPos());
            explosion->setYPos(object->getYPos());
            explosion->setType(EXPLOSION);
            explosion->setAnimation(EXPLODEANIM);

            eraseBomb(object);

            explosions.push_back(explosion);
            objects.push_back(dynamic_cast<AbstractEntity *>(explosion));
            break;
        }
        case BRICK: {
            eraseBrick(object);
            break;
        }
        case BRICKWITHPWR: {
            Brick *brick = getBrick(dynamic_cast<AbstractEntity *>(object));
            PowerUP *powerUP = getPowerUp(dynamic_cast<AbstractEntity *>(object));

            eraseBrickWithPowerUp(powerUP->getType(), brick);
            break;
        }
        default: {
            break;
        }
    }
}

/**
 * @brief Deducts 1 from the players life, then resets the level to it's original state.
 */

void EventManager::killPlayer() {
    if (bomberman->getLives() > 0) {
        bomberman->setLives(static_cast<signed short int>(bomberman->getLives() - 1));
    } else {
        // TODO: End the game.
    }

    resetLevel(level);
}

/**
 * @brief Swaps the brick on the map with a power up, then erases the brick from it's list and the objects list.
 * @param type - The type of the power up that the brick holds.
 * @param brick - A reference to the brick that holds the power up.
 */

void EventManager::eraseBrickWithPowerUp(Type type, Brick *brick) {
    map[brick->getXPos()][brick->getYPos()] = type;
    eraseBrick(dynamic_cast<AbstractEntity *>(brick));
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
        nextLevel();
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

/**
 * @brief Swaps out the bomb on the map data with an explosion, then deletes the bomb from the bombs and objects list.
 * @param object - A reference to the bomb in the objects list.
 */

void EventManager::eraseBomb(AbstractEntity *object) {
    map[object->getXPos()][object->getYPos()] = EXPLOSION;
    delete (object);

    for (int i{}; i < bombs.size(); i++) {
        if (bombs[i]->getXPos() == object->getXPos() && bombs[i]->getYPos() == object->getYPos()) {
            bombs.erase(bombs.begin() + i);
        }
    }

    for (int i{}; i < objects.size(); i++) {
        if (objects[i]->getXPos() == object->getXPos() && objects[i]->getYPos() == object->getYPos()) {
            objects.erase(objects.begin() + i);
        }
    }
}

/**
 * @brief Swaps out the brick on the map data with an empty tile, then deletes the brick from the bricks and objects
 * list.
 * @param object - A reference to the brick in the objects list.
 */

void EventManager::eraseBrick(AbstractEntity *object) {
    map[object->getXPos()][object->getYPos()] = EMPTYTILE;
    delete (object);

    for (int i{}; i < bricks.size(); i++) {
        if (bricks[i]->getXPos() == object->getXPos() && bricks[i]->getYPos() == object->getYPos()) {
            bricks.erase(bricks.begin() + i);
        }
    }

    for (int i{}; i < objects.size(); i++) {
        if (objects[i]->getXPos() == object->getXPos() && objects[i]->getYPos() == object->getYPos()) {
            objects.erase(objects.begin() + i);
        }
    }
}

/**
 * @brief Swaps out the ghost on the map data with an empty tile, then deletes the ghost from the ghosts and objects
 * list.
 * @param object - A reference to the ghost in the objects list.
 */

void EventManager::eraseGhost(AbstractEntity *object) {
    map[object->getXPos()][object->getYPos()] = EMPTYTILE;
    delete (object);

    for (int i{}; i < ghosts.size(); i++) {
        if (ghosts[i]->getXPos() == object->getXPos() && ghosts[i]->getYPos() == object->getYPos()) {
            ghosts.erase(ghosts.begin() + i);
        }
    }

    for (int i{}; i < objects.size(); i++) {
        if (objects[i]->getXPos() == object->getXPos() && objects[i]->getYPos() == object->getYPos()) {
            objects.erase(objects.begin() + i);
        }
    }
}

/**
 * @brief Retrieves a reference to a brick object from the bricks list that matches the passed object's coordinates.
 * @param object - A reference to a brick in the objects list.
 * @return - A pointer to the brick object.
 */

Brick *EventManager::getBrick(AbstractEntity *object) {
    for (int i{}; i < bricks.size(); i++) {
        if (bricks[i]->getXPos() == object->getXPos() && bricks[i]->getYPos() == object->getYPos()) {
            return (bricks[i]);
        }
    }
    return (nullptr);
}

/**
 * @brief Resets the level to it's original state by loading the original map from it's file.
 * @param level - The level that the game is currently on.
 */

void EventManager::resetLevel(short signed int level) {
    // TODO: Load original map form file.
}

Ghost *EventManager::getGhost(AbstractEntity *object) {
    for (int i{}; i < ghosts.size(); i++) {
        if (ghosts[i]->getXPos() == object->getXPos() && ghosts[i]->getYPos() == object->getYPos()) {
            return (ghosts[i]);
        }
    }
    return (nullptr);
}

Bomb *EventManager::getBomb(AbstractEntity *object) {
    for (auto bomb : bombs) {
        if (bomb->getXPos() == object->getXPos() && bomb->getYPos() == object->getYPos()) {
            return (bomb);
        }
    }
    return (nullptr);
}
