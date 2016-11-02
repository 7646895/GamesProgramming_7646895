//
// Created by Jessica Vilaysak on 30/08/2016.
//

#include "StateExit.h"

StateExit::StateExit()
{
    _name = "exit";
}

State* StateExit::commenceState()
{
    return this;
}