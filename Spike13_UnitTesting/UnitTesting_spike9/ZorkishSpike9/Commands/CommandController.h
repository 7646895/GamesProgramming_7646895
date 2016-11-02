//
// Created by Jessica Vilaysak on 20/09/2016.
//
#pragma once
#include "Command.h"
#include "../Player.h"
#include <vector>
#include <sstream>
#ifndef COMMANDPATTERN_COMMANDCONTROLLER_H
#define COMMANDPATTERN_COMMANDCONTROLLER_H


class CommandController {
private:
    vector<Command*> _commands;


public:
    CommandController();
    //~CommandController();

    string run(string input, Player *p);
    Command* getCommand(string id);
};


#endif //COMMANDPATTERN_COMMANDCONTROLLER_H
