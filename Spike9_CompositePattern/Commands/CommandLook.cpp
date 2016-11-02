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
        if((p->getObject(input.at(2)) == 0) && (p->getCurrentLocation()->getObject(input.at(2)) == 0))
        {
            cout << "Invalid command: Couldn't find item - " << input.at(2) << endl;
            return;
        }
        GameObject* object;
        if(p->getObject(input.at(2)) != 0)
            object = p->getObject(input.at(2));
        if(p->getCurrentLocation()->getObject(input.at(2)) != 0)
            object = p->getCurrentLocation()->getObject(input.at(2));
        if(!object->isContainer())
            cout << object->getName() << ": " << object->getDescription() << endl;
        else
        {
            Container* container = (Container*)object;
            cout << container->getName() << ": " << container->getDescription() << endl;
        }
        return;


    }
}


