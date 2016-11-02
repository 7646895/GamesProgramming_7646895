//
// Created by Jessica Vilaysak on 14/10/2016.
//
#pragma once
#include "Message.h"

#ifndef MESSAGINGSYSTEM_HEALTHMESSAGE_H
#define MESSAGINGSYSTEM_HEALTHMESSAGE_H


class HealthMessage : Message
{
private:
    int _effect;

public:
    HealthMessage();
    HealthMessage(int e);
    void setEffect(int e);
    int getEffect();
};


#endif //MESSAGINGSYSTEM_HEALTHMESSAGE_H

/*
to change
 */