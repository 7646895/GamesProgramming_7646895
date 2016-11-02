//
// Created by Jessica Vilaysak on 9/10/2016.
//

#include "Attack.h"

Attack::Attack()
{
    _id = "attack";
}

void Attack::setVector(vector<string> canBeAttackedWith)
{
    _canBeAttackedWith = canBeAttackedWith;
}

vector<string> Attack::getVector()
{
    return _canBeAttackedWith;
}