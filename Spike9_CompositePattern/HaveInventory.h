//
// Created by Jessica Vilaysak on 3/10/2016.
//
#pragma once
#include <iostream>
#include <vector>
#include "GameObject/GameObject.h"
#ifndef COMPOSITEPATTERNTEST_HAVEINVENTORY_H
#define COMPOSITEPATTERNTEST_HAVEINVENTORY_H
using namespace std;

class HaveInventory
{
protected:
    vector<GameObject*> _inventory;

public:
    HaveInventory();
    void setInventory(vector<GameObject*> inventory);
    void addInventoryObject(GameObject* object);
    void removeInventoryObject(string name);
    GameObject* getObject(string name);
};


#endif //COMPOSITEPATTERNTEST_HAVEINVENTORY_H
