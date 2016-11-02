//
// Created by Jessica Vilaysak on 9/10/2016.
//

#include "Level.h"

Level::Level()
{
    _id = "level";
    _level = 1;
}

void Level::update(GamePoints *p, Damage* d)
{
    int points = p->getPoints();
    int level = points/20;
    if(level > _level)
    {
        _level = level;
        d->setDamage(_level);
        cout << "CONGRATS you've levelled up!! \nYou're now at level " <<  _level << ".\nYou can now deal " << _level << " damage.\n";
    }
}