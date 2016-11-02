//
// Created by Jessica Vilaysak on 9/10/2016.
//
#pragma once
#include "Component.h"
#ifndef COMPONENTPATTERN_DAMAGE_H
#define COMPONENTPATTERN_DAMAGE_H


class Damage : public Component
{
private:
    int _damage;

public:
    Damage();
    void setDamage(int damage);
    int getDamage();
};


#endif //COMPONENTPATTERN_DAMAGE_H
