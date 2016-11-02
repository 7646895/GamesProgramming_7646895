//
// Created by Jessica Vilaysak on 12/09/2016.
//
#pragma once
#include "GameObject.h"
#include "Node.h"
#ifndef ZORKISHPARTONE_PLAYER_H
#define ZORKISHPARTONE_PLAYER_H


class Player : public GameObject
{
private:
    Node* _currentLocation;

public:
    Player();
    //~Player();
    void setName(string name);
    string listInventory();
    void setCurrentLocation(Node* current);
    Node* getCurrentLocation();
};


#endif //ZORKISHPARTONE_PLAYER_H
