//
// Created by Jessica Vilaysak on 14/10/2016.
//

#include "Message.h"

Message::Message()
{
    _type = "default";
}

string Message::getType()
{
    return _type;
}
