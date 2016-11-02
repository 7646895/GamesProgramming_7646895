//
// Created by Jessica Vilaysak on 9/10/2016.
//
#pragma once
#include "Component.h"
#ifndef COMPONENTPATTERN_LIFE_H
#define COMPONENTPATTERN_LIFE_H


class Life : public Component
{
private:
    int _lives;

public:
    Life();
    void decrease();
    void increase();
    int getNumLives();
};


#endif //COMPONENTPATTERN_LIFE_H
