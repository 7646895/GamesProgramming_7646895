//
// Created by Jessica Vilaysak on 9/10/2016.
//
#pragma once
#include "Component.h"
#include "GamePoints.h"
#include "Damage.h"
#ifndef COMPONENTPATTERN_LEVEL_H
#define COMPONENTPATTERN_LEVEL_H


class Level : public Component
{
private:
    int _level;

public:
    Level();
    void update(GamePoints* p, Damage* d);

};


#endif //COMPONENTPATTERN_LEVEL_H
