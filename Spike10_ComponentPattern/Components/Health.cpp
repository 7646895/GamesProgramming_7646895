//
// Created by Jessica Vilaysak on 11/10/2016.
//

#include "Health.h"

Health::Health()
{
    _id = "health";
}

void Health::decreaseHealth(int n)
{
    _health -= n;
}

int Health::getHealth()
{
    return _health;
}

void Health::increaseHealth(int n)
{
    _health += n;
}

void Health::setHealth(int n)
{
    _health = n;
}