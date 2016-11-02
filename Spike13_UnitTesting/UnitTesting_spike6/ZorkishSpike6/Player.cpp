//
// Created by Jessica Vilaysak on 12/09/2016.
//

#include "Player.h"

Player::Player()
{
}

string Player::listInventory()
{
    if(_itemsVector.capacity() == 0)
    {
        return "There are no items in your inventory!\n";
    }
    string output = "Listing inventory...\n";
    for(auto i=_itemsVector.begin(); i!=_itemsVector.end(); i++)
    {
        string temp = (*i)->getDescription();
        output += "\t"+temp;

    }
    return (output+"\n");
}

void Player::setName(string name)
{
    _id = name;
}