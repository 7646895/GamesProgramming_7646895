//
// Created by Jessica Vilaysak on 12/09/2016.
//

#include "GameObject.h"

GameObject::GameObject()
{
    _id = "game objecttt";
}

GameObject::~GameObject()
{
    for(auto i=_itemsVector.begin(); i!=_itemsVector.end(); i++)
    {
        delete (*i);
    }
}

GameObject::GameObject(vector<Item *> itemsVector)
{
    _id = "game objecttt";
    _itemsVector = itemsVector;
}

void GameObject::setItemVector(vector<Item *> itemsVector)
{
    _itemsVector = itemsVector;
}

string GameObject::listInventory()
{
    return "listing inventory... NOT\n";
}

string GameObject::getId()
{
    return _id;
}

void GameObject::addInventoryItem(Item *item)
{
    _itemsVector.push_back(item);
}

void GameObject::removeInventoryItem(string itemname)
{
    vector<Item*> newitems;
    for(auto i=_itemsVector.begin(); i!=_itemsVector.end(); i++)
    {
        if((*i)->getName() == itemname)
        {
            continue;
        }
        newitems.push_back(*i);
    }
    setItemVector(newitems);
}

int GameObject::getInventoryCount()
{
    int count = 0;
    for(auto i=_itemsVector.begin(); i!=_itemsVector.end(); i++)
    {
        count++;
    }
    return count;
}