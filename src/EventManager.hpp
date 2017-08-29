//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#ifndef BOMBERMAN_EVENTMANAGER_H
#define BOMBERMAN_EVENTMANAGER_H

#include <vector>
#include <fstream>
#include "Ghost.hpp"
#include "Bomb.hpp"
#include "Explosion.hpp"
#include "PowerUP.hpp"
#include "Brick.hpp"
#include "Bomberman.hpp"

class EventManager {
private:
    Bomberman                       *bomberman;
    std::vector<AbstractEntity *>   objects;
    std::vector<Ghost *>            ghosts;
    std::vector<Bomb *>             bombs;
    std::vector<Brick *>            bricks;
    std::vector<Explosion *>        explosions;
    std::vector<PowerUP *>          powerups;
    signed short int                level;

public:
    int map[11][13] = {{7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7},
                       {7, 1, 0, 2, 0, 0, 0, 0, 0, 5, 0, 6, 7},
                       {7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7},
                       {7, 0, 0, 0, 0, 0, 0, 11, 0, 10, 0, 9, 7},
                       {7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7},
                       {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
                       {7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7},
                       {7, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
                       {7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7, 0, 7},
                       {7, 8, 0, 0, 0, 0, 0, 0, 0, 0, 0, 0, 7},
                       {7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7, 7}};

    EventManager();

    Bomberman *getBomberman() const;

    void setBomberman(Bomberman *bomberman);

    const std::vector<AbstractEntity *> &getObjects() const;

    void setObjects(const std::vector<AbstractEntity *> &objects);

    std::vector<Ghost *> &getGhosts();

    void setGhosts(const std::vector<Ghost *> &ghosts);

    std::vector<Bomb *> &getBombs();

    void setBombs(const std::vector<Bomb *> &bombs);

    std::vector<Brick *> &getBricks();

    void setBricks(const std::vector<Brick *> &bricks);

    const std::vector<Explosion *> &getExplosions() const;

    void setExplosions(const std::vector<Explosion *> &explosions);

    std::vector<PowerUP *> &getPowerups();

    void setPowerups(const std::vector<PowerUP *> &powerups);

    short getLevel() const;

    void setLevel(short level);

    void performCollision(Type colliderType, AbstractEntity *object);

    void checkPossiblePlayerCollisions(AbstractEntity *object);

    void checkPossibleGhostCollisions(AbstractEntity *object);

    void checkPossibleExplosionCollisions(AbstractEntity *object);

    void applyPowerUp(AbstractEntity *object);

    void nextLevel();

    PowerUP *getPowerUp(AbstractEntity *object);

    void movePlayer(Direction dir);

    void eraseBomb(AbstractEntity *object);

    void eraseBrick(AbstractEntity *object);

    void eraseExplosion(AbstractEntity &collidedObject);

    void eraseGhost(AbstractEntity *object);

    void erasePowerUP(AbstractEntity *collidedObject);

    Bomb *getBomb(AbstractEntity *object);

    Brick *getBrick(AbstractEntity *object);

    Explosion *getExplosion(AbstractEntity &collidedObject);

    Ghost *getGhost(AbstractEntity *object);

    void doBombCollision(AbstractEntity &collidedObject);

    void doBrickCollision(AbstractEntity &collidedObject);

    void resetLevel(short signed int level);

    void generateObjects();

    void killPlayer();

    void eraseBrickWithPowerUp(Type type, Brick *brick);
};

#endif //BOMBERMAN_EVENTMANAGER_H
