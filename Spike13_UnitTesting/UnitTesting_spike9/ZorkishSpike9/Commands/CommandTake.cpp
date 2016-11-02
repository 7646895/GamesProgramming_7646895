//
// Created by Jessica Vilaysak on 25/09/2016.
//

#include "CommandTake.h"
#include "../GameObject/Container.h"

CommandTake::CommandTake()
{
    _identifiers.push_back("take");
}

string CommandTake::run(vector<string> input, Player *p)
{
    string output;
    if(input.capacity() == 2)
    {
        string objName = input.at(1);
        GameObject* object = p->getCurrentLocation()->getObject(objName);
        if(object != 0)
        {
            p->addInventoryObject(object);
            p->getCurrentLocation()->removeInventoryObject(objName);
            output = "The " + objName + " has been added to your inventory!\n";
        }
        else
        {
            output = "There is no " + objName +"\n";
        }
        return output;
    }
    if(input.capacity() == 4)
    {
        /*
         * 0 - take
         * 1 - object
         * 2 - from
         * 3 - container
         */
        string iObject = input.at(1);
        string iContainer = input.at(3);
        if(input.at(2) != "from")
        {
            return "I don't understand that command.\n";
        }
        //does 3 exist?
        if((p->getCurrentLocation()->getObject(iContainer) == 0) && (p->getObject(iContainer) == 0))
        {
           return (iContainer + "doesn't exist.\n");
        }
        GameObject* container;
        if(p->getCurrentLocation()->getObject(iContainer) != 0)
            container = p->getCurrentLocation()->getObject(iContainer);
        if(p->getObject(iContainer) != 0)
            container = p->getObject(iContainer);
        if(container == 0)
        {
            return iContainer + " doesn't exist in the current location.\n";
        }
        //is 3 a container
        if(!container->isContainer())
        {
            return iContainer + " isn't a container.\n";
        }

        Container* lContainer = (Container*)container;
        //is 3 open?
        if(!lContainer->isOpen())
        {
            return "The " + iContainer + " is not open.\n";
        }
        //does 3 contain 1
        GameObject* object = lContainer->getObject(iObject);
        if(object == 0)
        {
            return "There is no " + iObject + " in the " + iContainer +"\n";
        }

        //take object from container
        p->addInventoryObject(object);
        lContainer->removeInventoryObject(iObject);
        //p->getCurrentLocation()->removeInventoryObject(iObject);
        return "The " + iObject + " from the " + iContainer + " has been added to your inventory!\n";
    }
}