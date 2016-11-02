//
// Created by Jessica Vilaysak on 12/09/2016.
//
#pragma once
#include <iostream>
#include <vector>
#include "../Components/Component.h"
#include "../Components/Container.h"
#include "../Components/Open.h"
#ifndef ZORKISHPARTONE_GAMEOBJECT_H
#define ZORKISHPARTONE_GAMEOBJECT_H
//using namespace std;
class Inventory;
class GameObject {
protected:
    string _name;
    string _description;
    vector<string> _identifiers;
    vector<Component*> _components;

public:
    GameObject();
    GameObject(string name, vector<string> ids, string description, vector<Component*> components);

    string getName();
    virtual string getDescription();
    bool hasIdentifier(string id);
    bool isContainer();

    void addComponent(Component* component);
    Component* hasComponent(string id);

};


#endif //ZORKISHPARTONE_GAMEOBJECT_H
