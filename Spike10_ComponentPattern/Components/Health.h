//
// Created by Jessica Vilaysak on 11/10/2016.
//
#pragma once
#include "Component.h"
#ifndef COMPONENTPATTERN_HEALTH_H
#define COMPONENTPATTERN_HEALTH_H


class Health : public Component
{
private:
    int _health;

public:
    Health();
    void setHealth(int n);
    int getHealth();
    void increaseHealth(int n);
    void decreaseHealth(int n);
};


#endif //COMPONENTPATTERN_HEALTH_H
