//
// Created by Jessica Vilaysak on 12/09/2016.
//

#include "Player.h"
#include "Components/Life.h"
#include "Components/GamePoints.h"
#include "Components/Health.h"
#include "Components/Level.h"
#include "Components/Damage.h"

Player::Player()
{
    _Inventory = new Inventory();
    Life *life = new Life();
    _components.push_back((Component *) life);
    GamePoints *points = new GamePoints();
    points->setPoints(10);
    _components.push_back((Component *) points);
    Level *level = new Level();
    _components.push_back((Component *) level);
    Health *health = new Health();
    health->setHealth(10);
    _components.push_back((Component*)health);
    Damage *damage = new Damage();
    damage->setDamage(1);
    _components.push_back((Component*)damage);
}

void Player::listInv()
{
    if(_Inventory->getCapacity() < 1)
    {
        cout << "There are no items in your inventory!\n";
        return;
    }
    cout << "Listing your inventory...\n";
    _Inventory->listInventory();
}

void Player::setName(string name)
{
    _name = name;
}

void Player::setCurrentLocation(Node *current)
{
    _currentLocation = current;
}

Node* Player::getCurrentLocation()
{
    return _currentLocation;
}

Inventory* Player::getInventoryObject()
{
    return _Inventory;
}

void Player::addComponent(Component* component)
{
    _components.push_back(component);
}

Component* Player::hasComponent(string id)
{
    for(auto i=_components.begin(); i!=_components.end(); i++)
    {
        if((*i)->getId() == id)
        {
            return (*i);
        }
    }
    return 0;
}