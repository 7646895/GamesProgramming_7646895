//
// Created by Jessica Vilaysak on 9/10/2016.
//

#include "Container.h"

Container::Container()
{
    _id = "container";
}

Inventory* Container::getInventoryObject()
{
    return _Inventory;
}

void Container::setInventoryObject(Inventory *inv)
{
    _Inventory = inv;
}