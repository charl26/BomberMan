//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#include "Brick.hpp"

Brick::Brick() : powerUp(powerUp) {
}

bool Brick::hasPowerUp() const {
        return powerUp;
    }

void Brick::setPowerUp(bool powerUp) {
        Brick::powerUp = powerUp;
    }

Brick::~Brick() {}