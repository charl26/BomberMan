//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#include "Bomb.hpp"

Bomb::Bomb(signed short int fuseTime) {
	Bomb::fuseTime = fuseTime;
}

signed short int Bomb::getFuseTime() const {
    return fuseTime;
}

void Bomb::setFuseTime(signed short int fuseTime) {
    Bomb::fuseTime = fuseTime;
}

Bomb::~Bomb() {}
