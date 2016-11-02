//
// Created by Jessica Vilaysak on 25/09/2016.
//
#pragma once
#include "Command.h"
#ifndef COMMANDPATTERN_COMMANDDROP_H
#define COMMANDPATTERN_COMMANDDROP_H


class CommandDrop : public Command
{
private:


public:
    CommandDrop();

    void run(vector<string> input, Player *p);
};


#endif //COMMANDPATTERN_COMMANDDROP_H
