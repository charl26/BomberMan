//
// Created by Charl THERON on 2017/07/25.
//

#include "EventManager.hpp"

void TestDrawEventManagerConstructorObjects();

void TestEventManagerConstructor();

void TestEventManagerConstructorCoordinates();

int main(void) {
    auto eventManager = new EventManager();

    TestDrawEventManagerConstructorObjects();
    TestEventManagerConstructor();
    TestEventManagerConstructorCoordinates();

    delete (eventManager);
    return (0);
}
