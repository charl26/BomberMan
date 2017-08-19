//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#ifndef BOMBERMAN_ABSTRACTENTITY_H
#define BOMBERMAN_ABSTRACTENTITY_H

#include <vector>

enum Animation {BOMBANIM = 1, EXPLODEANIM = 2, POWERANIM = 3, PLAYERANIM = 4, GHOSTANIM = 5, BRICKANIM = 6};
enum Type {EMPTYTILE = 0, PLAYER = 1, GHOST = 2, BOMB = 3, EXPLOSION = 4, BRICK = 5, BRICKWITHPWR = 6, SOLIDBRICK = 7, DOOR = 8, BOMBCOUNTPWR = 9, FLAMESIZEPWR = 10, PLAYERSPEEDPWR = 11};
enum Effect {PIERCEBOMB = 1, POWERBOMB = 2, SOFTBLOCKPASS = 3, BOMBPASS = 4, NEXTLEVEL = 5, BOMCOUNTINC = 6, FLAMESIZEINC = 7, PLAYERSPEEDINC = 8};
enum Direction {UP = 1, DOWN = 2, LEFT = 3, RIGHT = 4};

class AbstractEntity {
private:
    signed short int    xPos;
    signed short int    yPos;
    std::vector<Effect> activeEffects;
    Animation           animation;
    Type                type;

public:
    AbstractEntity();

    short getXPos() const;

    void setXPos(short xPos);

    short getYPos() const;

    void setYPos(short yPos);

    const std::vector<Effect> &getActiveEffects() const;

    void setActiveEffects(const std::vector<Effect> &activeEffects);

    Animation getAnimation() const;

    void setAnimation(Animation animation);

    Type getType() const;

    void setType(Type type);

    virtual ~AbstractEntity();
};

#endif //BOMBERMAN_ABSTRACTENTITY_H
