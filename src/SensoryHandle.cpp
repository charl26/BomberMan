//
// Created by Charl THERON on 2017/08/29.
//

#include <dlfcn.h>
#include "SensoryHandle.hpp"


/**
 * @brief binds a function form the Library
 * @param name of the function you wish to access for the dynamic Library
 * @return if found returns a pointer to function
 * @throws SymbolNotFoundException() if the function does not exists
 */

void *SensoryHandle::loadSymbol(const std::string name) {

	const char *dlsymError;
	void *symbol;

	dlerror();
	symbol = dlsym(handler, name.c_str());
	dlsymError = dlerror();

	if (dlsymError != nullptr) {
		throw std::exception();
		//TODO throw SymbolNotFoundException();
	}

	return symbol;
}

/**
 * @brief opens a dynamic Library
 * @param name the name of the Library to open
 */

void SensoryHandle::loadLibrary(std::string name) {
	instantiate instantiate;

	handler = dlopen(name.c_str(), RTLD_NOW);

	if (handler == nullptr) {
		std::cout << dlerror() << std::endl;
		//TODO throw LibraryNotFoundException();
	}

	instantiate = reinterpret_cast<::instantiate>(loadSymbol("createObject"));
	uninstantiate = reinterpret_cast<unInstantiate>(loadSymbol("destroyObject"));
	instance = instantiate();
}
