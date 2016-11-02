//
// Created by Jessica Vilaysak on 25/09/2016.
//

#include "CommandDrop.h"

CommandDrop::CommandDrop()
{
    _identifiers.push_back("drop");
}

string CommandDrop::run(vector<string> input, Player *p)
{
    string output;
    if(input.capacity() == 2)
    {
        Item* item = p->getItem(input.at(1));
        if(item != 0)
        {
            //take out item from p inventory, add item to location inventory
            p->removeInventoryItem(input.at(1));
            p->getCurrentLocation()->addInventoryItem(item);
            output = "You have dropped your " + input.at(1) +"\n";
        }
        else
        {
            output = "You don't have a " + input.at(1) + " in your inventory..\n";
        }
    }
    return output;
}