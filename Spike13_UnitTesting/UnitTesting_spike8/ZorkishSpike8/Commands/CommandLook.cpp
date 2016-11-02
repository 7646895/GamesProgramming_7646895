//
// Created by Jessica Vilaysak on 25/09/2016.
//

#include "CommandLook.h"

CommandLook::CommandLook()
{
    _identifiers.push_back("look");
    _identifiers.push_back("see");
}

string CommandLook::run(vector<string> input, Player *p)
{
    string output;
    if(input.capacity() == 1)
    {
        return p->getCurrentLocation()->printInvDescription();
    }
    if(input.at(1) == "at")
    {
        if(input.at(2) == "inventory")
        {
            return p->listInventory();
        }

        if(input.at(2) == "me")
        {
            output = "You are at the " + p->getCurrentLocation()->getName() +"\n";
            output += p->listInventory();
            return output;
        }
        Item* item = p->getItem(input.at(2));
        if(item == 0)
        {
            return "Invalid command: Couldn't find item - " + input.at(2) +"\n";
        }
        output = item->getName() + ": " + item->getDescription() +"\n";
    }
    return output;
}


