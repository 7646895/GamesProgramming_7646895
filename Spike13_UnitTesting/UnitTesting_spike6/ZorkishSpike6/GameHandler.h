//
// Created by Jessica Vilaysak on 28/08/2016.
//
#pragma once
#include <vector>
#include "State.h"
#include "StateAbout.h"
#include "StateExit.h"
#include "StateGameplay.h"
#include "StateHallOfFame.h"
#include "StateHelp.h"
#include "StateHighscore.h"
#include "StateMenu.h"
#include "StateSelectworld.h"
#include "GameObject.h"
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
