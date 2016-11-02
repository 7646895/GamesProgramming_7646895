//
// Created by Jessica Vilaysak on 25/09/2016.
//

#include "CommandLook.h"
#include "../GameObject/Container.h"

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
            output = "You are at the " + p->getCurrentLocation()->getName() + "\n";
            output += p->listInventory();
            return output;
        }
        if((p->getObject(input.at(2)) == 0) && (p->getCurrentLocation()->getObject(input.at(2)) == 0))
        {
            return "Invalid command: Couldn't find item - " + input.at(2) +"\n";
        }
        GameObject* object;
        if(p->getObject(input.at(2)) != 0)
            object = p->getObject(input.at(2));
        if(p->getCurrentLocation()->getObject(input.at(2)) != 0)
            object = p->getCurrentLocation()->getObject(input.at(2));
        if(!object->isContainer())
            output = object->getName() + ": " + object->getDescription() +"\n";
        else
        {
            Container* container = (Container*)object;
            output = container->getName() + ": " + container->getDescription() +"\n";
        }
        return output;


    }
}


