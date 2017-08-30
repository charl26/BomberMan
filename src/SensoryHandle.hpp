//
// Created by Charl THERON on 2017/08/29.
//

#ifndef SensoryHANDLE_HPP
#define SensoryHANDLE_HPP

#include "SensoryManger.hpp"
#include <iostream>

typedef SensoryManger *(*instantiate)();

typedef void        (*unInstantiate)(SensoryManger *);

class SensoryHandle {
protected:
	void *handler;
	unInstantiate uninstantiate;
public:


	SensoryManger *instance;

	void loadLibrary(std::string);

	void *loadSymbol(std::string);
};


#endif
