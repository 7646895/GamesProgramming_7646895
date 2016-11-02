//
// Created by Jessica Vilaysak on 12/09/2016.
//
#pragma once
#include "GameObject.h"
#ifndef ZORKISHPARTONE_PLAYER_H
#define ZORKISHPARTONE_PLAYER_H


class Player : public GameObject
{
private:

public:
    Player();
   // ~Player();
    void setName(string name);
    void listInventory();
};


#endif //ZORKISHPARTONE_PLAYER_H
