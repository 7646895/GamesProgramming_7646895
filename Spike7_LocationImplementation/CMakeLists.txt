cmake_minimum_required(VERSION 3.5)
project(LocationImplementation)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp GameHandler.cpp GameHandler.h State.cpp State.h StateMenu.cpp StateMenu.h StateAbout.cpp StateAbout.h StateExit.cpp StateExit.h StateHelp.cpp StateHelp.h StateGameplay.cpp StateGameplay.h StateSelectworld.cpp StateSelectworld.h StateHighscore.cpp StateHighscore.h StateHallOfFame.cpp StateHallOfFame.h GameObject.cpp GameObject.h Item.cpp Item.h Player.cpp Player.h Graph.cpp Graph.h Node.cpp Node.h Edge.cpp Edge.h)
add_executable(LocationImplementation ${SOURCE_FILES})