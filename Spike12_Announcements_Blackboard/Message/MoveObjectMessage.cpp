//
// Created by Jessica Vilaysak on 27/10/2016.
//

#include "MoveObjectMessage.h"

MoveObjectMessage::MoveObjectMessage()
{
    _type = "move";
}

MoveObjectMessage::MoveObjectMessage(int points)
{
    _type = "move";
    _points = points;
}

int MoveObjectMessage::getPoints()
{
    return _points;
}
