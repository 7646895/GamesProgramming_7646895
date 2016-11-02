//
// Created by Jessica Vilaysak on 14/10/2016.
//

#include "HealthMessage.h"

HealthMessage::HealthMessage()
{
    _type = "health";
}

HealthMessage::HealthMessage(int e)
{
    _type = "health";
    _effect = e;
}

void HealthMessage::setEffect(int e)
{
    _effect = e;
}

int HealthMessage::getEffect()
{
    return _effect;
}