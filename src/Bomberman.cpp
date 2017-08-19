//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#include "Bomberman.hpp"

short Bomberman::getBombCount() const {
    return bombCount;
}

void Bomberman::setBombCount(short bombCount) {
    Bomberman::bombCount = bombCount;
}

short Bomberman::getLives() const {
    return lives;
}

void Bomberman::setLives(short lives) {
    Bomberman::lives = lives;
}

bool Bomberman::isRemote() const {
    return remote;
}

void Bomberman::setRemote(bool remote) {
    Bomberman::remote = remote;
}

Bomberman::Bomberman(short bombCount, short lives, bool remote) : bombCount(bombCount), lives(lives), remote(remote) {}

Bomberman::~Bomberman() {}

short Bomberman::getXBombRange() const {
    return xBombRange;
}

void Bomberman::setXBombRange(short xBmbRange) {
    Bomberman::xBombRange = xBmbRange;
}

short Bomberman::getYBombRange() const {
    return yBombRange;
}

void Bomberman::setYBombRange(short yBombRange) {
    Bomberman::yBombRange = yBombRange;
}
