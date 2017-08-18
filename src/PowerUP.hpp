//
// Created by Charl THERON on 2017/08/15.
//

#ifndef BOMBERMAN_POWERUP_HPP
#define BOMBERMAN_POWERUP_HPP


#include "AbstractEntity.hpp"

class PowerUP : public AbstractEntity {
private:
	Effect effect;

public:
    PowerUP();

	~PowerUP() override;

	Effect getEffect() const;

	void setEffect(Effect effect);
};

#endif
