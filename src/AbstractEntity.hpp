//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#ifndef BOMBERMAN_ABSTRACTENTITY_H
#define BOMBERMAN_ABSTRACTENTITY_H

#include "Bomberman.hpp"

class AbstractEntity {
private:
    signed short int    xPos;
    signed short int    yPos;
    ActiveEffects       activeEffects;
    Animation           animation;
    Type                type;

public:
    AbstractEntity();

    short getXPos() const;

    void setXPos(short xPos);

    short getYPos() const;

    void setYPos(short yPos);

    ActiveEffects getActiveEffects() const;

    void setActiveEffects(ActiveEffects activeEffects);

    Animation getAnimation() const;

    void setAnimation(Animation animation);

    Type getType() const;

    void setType(Type type);

    virtual ~AbstractEntity();
};

#endif //BOMBERMAN_ABSTRACTENTITY_H
