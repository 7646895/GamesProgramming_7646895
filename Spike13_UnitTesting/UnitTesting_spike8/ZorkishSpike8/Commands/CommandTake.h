//
// Created by Jessica Vilaysak on 25/09/2016.
//
#pragma once
#include "Command.h"
#ifndef COMMANDPATTERN_COMMANDTAKE_H
#define COMMANDPATTERN_COMMANDTAKE_H


class CommandTake : public Command
{
private:


public:
    CommandTake();

    string run(vector<string> input, Player *p);

};


#endif //COMMANDPATTERN_COMMANDTAKE_H
