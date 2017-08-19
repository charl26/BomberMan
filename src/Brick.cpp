//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#include "Brick.hpp"

Brick::Brick() {}

bool Brick::isPowerUp() const {
    return powerUp;
}

void Brick::setPowerUp(bool powerUp) {
    Brick::powerUp = powerUp;
}

Brick::~Brick() {}
