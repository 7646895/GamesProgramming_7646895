//
// Created by Jessica Vilaysak on 28/08/2016.
//
#pragma once
#include <vector>
#include "States/State.h"
#include "States/StateAbout.h"
#include "States/StateExit.h"
#include "States/StateGameplay.h"
#include "States/StateHallOfFame.h"
#include "States/StateHelp.h"
#include "States/StateHighscore.h"
#include "States/StateMenu.h"
#include "States/StateSelectworld.h"
#include "GameObject/GameObject.h"
#ifndef ZORKISHPARTONE_GAMEHANDLER_H
#define ZORKISHPARTONE_GAMEHANDLER_H


class GameHandler {
private:
    vector<State*> _stateVector;
    State *_currentState;
    Player *_player;

public:
    GameHandler();
    ~GameHandler();
    void startGame();
    State* getState(string name);
};


#endif //ZORKISHPARTONE_GAMEHANDLER_H
