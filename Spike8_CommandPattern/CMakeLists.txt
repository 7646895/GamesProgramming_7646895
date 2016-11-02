cmake_minimum_required(VERSION 3.5)
project(CommandPattern)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp GameHandler.cpp GameHandler.h States/State.cpp States/State.h States/StateMenu.cpp States/StateMenu.h States/StateAbout.cpp States/StateAbout.h States/StateExit.cpp States/StateExit.h States/StateHelp.cpp States/StateHelp.h States/StateGameplay.cpp States/StateGameplay.h States/StateSelectworld.cpp States/StateSelectworld.h States/StateHighscore.cpp States/StateHighscore.h States/StateHallOfFame.cpp States/StateHallOfFame.h GameObject.cpp GameObject.h Item.cpp Item.h Player.cpp Player.h Graph.cpp Graph.h Node.cpp Node.h Edge.cpp Edge.h Commands/Command.cpp Commands/Command.h Commands/CommandController.cpp Commands/CommandController.h Commands/CommandGo.cpp Commands/CommandGo.h Commands/CommandLook.cpp Commands/CommandLook.h Commands/CommandTake.cpp Commands/CommandTake.h Commands/CommandDrop.cpp Commands/CommandDrop.h)
add_executable(CommandPattern ${SOURCE_FILES})