//
// Created by Jessica Vilaysak on 12/09/2016.
//

#include "GameObject.h"

GameObject::GameObject()
{
    _id = 0;
}

GameObject::~GameObject()
{
    for(auto i=_itemsVector.begin(); i!=_itemsVector.end(); i++)
    {
        delete (*i);
    }
}

GameObject::GameObject(string name, string description)
{
    _name = name;
    _description = description;
}

void GameObject::setItemVector(vector<Item *> itemsVector)
{
    _itemsVector = itemsVector;
}

void GameObject::listInventory()
{
    cout << "listing inventory... NOT\n";
}

string GameObject::getName()
{
    return _name;
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
            delete (*i);
            continue;
        }
        newitems.push_back(*i);
    }
    setItemVector(newitems);
}

int GameObject::getInventoryCount()
{
    return (_itemsVector.capacity());
}