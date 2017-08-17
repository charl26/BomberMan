//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#include <iostream>
#include "EventManager.hpp"

EventManager::EventManager() {
    EventManager::bomberman = new Bomberman(1, 3, false);

    mapFile.open("Test.txt");

    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            mapFile >> map[x][y];
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

const std::vector<PowerUP *> &EventManager::getPowerups() const {
    return powerups;
}

void EventManager::setPowerups(const std::vector<PowerUP *> &powerups) {
    EventManager::powerups = powerups;
}

/**
 *  @brief
 *
 * Applies the effects of a collision between two objects.
 *
 * @param colliderType
 *      - The type of the object causing the collision.
 *
 * @param collidedObject
 *      - A reference to the object being collided with.
 **/

void EventManager::performCollision(Type colliderType, AbstractEntity &collidedObject) {
    switch (colliderType) {
        case GHOST: {
            if (collidedObject.getType() == PLAYER) {
                resetLevel();
            }
            break;
        }

        case EXPLOSION: {
            if (collidedObject.getType() == BOMB) {
                doBombCollision(collidedObject);
            }
            if (collidedObject.getType() == PLAYER) {
                resetLevel();
            }
            if (collidedObject.getType() == BRICK) {
                doBrickCollision(collidedObject);
            }
            if (collidedObject.getType() == GHOST) {
                eraseGhost(collidedObject);
            }
            break;
        }

        default: {
            break;
        }
    }
}

/**
 * @brief
 *
 * Performs the collision between a movable and a brick.
 *
 * @param collidedObject
 *      - A reference to the object being collided with.
 */

void EventManager::doBrickCollision(AbstractEntity &collidedObject) {
    Brick *brick;
    PowerUP *powerUP;

    brick = getBrick(collidedObject);

    if (brick->hasPowerUp()) {
        powerUP = getPowerUP(collidedObject);
        map[brick->getXPos()][brick->getYPos()] = powerUP->getType();
    } else {
        map[brick->getXPos()][brick->getYPos()] = EMPTYTILE;
    }

    eraseBrick(collidedObject);
}

/**
 * @brief
 *
 * Performs the collision between a movable and a bomb.
 *
 * @param collidedObject
 *      - A reference to the object being collided with.
 */

void EventManager::doBombCollision(AbstractEntity &collidedObject) {
    Explosion *explosion = new Explosion(bomberman->getXBombRange(), bomberman->getYBombRange());

    explosion->setType(EXPLOSION);
    explosion->setAnimation(EXPLODEANIM);
    explosion->setXPos(collidedObject.getXPos());
    explosion->setYPos(collidedObject.getYPos());

    explosions.push_back(explosion);
    objects.push_back((AbstractEntity *) explosion);

    eraseBomb(collidedObject);
}

/**
 * @brief
 *
 * Checks for collision in the specified direction. If there is a collision, performCollision() is called and the
 * player is not moved. If there is no collision, the player is moved in the specified direction.
 *
 * @param dir
 *      - An enum specifying in which direction the player should be moved.
 */

void EventManager::movePlayer(Direction dir) {
    switch (dir) {
        case UP: {
            // TODO: Check collision for up on the player.
            // TODO: Check collision for up in front of the player.
            // TODO: If no collision occurred, move the player up.
            // TODO: Else, don't move the player.
            break;
        }
        case DOWN: {
            // TODO: Check collision for down on the player.
            // TODO: Check collision for down in front of the player.
            // TODO: If no collision occurred, move the player down.
            // TODO: Else, don't move the player.
            break;
        }
        case LEFT: {
            // TODO: Check collision for left on the player.
            // TODO: Check collision for left in front of the player.
            // TODO: If no collision occurred, move the player left.
            // TODO: Else, don't move the player.
            break;
        }
        default: {
            // TODO: Check collision for right on the player.
            // TODO: Check collision for right in front of the player.
            // TODO: If no collision occurred, move the player right.
            // TODO: Else, don't move the player.
            break;
        }
    }
}

/**
 * @brief
 *
 * Finds a specific bomb object in the bombs list by matching it to the collidedObject's coordinates and deletes it
 * from the bombs and objects lists, then updates the map to render an explosion.
 *
 * @param collidedObject
 *      - A reference to the object being collided with.
 */

void EventManager::eraseBomb(AbstractEntity &collidedObject) {
    for (int i{}; i < bombs.size(); i++) {
        if (bombs[i]->getXPos() == collidedObject.getXPos() && bombs[i]->getYPos() == collidedObject.getYPos()) {
            delete(bombs[i]);
            bombs.erase(bombs.begin() + i);
            break;
        }
    }

    for (int i{}; i < objects.size(); i++) {
        if (objects[i]->getXPos() == collidedObject.getXPos() && objects[i]->getYPos() == collidedObject.getYPos()) {
            delete (objects[i]);
            objects.erase(objects.begin() + i);
            break;
        }
    }

    map[collidedObject.getXPos()][collidedObject.getYPos()] = EXPLOSION;
}

/**
 * @brief
 *
 * Finds a specific brick object in the bricks list by matching it to the collidedObject's coordinates and deletes it
 * from the bricks and objects lists.
 *
 * @param collidedObject
 *      - A reference to the object being collided with.
 */

void EventManager::eraseBrick(AbstractEntity &collidedObject) {
    for (int i{}; i < bricks.size(); i++) {
        if (bricks[i]->getXPos() == collidedObject.getXPos() && bricks[i]->getYPos() == collidedObject.getYPos()) {
            delete(bricks[i]);
            bricks.erase(bricks.begin() + i);
            break;
        }
    }

    for (int i{}; i < objects.size(); i++) {
        if (objects[i]->getXPos() == collidedObject.getXPos() && objects[i]->getYPos() == collidedObject.getYPos()) {
            delete (objects[i]);
            objects.erase(objects.begin() + i);
            break;
        }
    }
}

/**
 * @brief
 *
 * Finds a specific explosion object in the explosions list by matching it to the collidedObject's coordinates and
 * deletes it from the explosions and objects lists, then updates the map to render an empty tile.
 *
 * @param collidedObject
 *      - A reference to the object being collided with.
 */

void EventManager::eraseExplosion(AbstractEntity &collidedObject) {
    for (int i{}; i < explosions.size(); i++) {
        if (explosions[i]->getXPos() == collidedObject.getXPos() &&
            explosions[i]->getYPos() == collidedObject.getYPos()) {
            delete(explosions[i]);
            explosions.erase(explosions.begin() + i);
            break;
        }
    }

    for (int i{}; i < objects.size(); i++) {
        if (objects[i]->getXPos() == collidedObject.getXPos() && objects[i]->getYPos() == collidedObject.getYPos()) {
            delete (objects[i]);
            objects.erase(objects.begin() + i);
            break;
        }
    }

    map[collidedObject.getXPos()][collidedObject.getYPos()] = EMPTYTILE;
}

/**
 * @brief
 *
 * Finds a specific ghost object in the ghosts list by matching it to the collidedObject's coordinates and
 * deletes it from the ghosts and objects lists, then updates the map to render an empty tile.
 *
 * @param collidedObject
 *      - A reference to the object being collided with.
 */

void EventManager::eraseGhost(AbstractEntity &collidedObject) {
    for (int i{}; i < ghosts.size(); i++) {
        if (ghosts[i]->getXPos() == collidedObject.getXPos() && ghosts[i]->getYPos() == collidedObject.getYPos()) {
            delete(ghosts[i]);
            ghosts.erase(ghosts.begin() + i);
            break;
        }
    }

    for (int i{}; i < objects.size(); i++) {
        if (objects[i]->getXPos() == collidedObject.getXPos() && objects[i]->getYPos() == collidedObject.getYPos()) {
            delete (objects[i]);
            objects.erase(objects.begin() + i);
            break;
        }
    }

    map[collidedObject.getXPos()][collidedObject.getYPos()] = EMPTYTILE;
}

/**
 * @brief
 *
 * Finds a specific powerup object in the powerups list by matching it to the collidedObject's coordinates and
 * deletes it from the powerups and objects lists, then updates the map to render an empty tile.
 *
 * @param collidedObject
 *      - A reference to the object being collided with.
 */

void EventManager::erasePowerUP(AbstractEntity &collidedObject) {
    for (int i{}; i < powerups.size(); i++) {
        if (powerups[i]->getXPos() == collidedObject.getXPos() && powerups[i]->getYPos() == collidedObject.getYPos()) {
            delete(powerups[i]);
            powerups.erase(powerups.begin() + i);
            break;
        }
    }

    for (int i{}; i < objects.size(); i++) {
        if (objects[i]->getXPos() == collidedObject.getXPos() && objects[i]->getYPos() == collidedObject.getYPos()) {
            delete (objects[i]);
            objects.erase(objects.begin() + i);
            break;
        }
    }

    map[collidedObject.getXPos()][collidedObject.getYPos()] = EMPTYTILE;
}

/**
 * @brief
 *
 * Retrieves a specific bomb object in the bombs list by matching it to the collidedObject's coordinates and returns
 * a pointer to it.
 *
 * @param collidedObject
 *      - A reference to the object being collided with.
 *
 * @return
 *      - A pointer to a bomb object.
 */

Bomb *EventManager::getBomb(AbstractEntity &collidedObject) {
    for (int i{}; i < bombs.size(); i++) {
        if (bombs[i]->getXPos() == collidedObject.getXPos() && bombs[i]->getYPos() == collidedObject.getYPos()) {
            return (bombs[i]);
        }
    }
    return (nullptr);
}

/**
 * @brief
 *
 * Retrieves a specific brick object in the bricks list by matching it to the collidedObject's coordinates and returns
 * a pointer to it.
 *
 * @param collidedObject
 *      - A reference to the object being collided with.
 *
 * @return
 *      - A pointer to a brick object.
 */

Brick *EventManager::getBrick(AbstractEntity &collidedObject) {
    for (int i{}; i < bricks.size(); i++) {
        if (bricks[i]->getXPos() == collidedObject.getXPos() && bricks[i]->getYPos() == collidedObject.getYPos()) {
            return (bricks[i]);
        }
    }
    return (nullptr);
}

/**
 * @brief
 *
 * Retrieves a specific explosion object in the explosions list by matching it to the collidedObject's coordinates
 * and returns a pointer to it.
 *
 * @param collidedObject
 *      - A reference to the object being collided with.
 *
 * @return
 *      - A pointer to a explosion object.
 */

Explosion *EventManager::getExplosion(AbstractEntity &collidedObject) {
    for (int i{}; i < explosions.size(); i++) {
        if (explosions[i]->getXPos() == collidedObject.getXPos() &&
            explosions[i]->getYPos() == collidedObject.getYPos()) {
            return (explosions[i]);
        }
    }
    return (nullptr);
}

/**
 * @brief
 *
 * Retrieves a specific ghost object in the ghosts list by matching it to the collidedObject's coordinates and returns
 * a pointer to it.
 *
 * @param collidedObject
 *      - A reference to the object being collided with.
 *
 * @return
 *      - A pointer to a ghost object.
 */

Ghost *EventManager::getGhost(AbstractEntity &collidedObject) {
    for (int i{}; i < ghosts.size(); i++) {
        if (ghosts[i]->getXPos() == collidedObject.getXPos() && ghosts[i]->getYPos() == collidedObject.getYPos()) {
            return (ghosts[i]);
        }
    }
    return (nullptr);
}

/**
 * @brief
 *
 * Retrieves a specific powerup object in the powerups list by matching it to the collidedObject's coordinates and
 * returns a pointer to it.
 *
 * @param collidedObject
 *      - A reference to the object being collided with.
 *
 * @return
 *      - A pointer to a powerup object.
 */

PowerUP *EventManager::getPowerUP(AbstractEntity &collidedObject) {
    for (int i{}; i < powerups.size(); i++) {
        if (powerups[i]->getXPos() == collidedObject.getXPos() && powerups[i]->getYPos() == collidedObject.getYPos()) {
            return (powerups[i]);
        }
    }
    return (nullptr);
}

void EventManager::nextLevel() {

}

void EventManager::resetLevel() {
    std::vector<Effect> activeEffects = {};

    bomberman->setType(PLAYER);
    bomberman->setAnimation(PLAYERANIM);
    bomberman->setXPos(0); // TODO: Update this value.
    bomberman->setYPos(0); // TODO: Update this value.
    bomberman->setBombCount(1);
    bomberman->setLives(static_cast<signed short int>(bomberman->getLives() - 1));
    bomberman->setRemote(false);
    bomberman->setXBombRange(3); // TODO: Update this value.
    bomberman->setYBombRange(3); // TODO: Update this value.
    bomberman->setActiveEffects(activeEffects);

    objects.clear();
    bombs.clear();
    bricks.clear();
    explosions.clear();
    ghosts.clear();
    powerups.clear();

    // TODO: Re-place bricks, ghosts, power-ups and door.
    // TODO: Re-populate the lists with objects.
}
