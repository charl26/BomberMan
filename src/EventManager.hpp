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

    const std::vector<Ghost *> &getGhosts() const;

    void setGhosts(const std::vector<Ghost *> &ghosts);

    const std::vector<Bomb *> &getBombs() const;

    void setBombs(const std::vector<Bomb *> &bombs);

    const std::vector<Brick *> &getBricks() const;

    void setBricks(const std::vector<Brick *> &bricks);

    const std::vector<Explosion *> &getExplosions() const;

    void setExplosions(const std::vector<Explosion *> &explosions);

    const std::vector<PowerUP *> &getPowerups() const;

    void setPowerups(const std::vector<PowerUP *> &powerups);

    void performCollision(Type colliderType, AbstractEntity &object);

    PowerUP *getPowerUp(AbstractEntity &object);

    void movePlayer(Direction dir);

    void eraseBomb(AbstractEntity &collidedObject);

    void eraseBrick(AbstractEntity &collidedObject);

    void eraseExplosion(AbstractEntity &collidedObject);

    void eraseGhost(AbstractEntity &collidedObject);

    void erasePowerUP(AbstractEntity &collidedObject);

    Bomb *getBomb(AbstractEntity &collidedObject);

    Brick *getBrick(AbstractEntity &collidedObject);

    Explosion *getExplosion(AbstractEntity &collidedObject);

    Ghost *getGhost(AbstractEntity &collidedObject);

    PowerUP *getPowerUP(AbstractEntity &collidedObject);

    void doBombCollision(AbstractEntity &collidedObject);

    void doBrickCollision(AbstractEntity &collidedObject);

    void nextLevel();

    void resetLevel();

    void generateObjects();
};

#endif //BOMBERMAN_EVENTMANAGER_H
