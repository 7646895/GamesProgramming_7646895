//
// Created by Jessica Vilaysak on 25/09/2016.
//
#pragma once
#include "Command.h"
#ifndef COMMANDPATTERN_COMMANDLOOK_H
#define COMMANDPATTERN_COMMANDLOOK_H


class CommandLook : public Command
{
private:


public:
    CommandLook(MessageHandler *msgHandler);

    void run(vector<string> input, Player *p);
};


#endif //COMMANDPATTERN_COMMANDLOOK_H
