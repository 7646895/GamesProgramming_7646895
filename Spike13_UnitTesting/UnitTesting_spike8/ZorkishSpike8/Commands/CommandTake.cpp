//
// Created by Jessica Vilaysak on 25/09/2016.
//

#include "CommandTake.h"


CommandTake::CommandTake()
{
    _identifiers.push_back("take");
}

string CommandTake::run(vector<string> input, Player *p)
{
    string output;
    if(input.capacity() == 2)
    {
        string itemName = input.at(1);
        Item* item = p->getCurrentLocation()->getItem(itemName);
        if(item != 0)
        {
            p->addInventoryItem(item);
            p->getCurrentLocation()->removeInventoryItem(itemName);
            output = "The " + itemName + " has been added to your inventory!\n";
        }
        else
        {
            output = "There is no " + itemName +"\n";
        }
        return output;
    }
}