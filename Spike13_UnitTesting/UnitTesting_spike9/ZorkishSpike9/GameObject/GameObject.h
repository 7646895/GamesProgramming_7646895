//
// Created by Jessica Vilaysak on 12/09/2016.
//
#pragma once
#include <iostream>
#include <vector>
#ifndef ZORKISHPARTONE_GAMEOBJECT_H
#define ZORKISHPARTONE_GAMEOBJECT_H
using namespace std;

class GameObject {
protected:
    string _name;
    string _description;
    string _locationDescription;
    vector<string> _identifiers;
    bool _take;
    bool _isContainer;

public:
    GameObject();

    void setIdentifiers(vector<string> identifiers);
    string getName();
    virtual string getDescription();
    bool hasIdentifier(string id);
    bool isContainer();
    virtual string getLocationDescription();
};


#endif //ZORKISHPARTONE_GAMEOBJECT_H
