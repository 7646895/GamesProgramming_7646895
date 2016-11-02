//
// Created by Jessica Vilaysak on 9/10/2016.
//
#pragma once
#include "Component.h"
#ifndef COMPONENTPATTERN_CONTAINER_H
#define COMPONENTPATTERN_CONTAINER_H
class Inventory;
class Container : public Component
{
private:
    Inventory* _Inventory;

public:
    Container();
    Inventory* getInventoryObject();
    void setInventoryObject(Inventory* inv);
};


#endif //COMPONENTPATTERN_CONTAINER_H
