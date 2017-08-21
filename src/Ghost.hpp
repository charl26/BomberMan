//
// Created by Franco SCHEEPERS on 2017/08/15.
//

#ifndef BOMBERMAN_GHOST_H
#define BOMBERMAN_GHOST_H

#include "AbstractEntity.hpp"

class Ghost : public AbstractEntity {
private:
	int smartness;
public:
    Ghost();

    virtual ~Ghost();

	int getSmartness() const;

	void setSmartness(int smartness);
};

#endif //BOMBERMAN_GHOST_H
