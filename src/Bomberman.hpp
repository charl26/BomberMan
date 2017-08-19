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
    bool                remote;
    signed short int    xBombRange;
    signed short int    yBombRange;

public:
    Bomberman(short bombCount, short lives, bool remote);

    short getBombCount() const;

    void setBombCount(short bombCount);

    short getLives() const;

    void setLives(short lives);

    bool isRemote() const;

    void setRemote(bool remote);

    short getXBombRange() const;

    void setXBombRange(short xBmbRange);

    short getYBombRange() const;

    void setYBombRange(short yBombRange);

    virtual ~Bomberman();
};

#endif //BOMBERMAN_BOMBERMAN_H
