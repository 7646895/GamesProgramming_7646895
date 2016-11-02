//
// Created by Jessica Vilaysak on 30/08/2016.
//
#pragma once
#include "State.h"

#ifndef ZORKISHPARTONE_STATESELECTWORLD_H
#define ZORKISHPARTONE_STATESELECTWORLD_H


class StateSelectworld : public State
{
private:
    string _world;
public:
    StateSelectworld();
    State* commenceState();
    int validateWorld(string input);
};


#endif //ZORKISHPARTONE_STATESELECTWORLD_H
