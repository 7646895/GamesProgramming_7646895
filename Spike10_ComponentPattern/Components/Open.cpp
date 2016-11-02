//
// Created by Jessica Vilaysak on 9/10/2016.
//

#include "Open.h"

Open::Open()
{
    _id = "open";
    _open = false;
}

void Open::setCanOpenWith(vector<string> openwith)
{
    _canOpenWith = openwith;
}

bool Open::isOpen()
{
    return _open;
}

void Open::openObject()
{
    _open = true;
}

bool Open::canOpenWith(string id)
{
    for(auto i=_canOpenWith.begin(); i!=_canOpenWith.end(); i++)
    {
        if((*i) == id)
        {
            return true;
        }
    }
    return false;
}

string Open::getOpenWithVector()
{
    string output;
    for(auto i=_canOpenWith.begin(); i!=_canOpenWith.end(); i++)
    {
        output += " " + (*i) + "\n";
    }
    return output;
}