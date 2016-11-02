//
// Created by Jessica Vilaysak on 31/08/2016.
//
#pragma once
#include "State.h"

#ifndef ZORKISHPARTONE_STATEHIGHSCORE_H
#define ZORKISHPARTONE_STATEHIGHSCORE_H


class StateHighscore : public State
{
private:
    string _world;
    int _score;
    int _moves;

public:
    StateHighscore(string world, int score, int moves);
    State* commenceState();

    void getData();
};


#endif //ZORKISHPARTONE_STATEHIGHSCORE_H
