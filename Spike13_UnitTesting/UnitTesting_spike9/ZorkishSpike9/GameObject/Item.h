//
// Created by Jessica Vilaysak on 12/09/2016.
//
#pragma once
#include "GameObject.h"
#include <iostream>
#ifndef ZORKISHPARTONE_ITEM_H
#define ZORKISHPARTONE_ITEM_H

class Item : public GameObject
{
private:

public:
    Item();
    Item(string name, string description, string locationDescription, bool take);
    bool canTake();
};


#endif //ZORKISHPARTONE_ITEM_H
