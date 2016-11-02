//
// Created by Jessica Vilaysak on 20/09/2016.
//
#pragma once
#include <iostream>
#include <vector>
#include "../Player.h"
#include "../GameObject/GameObject.h"
#include "../Message/ICanMessage.h"
#include "../Message/MessageHandler.h"
#ifndef COMMANDPATTERN_COMMAND_H
#define COMMANDPATTERN_COMMAND_H
using namespace std;

class Command {
protected:
    vector<string> _identifiers;
    MessageHandler *_msgHandler;

public:
    Command();
    //~Command();

    void addIdentifiers(vector<string> ids);
    virtual void run(vector<string> input, Player *p);
    bool containsId(string id);
    void sendHealthMessage(string type, int effect, vector<string> recipients);
};


#endif //COMMANDPATTERN_COMMAND_H
