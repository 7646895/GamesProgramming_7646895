//
// Created by Jessica Vilaysak on 11/10/2016.
//
#pragma once
#include "Command.h"
#include "../Components/Attack.h"
#include "../Components/GamePoints.h"
#include "../Components/Damage.h"
#include "../Components/Health.h"
#include <ostream>
#ifndef COMPONENTPATTERN_COMMANDATTACK_H
#define COMPONENTPATTERN_COMMANDATTACK_H


class CommandAttack : public Command
{
private:
    vector<string> _canBeAttackedWith;

public:
    CommandAttack();

    void run(vector<string> input, Player *p);
    bool attackVectorContains(vector<string> v, string id);
    void canAttackWith(vector<string> with, string monster);
    void displayStats(Health* h, GamePoints* p);
};


#endif //COMPONENTPATTERN_COMMANDATTACK_H
