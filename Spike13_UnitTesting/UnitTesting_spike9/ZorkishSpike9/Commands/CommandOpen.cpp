//
// Created by Jessica Vilaysak on 4/10/2016.
//

#include "CommandOpen.h"
#include "../GameObject/Container.h"

CommandOpen::CommandOpen()
{
    _identifiers.push_back("open");
}

string CommandOpen::run(vector<string> input, Player *p)
{
    /*
     * open [container]
     *
     * open [container] with [item]
     */
    string output;
    string containerName = input.at(1);
    //check if 1 is an object
    GameObject* object = p->getObject(containerName);
    if(object == 0)
    {
        return containerName + " is not in your inventory.\n";
    }
    //check if 1 is a container
    if(!object->isContainer())
    {
        return containerName + " is not a container so can't be opened.\n";
    }
    Container* container = (Container*)object;
    if(input.capacity() == 2)
    {
        //can container be opened by 'me'?
        if(!container->canOpenWith("me"))
        {
            output = "Oh noo, you can only open this container with the following:\n" + container->getOpenWith();
        }
        else
        {
            container->openContainer();
            output = "You've opened the " + containerName + "\n";
        }
        return output;
    }
    string itemName = input.at(3);
    if(input.capacity() == 4)
    {
        if(!container->canOpenWith(itemName))
        {
            return "oh noo, you can only open this container with the following:\n" + container->getOpenWith();
        }
        if(p->getObject(itemName) != 0)
        {
            container->openContainer();
            return "You've opened the " + containerName + " with the " + itemName +"\n";
        }
        else
        {
            return "You don't have a " + itemName + " to open the " + containerName + " with.\n";
        }
    }
}