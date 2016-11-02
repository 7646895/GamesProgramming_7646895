//
// Created by Jessica Vilaysak on 12/09/2016.
//

#include "Player.h"

Player::Player()
{
}

string Player::listInventory()
{
    if(_inventory.capacity() == 0)
    {
        return "There are no items in your inventory!\n";
    }
    string output = "Listing your inventory...\n";
    for(auto i=_inventory.begin(); i!=_inventory.end(); i++)
    {

        string temp = (*i)->getName() +" ("+(*i)->getDescription()+")\n";
        output += " "+temp;

    }
    return output +"\n";
}

void Player::setName(string name)
{
    _name = name;
}

void Player::setCurrentLocation(Node *current)
{
    _currentLocation = current;
}

Node* Player::getCurrentLocation()
{
    return _currentLocation;
}
