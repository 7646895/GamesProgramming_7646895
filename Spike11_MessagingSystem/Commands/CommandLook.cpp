//
// Created by Jessica Vilaysak on 25/09/2016.
//

#include "CommandLook.h"
#include "../Components/Attack.h"
#include "../Components/Damage.h"
#include "../Components/Health.h"

CommandLook::CommandLook(MessageHandler *msgHandler)
{
    _identifiers.push_back("look");
    _identifiers.push_back("see");
}

void CommandLook::run(vector<string> input, Player *p)
{
    if(input.capacity() == 1)
    {
        p->getCurrentLocation()->printDescription();
        return;
    }
    if(input.at(1) == "at")
    {
        if(input.at(2) == "inventory")
        {
            p->listInv();
            return;
        }

        if(input.at(2) == "me")
        {
            cout << "You are at the " << p->getCurrentLocation()->getName() << endl;
            p->listInv();
            return;
        }
        if((p->getInventoryObject()->getObject(input.at(2)) == 0) && (p->getCurrentLocation()->getInventoryObject()->getObject(input.at(2)) == 0))
        {
            cout << "Invalid command: Couldn't find item - " << input.at(2) << endl;
            return;
        }
        GameObject* object;
        if(p->getInventoryObject()->getObject(input.at(2)) != 0)
            object = p->getInventoryObject()->getObject(input.at(2));
        if(p->getCurrentLocation()->getInventoryObject()->getObject(input.at(2)) != 0)
            object = p->getCurrentLocation()->getInventoryObject()->getObject(input.at(2));

        string output = object->getName() + ": " + object->getDescription();
        Attack* attackObj = (Attack*)object->hasComponent("attack");
        if(attackObj != 0)
        {
            //damage and health
            Damage* damageObj = (Damage*)object->hasComponent("damage");
            Health* healthObj = (Health*)object->hasComponent("health");
            cout << output;
            cout << "\nStats: \n";
            cout << " damage: " << damageObj->getDamage() << endl;
            cout << " health: " << healthObj->getHealth() << endl;
            return;
        }

        Container* containerObj = (Container*)object->hasComponent("container");
        Open* openObj = (Open*)object->hasComponent("open");

        if((containerObj != 0) && (openObj != 0))
        {
            if(openObj->isOpen())
            {
                if(containerObj->getInventoryObject()->getCapacity() == 0)
                {
                    cout << output << endl;
                    return;
                }
                output += ". The " + object->getName() + " contains: ";
                vector<GameObject*> inventory = containerObj->getInventoryObject()->getInventory();
                for(auto i=inventory.begin(); i!=inventory.end(); i++)
                {
                    if(i!=inventory.begin())
                        output += ", ";
                    output += (*i)->getName();
                }
                output += ".";
                cout << output << endl;
                return;
            }
        }
        cout << output << endl;
    }
}


