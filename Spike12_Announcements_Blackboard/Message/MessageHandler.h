//
// Created by Jessica Vilaysak on 14/10/2016.
//
#pragma once
#include <iostream>
#include <vector>
#include "ICanMessage.h"
#ifndef MESSAGINGSYSTEM_MESSAGEHANDLER_H
#define MESSAGINGSYSTEM_MESSAGEHANDLER_H
using namespace std;

class MessageHandler {
private:
    vector<string> _msgTypes;
    vector<GameObject*> _receivers;
    vector<Node*> _locations;
    Player* _player;
    int _numAttacks;
    bool _viewedRecent;

public:
    MessageHandler();
    void setDefaultObjects(vector<Node*> l, Player* p);
    void sendMessages(Message* m, string type, vector<string> receivers);
    GameObject* findGameObject(string name);
    Node* findLocation(string name);
    void addReceiver(GameObject* g);
    int sendMoveAnnouncement(Message* m, string type, vector<string> receivers);
    void updateBlackboard();
    int viewBlackboard();

};


#endif //MESSAGINGSYSTEM_MESSAGEHANDLER_H
