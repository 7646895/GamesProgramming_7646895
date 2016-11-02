//
// Created by Jessica Vilaysak on 12/09/2016.
//

#include "Item.h"

Item::Item(string name, string description)
{
    _name = name;
    _description = description;
}

string Item::getDescription()
{
    string output = _name+" ("+_description+") \n";
    return output;
}

string Item::getName()
{
    return _name;
}