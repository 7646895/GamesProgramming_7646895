//
// Created by Jessica Vilaysak on 9/10/2016.
//
#pragma once
#include "Component.h"
#ifndef COMPONENTPATTERN_GAMEPOINTS_H
#define COMPONENTPATTERN_GAMEPOINTS_H


class GamePoints : public Component
{
private:
    int _points;

public:
    GamePoints();
    int getPoints();
    int setPoints(int points);
    void decreasePoints(int n);
    void increasePoints(int n);
};


#endif //COMPONENTPATTERN_GAMEPOINTS_H
