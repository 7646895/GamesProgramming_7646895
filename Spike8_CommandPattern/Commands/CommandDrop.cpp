//
// Created by Jessica Vilaysak on 25/09/2016.
//

#include "CommandDrop.h"

CommandDrop::CommandDrop()
{
    _identifiers.push_back("drop");
}

void CommandDrop::run(vector<string> input, Player *p)
{
    if(input.capacity() == 2)
    {
        Item* item = p->getItem(input.at(1));
        if(item != 0)
        {
            //take out item from p inventory, add item to location inventory
            p->removeInventoryItem(input.at(1));
            p->getCurrentLocation()->addInventoryItem(item);
            cout << "You have dropped your " << input.at(1) << endl;
        }
        else
        {
            cout << "You don't have a " << input.at(1) << " in your inventory..\n";
        }
    }
}