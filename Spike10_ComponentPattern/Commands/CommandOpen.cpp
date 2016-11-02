//
// Created by Jessica Vilaysak on 4/10/2016.
//

#include "CommandOpen.h"
#include "../Components/Container.h"
#include "../Components/Open.h"

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
    GameObject* gameObj = p->getInventoryObject()->getObject(containerName);
    if(gameObj == 0)
    {
        cout << containerName << " is not in your inventory.\n";
        return;
    }
    //check if 1 is a container
    Container* aContainer = (Container*)gameObj->hasComponent("container");
    if(aContainer == 0)
    {
        cout << containerName << " is not a container so can't be opened.\n";
        return;
    }
    //check if container is open
    Open* aOpen = (Open*)gameObj->hasComponent("open");
    if(aOpen == 0)
    {
        cout << "The " << containerName << " can't be opened.\n";
        return;
    }
    if(aOpen->isOpen())
    {
        cout << containerName << " is already open!\n";
        return;
    }
    if(input.capacity() == 2)
    {
        if(!aOpen->canOpenWith("me"))
        {
            cout << "Oh noo, you can only open this container with the following:\n" << aOpen->getOpenWithVector();
        }
        else
        {
            aOpen->openObject();
            cout << "You've opened the " << containerName << ".\n";
        }
        return;
    }
    string itemName = input.at(3);
    if(input.capacity() == 4)
    {
        if(!aOpen->canOpenWith(itemName))
        {
            cout << "Oh noo, you can only open this container with the following:\n" << aOpen->getOpenWithVector();
            return;
        }
        if(p->getInventoryObject()->getObject(itemName) != 0)
        {
            aOpen->openObject();
            cout << "You've opened the " << containerName << " with the " << itemName << endl;
        }
        else
        {
            cout << "You don't have a " << itemName << " to open the " << containerName << " with.\n";
        }
        return;
    }
}