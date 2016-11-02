//
// Created by Jessica Vilaysak on 28/08/2016.
//
#pragma once
#include "State.h"
#ifndef ZORKISHPARTONE_GAMEHANDLER_H
#define ZORKISHPARTONE_GAMEHANDLER_H


class GameHandler {
private:
    State *_state;

public:
    GameHandler();
    void startGame();


};


#endif //ZORKISHPARTONE_GAMEHANDLER_H
