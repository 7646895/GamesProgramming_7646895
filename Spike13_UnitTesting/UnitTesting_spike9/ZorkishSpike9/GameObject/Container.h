//
// Created by Jessica Vilaysak on 3/10/2016.
//
#pragma once
#include "GameObject.h"
#ifndef COMPOSITEPATTERNTEST_CONTAINER_H
#define COMPOSITEPATTERNTEST_CONTAINER_H

class Container : public GameObject
{
private:
    bool _isOpen;
    vector<string> _openWith;
    vector<GameObject*> _inventory;

public:
    Container();
    Container(string name, string description, string locationDescription, bool take);
    string getDescription();
    bool canOpenWith(string item);
    void openContainer();
    GameObject* doesContain(string name);
    void setOpenWith(vector<string> openWith);
    string getOpenWith();

    void setInventory(vector<GameObject*> inventory);
    void addInventoryObject(GameObject* object);
    void removeInventoryObject(string name);
    GameObject* getObject(string name);
    string getLocationDescription();
    bool isOpen();
};


#endif //COMPOSITEPATTERNTEST_CONTAINER_H
