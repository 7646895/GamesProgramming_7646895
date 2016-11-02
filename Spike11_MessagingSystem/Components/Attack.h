//
// Created by Jessica Vilaysak on 9/10/2016.
//
#pragma once
#include "Component.h"

#ifndef COMPONENTPATTERN_ATTACK_H
#define COMPONENTPATTERN_ATTACK_H


class Attack : public Component
{
private:
    vector<string> _canBeAttackedWith;

public:
    Attack();
    void setVector(vector<string> canBeAttackedWith);
    vector<string> getVector();
    void attackObj();
};


#endif //COMPONENTPATTERN_ATTACK_H
