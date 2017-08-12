#!/usr/bin/env bash
git submodule add https://github.com/charl26/BomberMan-Dependencies ;
git submodule init ;
git submodule update ;

brew --version;

if [[ $? == 127 ]]; then
	sh -c "$(curl -fsSL https://raw.githubusercontent.com/Tolsadus/42homebrewfix/master/install.sh)"
fi

sdl-config --cflags;

if [[ $? == 127 ]]; then
	brew install sdl2;
	brew link sdl2;
	brew install sdl2_image;
	brew install sdl2_ttf;
	brew install glew;
fi