//
// Created by Jessica Vilaysak on 3/10/2016.
//

#include "Inventory.h"

Inventory::Inventory()
{
    _id = "inventory";
}

void Inventory::setInventory(vector<GameObject*> inventory)
{
    _inventory = inventory;
}

void Inventory::addInventoryObject(GameObject* object)
{
    _inventory.push_back(object);
}

void Inventory::removeInventoryObject(string name)
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

GameObject* Inventory::getObject(string name)
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

void Inventory::listInventory()
{
    string output;
    for(auto i=_inventory.begin(); i!=_inventory.end(); i++)
    {

        string temp = (*i)->getName() +" ("+(*i)->getDescription()+")\n";
        output += " "+temp;

    }
    cout << output << endl;
}

int Inventory::getCapacity()
{
    int count = 0;
    for(auto i=_inventory.begin(); i!=_inventory.end(); i++)
    {
        if((*i)->getName() != "")
            count++;
    }
    //return _inventory.capacity();
    return count;
}

vector<GameObject*> Inventory::getInventory()
{
    return _inventory;
}