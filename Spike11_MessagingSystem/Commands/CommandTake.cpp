//
// Created by Jessica Vilaysak on 25/09/2016.
//

#include "CommandTake.h"
#include "../Components/Take.h"


CommandTake::CommandTake(MessageHandler *msgHandler)
{
    _msgHandler = msgHandler;
    _identifiers.push_back("take");
}

void CommandTake::run(vector<string> input, Player *p)
{
    if(input.capacity() == 2)
    {
        string objName = input.at(1);
        GameObject* object = p->getCurrentLocation()->getInventoryObject()->getObject(objName);
        if(object != 0)
        {
            Take* takeObj = (Take*)object->hasComponent("take");
            if(takeObj == 0)
            {
                cout << "The " << objName << " cannot be taken!\n";
                return;
            }
            p->getInventoryObject()->addInventoryObject(object);
            p->getCurrentLocation()->getInventoryObject()->removeInventoryObject(objName);
            cout << "The " << objName << " has been added to your inventory!\n";
        }
        else
        {
            if((p->getInventoryObject()->getObject(objName)) != 0)
            {
                cout << "You already have the " << objName << ".\n";
            }
            else
            {
                cout << "There is no " << objName << ".\n";
            }
        }

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
            cout << "I don't understand that command.\n";
            return;
        }
        //does 3 exist?
        if((p->getCurrentLocation()->getInventoryObject()->getObject(iContainer) == 0) && (p->getInventoryObject()->getObject(iContainer) == 0))
        {
            cout << iContainer << "doesn't exist.\n";
        }
        GameObject* gameObj;
        if(p->getCurrentLocation()->getInventoryObject()->getObject(iContainer) != 0)
            gameObj = p->getCurrentLocation()->getInventoryObject()->getObject(iContainer);
        if(p->getInventoryObject()->getObject(iContainer) != 0)
            gameObj = p->getInventoryObject()->getObject(iContainer);
        if(gameObj == 0)
        {
            cout << iContainer << " doesn't exist in the current location.\n";
            return;
        }
        //is 3 a container
        if(gameObj->hasComponent("container") == 0)
        {
            cout << iContainer << " isn't a container.\n";
            return;
        }
        //is 3 open?
        Open* aOpen = (Open*)gameObj->hasComponent("open");
        if(!aOpen->isOpen())
        {
            cout << "The " << iContainer << " is not open.\n";
            return;
        }
        //does 3 contain 1
        Container* aContainer = (Container*)gameObj->hasComponent("container");
        if(aContainer->getInventoryObject()->getObject(iObject) == 0)
        {
            cout << "There is no " << iObject << " in the " << iContainer << endl;
            return;
        }
        GameObject* takeObj = aContainer->getInventoryObject()->getObject(iObject);
        p->getInventoryObject()->addInventoryObject(takeObj);
        aContainer->getInventoryObject()->removeInventoryObject(iObject);
        cout << "The " << iObject << " from the " << iContainer << " has been added to your inventory!\n";
    }
}