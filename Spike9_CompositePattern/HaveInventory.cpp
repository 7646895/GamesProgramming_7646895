//
// Created by Jessica Vilaysak on 3/10/2016.
//

#include "HaveInventory.h"

HaveInventory::HaveInventory()
{

}

void HaveInventory::setInventory(vector<GameObject*> inventory)
{
    _inventory = inventory;
}

void HaveInventory::addInventoryObject(GameObject* object)
{
    _inventory.push_back(object);


}

void HaveInventory::removeInventoryObject(string name)
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

GameObject* HaveInventory::getObject(string name)
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