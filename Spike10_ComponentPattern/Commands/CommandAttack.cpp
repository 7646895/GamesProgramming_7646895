//
// Created by Jessica Vilaysak on 11/10/2016.
//

#include "CommandAttack.h"


CommandAttack::CommandAttack()
{
    _identifiers.push_back("attack");
    _identifiers.push_back("fight");
}

void CommandAttack::run(vector<string> input, Player *p)
{
    /*
     * 0 - attack
     * 1 - gameObj
     * 2 - with
     * 3 - gameObj
     */
    string monster = input.at(1);
    GameObject* gameObj = p->getCurrentLocation()->getInventoryObject()->getObject(monster);
    if(gameObj == 0)
    {
        cout << "There is no " << monster << " to attack.\n";
        return;
    }
    Attack* attackObj = (Attack*)gameObj->hasComponent("attack");
    if(attackObj == 0)
    {
        cout << "You can't attack this " << monster << ".\n";
        return;
    }

    GamePoints* pPoints = (GamePoints*)p->hasComponent("points");
    Damage* pDamage = (Damage*)p->hasComponent("damage");
    Health* pHealth = (Health*)p->hasComponent("health");
    Health* oHealth = (Health*)gameObj->hasComponent("health");
    //attack OBJ
    if(input.capacity() == 2)
    {
        if(attackVectorContains(attackObj->getVector(), "me"))
        {
            //increase p points by p damage
            pPoints->increasePoints(pDamage->getDamage());
            //decrease p health by p damage
            pHealth->decreaseHealth(pDamage->getDamage());
            //gameObj health decreases by p damage
            oHealth->decreaseHealth(pDamage->getDamage());
            cout << "You've attacked the " << monster << "!\n";
        }
        else
        {
            //p health decreases by obj damage
            pHealth->decreaseHealth(oHealth->getHealth());
            canAttackWith(attackObj->getVector(), monster);
            cout << "Oh no the " << monster << " retaliated! \n";
        }
    }
    //attack OBJ with ITEM
    if(input.capacity() == 4)
    {
        string item = input.at(3);
        //player must have item in inventory
        GameObject* itemObj = p->getInventoryObject()->getObject(item);
        if (itemObj == 0)
        {
            cout << "That item isn't in your inventory! ";
            //if item isn't in p inventory, p still attacks obj but with "me"
            if(attackVectorContains(attackObj->getVector(), "me"))
            {
                //increase p points by p damage
                pPoints->increasePoints(pDamage->getDamage());
                //decrease p health by p damage
                pHealth->decreaseHealth(pDamage->getDamage());
                //gameObj health decreases by p damage
                oHealth->decreaseHealth(pDamage->getDamage());
                cout << "But you were still able to attack the " << monster << "! \n";
            }
            else
            {
                //p health decreases by obj damage
                pHealth->decreaseHealth(oHealth->getHealth());
                canAttackWith(attackObj->getVector(), monster);
                cout << "The monster retaliated!\n";
            }
        }
        else
        {
            if(attackVectorContains(attackObj->getVector(), item))
            {
                //increase p points by p damage
                pPoints->increasePoints(pDamage->getDamage());
                //decrease p health by p damage
                pHealth->decreaseHealth(pDamage->getDamage());
                //gameObj health decreases by p damage
                oHealth->decreaseHealth(pDamage->getDamage());
                cout << "You attacked the " << monster << " with your " << item << "!\n";
            }
            else
            {

                canAttackWith(attackObj->getVector(), monster);
                //p health decreases by obj damage
                pHealth->decreaseHealth(oHealth->getHealth());
                cout << "The monster retaliated and hurt you! You can't attack the " << monster << " with a " << item << ".\n";

            }
        }
    }
    displayStats(pHealth, pPoints);
    if(oHealth->getHealth() == 0)
    {
        //monster has DIED
        cout << "DEAD. The " << monster << " is dead.\n";
        p->getCurrentLocation()->getInventoryObject()->removeInventoryObject(monster);
    }
    return;
}

void CommandAttack::canAttackWith(vector<string> with, string monster)
{
    cout << "You can only attack the " << monster << " with: ";
    vector<string> attackWith = with;
    for(auto i=attackWith.begin(); i!=attackWith.end(); i++)
    {
        cout << (*i) << ", ";
    }
    cout << ".\n";
}

bool CommandAttack::attackVectorContains(vector<string> v, string id)
{
    for(auto i=v.begin(); i!=v.end(); i++)
    {
        if((*i) == id)
            return true;
    }
    return false;
}

void CommandAttack::displayStats(Health* h, GamePoints* p)
{
    cout << "Your stats:\n";
    cout << " health: " << h->getHealth() << endl;
    cout << " points: " << p->getPoints() << endl;
}