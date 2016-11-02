//
// Created by Jessica Vilaysak on 28/08/2016.
//

#include "State.h"
#include "StateMenu.h"

State::State() {}

string State::commenceState()
{
    return "default";
}

string State::getStateName()
{
    return _name;
}