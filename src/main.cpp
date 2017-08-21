//
// Created by Charl THERON on 2017/07/25.
//

#include <iostream>
#include "EventManager.hpp"

void TestDrawEventManagerConstructorObjects();

void TestEventManagerConstructor();

void TestEventManagerConstructorCoordinates();

void TestEventManagerPerformCollision();

bool testLogicManger();

int main() {
    auto eventManager = new EventManager();

    TestDrawEventManagerConstructorObjects();
    std::cout << std::endl;
    TestEventManagerConstructor();
    TestEventManagerConstructorCoordinates();
    std::cout << std::endl;
    TestEventManagerPerformCollision();

    testLogicManger();

    delete (eventManager);
    return (0);
}
