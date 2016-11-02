//
// Created by Jessica Vilaysak on 9/10/2016.
//

#include "Damage.h"

Damage::Damage()
{
    _id = "damage";
}

void Damage::setDamage(int damage)
{
    _damage = damage;
}

int Damage::getDamage()
{
    return _damage;
}