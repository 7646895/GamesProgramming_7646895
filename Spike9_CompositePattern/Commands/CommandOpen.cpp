//
// Created by Jessica Vilaysak on 4/10/2016.
//

#include "CommandOpen.h"
#include "../GameObject/Container.h"

CommandOpen::CommandOpen()
{
    _identifiers.push_back("open");
}

void CommandOpen::run(vector<string> input, Player *p)
{
    /*
     * open [container]
     *
     * open [container] with [item]
     */
    string containerName = input.at(1);
    //check if 1 is an object
    GameObject* object = p->getObject(containerName);
    if(object == 0)
    {
        cout << containerName << " is not in your inventory.\n";
        return;
    }
    //check if 1 is a container
    if(!object->isContainer())
    {
        cout << containerName << " is not a container so can't be opened.\n";
        return;
    }
    Container* container = (Container*)object;
    if(input.capacity() == 2)
    {
        //can container be opened by 'me'?
        if(!container->canOpenWith("me"))
        {
            cout << "Oh noo, you can only open this container with the following:\n" << container->getOpenWith();
        }
        else
        {
            container->openContainer();
            cout << "You've opened the " << containerName << "\n";
        }
        return;
    }
    string itemName = input.at(3);
    if(input.capacity() == 4)
    {
        if(!container->canOpenWith(itemName))
        {
            cout << "oh noo, you can only open this container with the following:\n" << container->getOpenWith();
            return;
        }
        if(p->getObject(itemName) != 0)
        {
            container->openContainer();
            cout << "You've opened the " << containerName << " with the " << itemName << endl;
        }
        else
        {
            cout << "You don't have a " << itemName << " to open the " << containerName << " with.\n";
        }
        return;
    }
}