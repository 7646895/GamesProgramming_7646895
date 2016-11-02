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
    int _id;
    string _name;
    string _description;

public:
    GameObject();
    ~GameObject();
    GameObject(string name, string description);

    void setItemVector(vector<Item*> itemsVector);
    virtual void listInventory();
    string getName();
    void addInventoryItem(Item* item);
    void removeInventoryItem(string itemname);
    int getInventoryCount();
    Item* getItem(string name);

};


#endif //ZORKISHPARTONE_GAMEOBJECT_H
