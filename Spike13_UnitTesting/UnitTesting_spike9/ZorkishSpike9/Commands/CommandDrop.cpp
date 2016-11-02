//
// Created by Jessica Vilaysak on 25/09/2016.
//

#include "CommandDrop.h"
#include "../GameObject/Container.h"

CommandDrop::CommandDrop()
{
    _identifiers.push_back("drop");
    _identifiers.push_back("put");
}

string CommandDrop::run(vector<string> input, Player *p)
{
    string output;
    if(input.capacity() == 2)
    {
        GameObject* object = p->getObject(input.at(1));
        if(object != 0)
        {
            //take out item from p inventory, add item to location inventory
            p->removeInventoryObject(input.at(1));
            p->getCurrentLocation()->addInventoryObject(object);
            output = "You have dropped your " + input.at(1) +"\n";
        }
        else
        {
            output = "You don't have a " + input.at(1) + " in your inventory..\n";
        }
        return output;
    }
    /*
     * 0 - put
     * 1 - item
     * 2 - in
     * 3 - container
     */
    if(input.capacity() == 4)
    {
        string itemName = input.at(1);
        string containerName = input.at(3);
        //check item is in p inventory
        if(!p->getObject(itemName))
        {
            return "The " + itemName + " isn't in your inventory.\n";
        }
        if((p->getObject(containerName) == 0) && (p->getCurrentLocation()->getObject(containerName) == 0))
        {
            return containerName + " cannot be found.\n";
        }
        Container* lContainer;
        if(p->getObject(containerName) != 0)
            lContainer = (Container*)p->getObject(containerName);
        if(p->getCurrentLocation()->getObject(containerName) != 0)
            lContainer = (Container*)p->getCurrentLocation()->getObject(containerName);

        lContainer->addInventoryObject(p->getObject(itemName));
        p->removeInventoryObject(itemName);
        return "The " + itemName + " has been placed in your " + containerName +"\n";
    }
}