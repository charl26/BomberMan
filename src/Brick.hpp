//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#ifndef BOMBERMAN_BRICK_H
#define BOMBERMAN_BRICK_H

#include "AbstractEntity.hpp"

class Brick : public AbstractEntity{
    private:
        bool        powerUp;

    public:
        Brick();

        bool hasPowerUp() const;

        void setPowerUp(bool powerUp);

        ~Brick() override;
    };

#endif //BOMBERMAN_BRICK_H
