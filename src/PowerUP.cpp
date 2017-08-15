//
// Created by Charl THERON on 2017/08/15.
//

#include "PowerUP.hpp"

PowerUP::~PowerUP() {

}

PowerUP::PowerUP() {}

EFFECT PowerUP::getEffect() const {
	return effect;
}

void PowerUP::setEffect(EFFECT effect) {
	PowerUP::effect = effect;
}
