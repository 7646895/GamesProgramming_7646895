//
// Created by Jessica Vilaysak on 3/10/2016.
//
#pragma once
#include <iostream>
#include "Component.h"
#include <vector>
#include "../GameObject/GameObject.h"
#ifndef COMPOSITEPATTERNTEST_HAVEINVENTORY_H
#define COMPOSITEPATTERNTEST_HAVEINVENTORY_H

class Inventory : public Component
{
protected:
    vector<GameObject*> _inventory;

public:
    Inventory();
    int getCapacity();
    void setInventory(vector<GameObject*> inventory);
    vector<GameObject*> getInventory();
    void addInventoryObject(GameObject* object);
    void removeInventoryObject(string name);
    GameObject* getObject(string name);
    void listInventory();
};


#endif //COMPOSITEPATTERNTEST_HAVEINVENTORY_H
