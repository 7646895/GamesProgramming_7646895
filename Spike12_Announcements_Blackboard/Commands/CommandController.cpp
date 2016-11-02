//
// Created by Jessica Vilaysak on 20/09/2016.
//

#include "CommandController.h"
#include "CommandGo.h"
#include "CommandLook.h"
#include "CommandTake.h"
#include "CommandDrop.h"
#include "CommandOpen.h"
#include "CommandAttack.h"

CommandController::CommandController(MessageHandler *msgHandler)
{
    _msgHandler = msgHandler;

    Command *go = new CommandGo(_msgHandler);
    _commands.push_back(go);
    Command *look = new CommandLook(_msgHandler);
    _commands.push_back(look);
    Command *take = new CommandTake(_msgHandler);
    _commands.push_back(take);
    Command *drop = new CommandDrop(_msgHandler);
    _commands.push_back(drop);
    Command *open = new CommandOpen(_msgHandler);
    _commands.push_back(open);
    Command *attack = new CommandAttack(_msgHandler);
    _commands.push_back(attack);
}


int CommandController::run(string input, Player *p)
{
    if(input == "quit")
        return 1;
    if(input == "hiscore")
        return 2;

    string lInput;

    for(int i=0; i<input.length(); i++)
    {
        lInput += tolower(input[i]);
    }

    stringstream ssin(lInput);
    vector<string> vInput;
    string tempInput;

    while (ssin.good())
    {
        ssin >> tempInput;
        vInput.push_back(tempInput);
    }

    if(getCommand(vInput.at(0)) != 0)
    {
        getCommand(vInput.at(0))->run(vInput, p);
        return 0;
    }

    if(vInput.capacity() == 1)
    {
        if(vInput.at(0) == "")
            return 0;
        if(vInput.at(0) == "inventory")
        {
            p->listInv();
            return 0;
        }

        getCommand("go")->run(vInput, p);
    }


    return 0;
}

Command* CommandController::getCommand(string id)
{
    for(auto i=_commands.begin(); i!=_commands.end(); i++)
    {
        if((*i)->containsId(id))
        {
            return (*i);
        }
    }
    return 0;
}