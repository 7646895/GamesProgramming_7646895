//
// Created by Jessica Vilaysak on 4/10/2016.
//
#pragma once
#include "Command.h"
#ifndef COMPOSITEPATTERNTEST_COMMANDOPEN_H
#define COMPOSITEPATTERNTEST_COMMANDOPEN_H


class CommandOpen : public Command
{
private:

public:
    CommandOpen(MessageHandler *msgHandler);
    void run(vector<string> input, Player *p);

};


#endif //COMPOSITEPATTERNTEST_COMMANDOPEN_H
