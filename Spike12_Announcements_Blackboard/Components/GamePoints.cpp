//
// Created by Jessica Vilaysak on 9/10/2016.
//

#include "GamePoints.h"

GamePoints::GamePoints()
{
    _id = "points";
}

int GamePoints::getPoints()
{
    return _points;
}

void GamePoints::decreasePoints(int n)
{
    _points -= n;
}

void GamePoints::increasePoints(int n)
{
    _points += n;
}

int GamePoints::setPoints(int points)
{
    _points = points;
}