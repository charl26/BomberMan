//
// Created by Charl THERON on 2017/07/25.
//

#include <iostream>
#include "EventManager.hpp"

int main(void) {
    std::cout << "Hello World!" << std::endl;
    EventManager *eventManager = new EventManager();
    Bomb *bomb = new Bomb(5);

    bomb->setType(BOMB);
    eventManager->performCollision(*bomb);
    return (0);
}
