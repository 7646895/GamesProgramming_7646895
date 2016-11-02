//
// Created by Jessica Vilaysak on 25/09/2016.
//

#include "CommandLook.h"

CommandLook::CommandLook()
{
    _identifiers.push_back("look");
    _identifiers.push_back("see");
}

void CommandLook::run(vector<string> input, Player *p)
{
    if(input.capacity() == 1)
    {
        p->getCurrentLocation()->printInvDescription();
        return;
    }
    if(input.at(1) == "at")
    {
        if(input.at(2) == "inventory")
        {
            p->listInventory();
            return;
        }

        if(input.at(2) == "me")
        {
            cout << "You are at the " << p->getCurrentLocation()->getName() << endl;
            p->listInventory();
            return;
        }
        Item* item = p->getItem(input.at(2));
        if(item == 0)
        {
            cout << "Invalid command: Couldn't find item - " << input.at(2) << endl;
            return;
        }
        cout << item->getName() << ": " << item->getDescription() << endl;
    }
}


