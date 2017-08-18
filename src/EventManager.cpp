//
// Created by Franco SCHEEPERS on 2017/08/18.
//

#include "EventManager.hpp"
#include <iostream>

/**
 * @brief
 *
 * Opens a map file and stores it in a 2D int array.
 *
 */

EventManager::EventManager() {
    mapFile.open("Test.txt");

    for (int y = 0; y < 20; y++) {
        for (int x = 0; x < 20; x++) {
            mapFile >> map[x][y];
        }
    }

    generateObjects();
}

/**
 * @brief
 *
 * Reads the map then creates and stores objects in their respective lists according to the data found in the map.
 *
 */

void EventManager::generateObjects() {
    int     mapRows;
    int     mapCol;

    mapRows = sizeof(map) / sizeof(map[0]);
    mapCol = sizeof(map[0]) / sizeof(map[0][0]);

    for (int y{}; y < mapCol; y++) {
        for (int x{}; x < mapRows; x++) {
            switch (map[x][y]) {
                case PLAYER: {
                    bomberman = new Bomberman(1, 3, false);
                    std::__1::vector<Effect>     activeEffects = {};

                    bomberman->setType(PLAYER);
                    bomberman->setAnimation(PLAYERANIM);
                    bomberman->setXPos(static_cast<signed short int>(x));
                    bomberman->setYPos(static_cast<signed short int>(y));
                    bomberman->setBombCount(1);
                    bomberman->setActiveEffects(activeEffects);
                    bomberman->setLives(3);
                    bomberman->setRemote(false);
                    bomberman->setXBombRange(3);
                    bomberman->setYBombRange(3);
                    break;
                }
                case GHOST: {
                    auto *ghost = new Ghost();

                    ghost->setXPos(static_cast<signed short int>(x));
                    ghost->setYPos(static_cast<signed short int>(y));
                    ghost->setAnimation(GHOSTANIM);
                    ghost->setType(GHOST);

                    ghosts.push_back(ghost);
                    objects.push_back((AbstractEntity *)ghost);
                    break;
                }
                case BRICK: {
                    auto *brick = new Brick();

                    brick->setXPos(static_cast<signed short int>(x));
                    brick->setYPos(static_cast<signed short int>(y));
                    brick->setAnimation(BRICKANIM);
                    brick->setType(BRICK);
                    brick->setPowerUp(false);

                    bricks.push_back(brick);
                    objects.push_back((AbstractEntity *)brick);
                    break;
                }
                case BRICKWITHPWR: {
                    auto *brick = new Brick();

                    brick->setXPos(static_cast<signed short int>(x));
                    brick->setYPos(static_cast<signed short int>(y));
                    brick->setAnimation(BRICKANIM);
                    brick->setType(BRICKWITHPWR);
                    brick->setPowerUp(true);

                    bricks.push_back(brick);
                    objects.push_back((AbstractEntity *)brick);
                    break;
                }
                case SOLIDBRICK: {
                    auto *brick = new Brick();

                    brick->setXPos(static_cast<signed short int>(x));
                    brick->setYPos(static_cast<signed short int>(y));
                    brick->setAnimation(BRICKANIM);
                    brick->setType(SOLIDBRICK);
                    brick->setPowerUp(false);

                    bricks.push_back(brick);
                    objects.push_back((AbstractEntity *)brick);
                    break;
                }
                case DOOR: {
                    auto *powerup = new PowerUP();

                    powerup->setXPos(static_cast<signed short int>(x));
                    powerup->setYPos(static_cast<signed short int>(y));
                    powerup->setEffect(NEXTLEVEL);
                    powerup->setAnimation(POWERANIM);
                    powerup->setType(DOOR);


                    powerups.push_back(powerup);
                    objects.push_back((AbstractEntity *)powerup);
                    break;
                }
                case BOMBCOUNTPWR: {
                    auto *powerup = new PowerUP();

                    powerup->setXPos(static_cast<signed short int>(x));
                    powerup->setYPos(static_cast<signed short int>(y));
                    powerup->setEffect(BOMCOUNTINC);
                    powerup->setAnimation(POWERANIM);
                    powerup->setType(BOMBCOUNTPWR);


                    powerups.push_back(powerup);
                    objects.push_back((AbstractEntity *)powerup);
                    break;
                }
                case FLAMESIZEPWR: {
                    auto *powerup = new PowerUP();

                    powerup->setXPos(static_cast<signed short int>(x));
                    powerup->setYPos(static_cast<signed short int>(y));
                    powerup->setEffect(FLAMESIZEINC);
                    powerup->setAnimation(POWERANIM);
                    powerup->setType(FLAMESIZEPWR);


                    powerups.push_back(powerup);
                    objects.push_back((AbstractEntity *)powerup);
                    break;
                }
                case PLAYERSPEEDPWR: {
                    auto *powerup = new PowerUP();

                    powerup->setXPos(static_cast<signed short int>(x));
                    powerup->setYPos(static_cast<signed short int>(y));
                    powerup->setEffect(PLAYERSPEEDINC);
                    powerup->setAnimation(POWERANIM);
                    powerup->setType(PLAYERSPEEDPWR);


                    powerups.push_back(powerup);
                    objects.push_back((AbstractEntity *)powerup);
                    break;
                }
                default: {
                    break;
                }
            }
        }
    }
}