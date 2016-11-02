//
// Created by Jessica Vilaysak on 30/08/2016.
//
#pragma once
#include "State.h"

#ifndef ZORKISHPARTONE_STATEGAMEPLAY_H
#define ZORKISHPARTONE_STATEGAMEPLAY_H


class StateGameplay : public State
{
private:
    string _world;
    string _nextAction;

public:
    StateGameplay(string world);
    State* commenceState();
    void validateAction(string input);
};


#endif //ZORKISHPARTONE_STATEGAMEPLAY_H
