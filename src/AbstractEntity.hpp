//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#ifndef BOMBERMAN_ABSTRACTENTITY_H
#define BOMBERMAN_ABSTRACTENTITY_H

enum ActiveEffects {TEMP1 = 1};
enum Animation {TEMP2 = 1};
enum Type {PLAYER = 1, GHOST = 2, BOMB = 3, EXPLOSION = 4, POWERUP = 5, BRICK = 6, SOLIDBRICK = 7, DOOR = 8};
enum EFFECT {BOMBS = 0, FLAMES = 1, SPEED = 2, EXITDOOR = 3};

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
