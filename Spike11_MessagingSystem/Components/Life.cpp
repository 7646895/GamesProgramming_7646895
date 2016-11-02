//
// Created by Jessica Vilaysak on 9/10/2016.
//

#include "Life.h"

Life::Life()
{
    _id = "life";
    _lives = 3;
}

void Life::decrease()
{
    _lives--;
}

void Life::increase()
{
    _lives++;
}

int Life::getNumLives()
{
    return _lives;
}
