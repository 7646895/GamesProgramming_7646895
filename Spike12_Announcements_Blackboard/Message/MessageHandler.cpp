//
// Created by Jessica Vilaysak on 14/10/2016.
//

#include "MessageHandler.h"
#include "../Components/Component.h"
#include "../Components/Health.h"

MessageHandler::MessageHandler()
{
    _msgTypes.push_back("health");
    _numAttacks = 0;
    _viewedRecent = false;
}

void MessageHandler::sendMessages(Message *m, string type, vector<string> receivers)
{
    if(type == "health")
    {
        HealthMessage *hMsg = (HealthMessage*)m;
        for(auto i=receivers.begin(); i!=receivers.end(); i++)
        {
            Health *h;
            string output;
            if((*i) == "player")
            {
                Component *cPlayer = _player->hasComponent("health");
                h = (Health*)cPlayer;
                output = "Player's health ";
            }
            else
            {
                GameObject *gObj = findGameObject((*i));
                output = gObj->getName() + "'s health ";
                Component *cGame = gObj->hasComponent("health");
                h = (Health*)cGame;
            }
            int effect = hMsg->getEffect();
            if(effect > 0)
            {

                output += "has increased by ";
                h->increaseHealth(effect);
                cout << output << effect << endl;
            }
            else
            {
                output += "has decreased by ";
                h->decreaseHealth(effect*-1);
                cout << output << (effect*-1) << endl;
            }
        }
        return;
    }
}

GameObject* MessageHandler::findGameObject(string name)
{
    for(auto i=_receivers.begin(); i!=_receivers.end(); i++)
    {
        if((*i)->getName() == name)
            return (*i);
    }
    return 0;
}

Node* MessageHandler::findLocation(string name)
{
    for(auto i=_locations.begin(); i!=_locations.end(); i++)
    {
        if(name == (*i)->getName())
            return (*i);
    }
    return 0;
}

void MessageHandler::addReceiver(GameObject *g)
{
    _receivers.push_back(g);
}

void MessageHandler::setDefaultObjects(vector<Node *> l, Player *p)
{
    _locations = l;
    _player = p;
}

int MessageHandler::sendMoveAnnouncement(Message *m, string type, vector<string> receivers)
{
    if(type == "move")
    {
        MoveObjectMessage *moMsg = (MoveObjectMessage*)m;
        int count = 0;
        for(auto i=receivers.begin(); i!=receivers.end(); i++)
        {
            GameObject *g = findGameObject((*i));
            _player->getInventoryObject()->addInventoryObject(g);
            _player->getCurrentLocation()->getInventoryObject()->removeInventoryObject((*i));
            count++;
        }
        cout << "You've obtained all the objects at " << _player->getCurrentLocation()->getName() << endl;
        return (count * moMsg->getPoints());
    }
}

void MessageHandler::updateBlackboard()
{
    _numAttacks++;
    _viewedRecent = false;
}

int MessageHandler::viewBlackboard()
{
    _viewedRecent = true;
    return _numAttacks;
}