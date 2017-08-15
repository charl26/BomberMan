//
// Created by Charl THERON on 2017/08/15.
//

#ifndef BOMBERMAN_POWERUP_HPP
#define BOMBERMAN_POWERUP_HPP


#include "AbstractEntity.hpp"

class PowerUP : public AbstractEntity {
	EFFECT effect;
public:
	PowerUP();

	~PowerUP() override;

	EFFECT getEffect() const;

	void setEffect(EFFECT effect);
};

#endif
