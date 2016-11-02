//
// Created by Jessica Vilaysak on 24/09/2016.
//
#pragma once
#include "Command.h"
#ifndef COMMANDPATTERN_COMMANDGO_H
#define COMMANDPATTERN_COMMANDGO_H


class CommandGo : public Command
{
private:

public:
    CommandGo();

    void run(vector<string> input, Player *p);

};


#endif //COMMANDPATTERN_COMMANDGO_H
