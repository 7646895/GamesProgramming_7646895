//
// Created by Jessica Vilaysak on 20/09/2016.
//
#pragma once
#include <iostream>
#include <vector>
#include "../Player.h"
#include "../GameObject/GameObject.h"
#ifndef COMMANDPATTERN_COMMAND_H
#define COMMANDPATTERN_COMMAND_H
using namespace std;

class Command {
protected:
    vector<string> _identifiers;

public:
    Command();
    //~Command();

    void addIdentifiers(vector<string> ids);
    virtual string run(vector<string> input, Player *p);
    bool containsId(string id);
};


#endif //COMMANDPATTERN_COMMAND_H
