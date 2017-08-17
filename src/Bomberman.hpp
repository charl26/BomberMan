//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#ifndef BOMBERMAN_BOMBERMAN_H
#define BOMBERMAN_BOMBERMAN_H

#include "AbstractEntity.hpp"

class Bomberman : public AbstractEntity {
private:
    signed short int    bombCount;
    signed short int    lives;
    signed short int    xBombRange;
    signed short int    yBombRange;
    bool                remote;

public:
    Bomberman(short bombCount, short lives, bool remote);

    short getBombCount() const;

    void setBombCount(short bombCount);

    short getLives() const;

    void setLives(short lives);

    short getXBombRange() const;

    void setXBombRange(short xBombRange);

    short getYBombRange() const;

    void setYBombRange(short yBombRange);

    bool isRemote() const;

    void setRemote(bool remote);

    virtual ~Bomberman();
};

#endif //BOMBERMAN_BOMBERMAN_H
