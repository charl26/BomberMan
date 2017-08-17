//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#include "AbstractEntity.hpp"

AbstractEntity::AbstractEntity() {}

short AbstractEntity::getXPos() const { return xPos; }

void AbstractEntity::setXPos(short xPos) { AbstractEntity::xPos = xPos; }

short AbstractEntity::getYPos() const { return yPos; }

void AbstractEntity::setYPos(short yPos) { AbstractEntity::yPos = yPos; }

std::vector<Effect> AbstractEntity::getActiveEffects() const {
    return activeEffects;
}

void AbstractEntity::setActiveEffects(std::vector<Effect> &activeEffects) {
    AbstractEntity::activeEffects = activeEffects;
}

Animation AbstractEntity::getAnimation() const { return animation; }

void AbstractEntity::setAnimation(Animation animation) { AbstractEntity::animation = animation; }

Type AbstractEntity::getType() const { return type; }

void AbstractEntity::setType(Type type) { AbstractEntity::type = type; }

AbstractEntity::~AbstractEntity() {}
