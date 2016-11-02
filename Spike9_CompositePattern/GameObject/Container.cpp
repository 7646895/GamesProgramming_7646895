//
// Created by Jessica Vilaysak on 3/10/2016.
//

#include "Container.h"

Container::Container() {}

Container::Container(string name, string description, string locationDescription, bool take)
{
    _name = name;
    _description = description;
    _take = take;
    _isOpen = false;
    _isContainer = true;
    _locationDescription = locationDescription;
}

bool Container::canOpenWith(string item)
{
    for(auto i=_openWith.begin(); i!=_openWith.end(); i++)
    {
        if((*i) == item)
        {
            return true;
        }
    }
    return false;
}

void Container::openContainer()
{
    _isOpen = true;
}

GameObject* Container::doesContain(string name)
{
    GameObject *temp = getObject(name);
    return temp;
}

void Container::setOpenWith(vector<string> openWith)
{
    _openWith = openWith;
}

void Container::setInventory(vector<GameObject *> inventory)
{
    _inventory = inventory;

}

void Container::addInventoryObject(GameObject *object)
{
    _inventory.push_back(object);
}

void Container::removeInventoryObject(string name)
{
    vector<GameObject*> newInv;
    for(auto i=_inventory.begin(); i!=_inventory.end(); i++)
    {
        if((*i)->getName() == name)
        {
            continue;
        }
        newInv.push_back((*i));
    }
    setInventory(newInv);
}

GameObject* Container::getObject(string name)
{
    for(auto i=_inventory.begin(); i!=_inventory.end(); i++)
    {
        if((*i)->hasIdentifier(name))
        {
            return (*i);
        }
    }
    return 0;
}

string Container::getOpenWith()
{
    string output;
    for(auto i=_openWith.begin(); i!=_openWith.end(); i++)
    {
        output += " " + (*i) + "\n";
    }
    return output;
}

string Container::getLocationDescription()
{
    if(_inventory.capacity() == 0)
        return _locationDescription;

    string output = _locationDescription + " The " + _name + " contains: ";
    for(auto i=_inventory.begin(); i!=_inventory.end(); i++)
    {
        if(i!=_inventory.begin())
            output += ", ";
        output += (*i)->getName();
    }
    output += ".";
    return output;
}

bool Container::isOpen()
{
    return _isOpen;
}

string Container::getDescription()
{
    if(_inventory.capacity() == 0)
        return _description;

    string output = _description + ". The " + _name + " contains: ";
    for(auto i=_inventory.begin(); i!=_inventory.end(); i++)
    {
        if(i!=_inventory.begin())
            output += ", ";
        output += (*i)->getName();
    }
    output += ".";
    return output;

}



