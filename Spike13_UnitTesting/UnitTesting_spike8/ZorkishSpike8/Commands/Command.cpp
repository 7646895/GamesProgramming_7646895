//
// Created by Jessica Vilaysak on 20/09/2016.
//

#include "Command.h"

Command::Command()
{
    _identifiers.push_back("default command");
}

void Command::addIdentifiers(vector<string> ids)
{
    for(auto i=ids.begin(); i!=ids.end(); i++)
    {
        _identifiers.push_back(*i);
    }
}

string Command::run(vector<string> input, Player *p)
{
    return "default";
}

bool Command::containsId(string id)
{
    for(auto i=_identifiers.begin(); i!=_identifiers.end(); i++)
    {
        if((*i) == id)
        {
            return true;
        }
    }
    return false;
}