//
// Created by Jessica Vilaysak on 27/10/2016.
//
#include "Message.h"
#ifndef MESSAGINGSYSTEM_MOVEOBJECTMESSAGE_H
#define MESSAGINGSYSTEM_MOVEOBJECTMESSAGE_H


class MoveObjectMessage : public Message
{
private:
    int _points;

public:
    MoveObjectMessage();
    MoveObjectMessage(int points);
    int getPoints();
};


#endif //MESSAGINGSYSTEM_MOVEOBJECTMESSAGE_H
