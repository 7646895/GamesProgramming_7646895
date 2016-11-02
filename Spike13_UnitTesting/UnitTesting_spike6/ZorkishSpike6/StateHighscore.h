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
    StateHighscore();

    void setValues(string world, int score, int moves);
    string commenceState();

};


#endif //ZORKISHPARTONE_STATEHIGHSCORE_H
