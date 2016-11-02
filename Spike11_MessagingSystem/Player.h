//
// Created by Jessica Vilaysak on 12/09/2016.
//
#pragma once
#include "Node.h"
#include "Components/Inventory.h"
#include "Components/Component.h"
#include "Message/ICanMessage.h"
#ifndef ZORKISHPARTONE_PLAYER_H
#define ZORKISHPARTONE_PLAYER_H

class Player
{
private:
    string _name;
    Node* _currentLocation;
    Inventory* _Inventory;
    vector<Component*> _components;

public:
    Player();
    //~Player();
    void setName(string name);
    void listInv();
    void setCurrentLocation(Node* current);
    Node* getCurrentLocation();
    Inventory* getInventoryObject();

    void addComponent(Component* component);
    Component* hasComponent(string id);
};


#endif //ZORKISHPARTONE_PLAYER_H
