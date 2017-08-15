//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#include "Explosion.hpp"

Explosion::Explosion(signed short int xRange, signed short int yRange) : xRange(xRange), yRange(yRange) {}

signed short int Explosion::getXRange() const {
    return xRange;
}

void Explosion::setXRange(signed short int xRange) {
    Explosion::xRange = xRange;
}

signed short int Explosion::getYRange() const {
    return yRange;
}

void Explosion::setYRange(signed short int yRange) {
    Explosion::yRange = yRange;
}

Explosion::~Explosion() {}
