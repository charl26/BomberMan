//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#ifndef BOMBERMAN_EXPLOSION_H
#define BOMBERMAN_EXPLOSION_H

#include "AbstractEntity.hpp"

class Explosion : public AbstractEntity {
private:
    signed short int    xRange;
    signed short int    yRange;

public:
    Explosion(signed short int xRange, signed short int yRange);

    signed short int getXRange() const;

    void setXRange(signed short int xRange);

    signed short int getYRange() const;

    void setYRange(signed short int yRange);

    virtual ~Explosion();
};

#endif //BOMBERMAN_EXPLOSION_H
