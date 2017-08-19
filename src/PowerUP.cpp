//
// Created by Charl THERON on 2017/08/15.
//

#include "PowerUP.hpp"

PowerUP::~PowerUP() {}

PowerUP::PowerUP() {}

Effect PowerUP::getEffect() const {
    return effect;
}

void PowerUP::setEffect(Effect effect) {
    PowerUP::effect = effect;
}
