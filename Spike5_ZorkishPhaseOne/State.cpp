//
// Created by Jessica Vilaysak on 28/08/2016.
//

#include "State.h"
#include "StateMenu.h"

State::State() {}

State* State::commenceState()
{
    State *menu = new StateMenu();
    return menu;
}

string State::getStateName()
{
    return _name;
}