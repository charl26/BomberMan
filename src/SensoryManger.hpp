//
// Created by Charl THERON on 2017/08/29.
//

#ifndef SensoryManger_HPP
#define SensoryManger_HPP

enum moveEvent {
	NoMOVE = 0,
	UP = 1,
	DOWN = 2,
	LEFT = 3,
	RIGHT = 4
};

enum SoundEvent {
	BOMBEXPLODES = 0
};


/**
 * @brief  SensoryManger will be extended by Graphics that will contain
 * the dynamic graphics LIB which will process graphics, audio and KeyHooks
 * @var action will be accessed by the Event Manger to apply the keyHook to Core game
 * @var sound will be accessed by the audio player to player which sound
 */

class SensoryManger {
public:
	moveEvent action;
	SoundEvent sound;

	virtual            ~SensoryManger() = default;

	virtual void update() = 0;
};


#endif
