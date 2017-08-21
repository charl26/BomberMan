cmake_minimum_required(VERSION 3.8)
project(BomberMan)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES
		src/AbstractEntity.cpp
		src/AbstractEntity.hpp
		src/Bomb.cpp
		src/Bomb.hpp
		src/Bomberman.cpp
		src/Bomberman.hpp
		src/Brick.cpp
		src/Brick.hpp
		src/EventManager.cpp
		src/EventManager.hpp
		src/Explosion.cpp
		src/Explosion.hpp
		src/FrancoTest.cpp
		src/Ghost.cpp
		src/Ghost.hpp
		src/LogicManager.cpp
		src/LogicManager.hpp
		src/main.cpp
		src/PowerUP.cpp
		src/PowerUP.hpp
		src/LogicMangerTests.cpp)

add_executable(BomberMan ${SOURCE_FILES})