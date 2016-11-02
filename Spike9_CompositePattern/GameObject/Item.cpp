//
// Created by Jessica Vilaysak on 12/09/2016.
//

#include "Item.h"

Item::Item() {}

Item::Item(string name, string description, string locationDescription, bool take)
{
    _name = name;
    _description = description;
    _take = take;
    _isContainer = false;
    _locationDescription = locationDescription;
}

bool Item::canTake()
{
    return _take;
}
