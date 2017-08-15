//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#ifndef BOMBERMAN_BOMB_H
#define BOMBERMAN_BOMB_H

#include "AbstractEntity.hpp"

class Bomb : public AbstractEntity {
private:
    signed short int fuseTime;

public:
    Bomb(signed short int fuseTime);

    signed short int getFuseTime() const;

    void setFuseTime(signed short int fuseTime);

    virtual ~Bomb();
};

#endif //BOMBERMAN_BOMB_H
