//
// Created by Jessica Vilaysak on 12/09/2016.
//

#include "Player.h"

Player::Player()
{
}

void Player::listInventory()
{
    string output = "Listing inventory...\n";
    for(auto i=_itemsVector.begin(); i!=_itemsVector.end(); i++)
    {
        string temp = (*i)->getDescription();
        output += "\t"+temp;

    }
    cout << output << endl;
}

void Player::setName(string name)
{
    _id = name;
}