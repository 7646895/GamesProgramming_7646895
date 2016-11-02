//
// Created by Jessica Vilaysak on 12/09/2016.
//
#pragma once
#include <iostream>
#include <vector>
#include "Item.h"
#ifndef ZORKISHPARTONE_GAMEOBJECT_H
#define ZORKISHPARTONE_GAMEOBJECT_H
using namespace std;

class GameObject {
protected:
    vector<Item*> _itemsVector;
    string _id;

public:
    GameObject();
    ~GameObject();
    GameObject(vector<Item*> itemsVector);

    void setItemVector(vector<Item*> itemsVector);
    virtual void listInventory();
    string getId();
    void addInventoryItem(Item* item);
    void removeInventoryItem(string itemname);
    int getInventoryCount();

};


#endif //ZORKISHPARTONE_GAMEOBJECT_H
