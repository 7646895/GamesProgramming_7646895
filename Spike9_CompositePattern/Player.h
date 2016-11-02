//
// Created by Jessica Vilaysak on 12/09/2016.
//
#pragma once
#include "Node.h"
#include "HaveInventory.h"
#ifndef ZORKISHPARTONE_PLAYER_H
#define ZORKISHPARTONE_PLAYER_H


class Player : public HaveInventory
{
private:
    string _name;
    Node* _currentLocation;

public:
    Player();
    //~Player();
    void setName(string name);
    void listInventory();
    void setCurrentLocation(Node* current);
    Node* getCurrentLocation();
};


#endif //ZORKISHPARTONE_PLAYER_H
