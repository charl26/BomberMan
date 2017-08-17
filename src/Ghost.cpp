//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#include "Ghost.hpp"

Ghost::Ghost() {}

Ghost::~Ghost() {}

int Ghost::getSmartness() const {
	return smartness;
}

void Ghost::setSmartness(int smartness) {
	Ghost::smartness = smartness;
}
