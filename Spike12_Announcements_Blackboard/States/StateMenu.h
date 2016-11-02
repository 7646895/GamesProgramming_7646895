//
// Created by Jessica Vilaysak on 28/08/2016.
//
#pragma once
#include "State.h"
#ifndef ZORKISHPARTONE_STATEMENU_H
#define ZORKISHPARTONE_STATEMENU_H


class StateMenu : public State
{
private:

public:
    StateMenu();
    string commenceState();
    int validateInput(string input);
};


#endif //ZORKISHPARTONE_STATEMENU_H
