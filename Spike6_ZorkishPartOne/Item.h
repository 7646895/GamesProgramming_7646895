//
// Created by Jessica Vilaysak on 12/09/2016.
//
#pragma once
#include <iostream>
#ifndef ZORKISHPARTONE_ITEM_H
#define ZORKISHPARTONE_ITEM_H
using namespace std;

class Item
{
private:
    string _name;
    string _description;

public:
    Item(string name, string description);
    string getDescription();
    string getName();
};


#endif //ZORKISHPARTONE_ITEM_H
