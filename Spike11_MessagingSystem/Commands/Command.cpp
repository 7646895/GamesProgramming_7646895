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

void Command::run(vector<string> input, Player *p)
{
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

void Command::sendHealthMessage(string type, int effect, vector<string> recipients)
{
    HealthMessage *hMsg;
    if(type == "decrease")
    {
        hMsg = new HealthMessage((effect*-1));
    }
    else if(type == "increase")
    {
        hMsg = new HealthMessage(effect);
    }
    Message *msg = (Message*)hMsg;
    _msgHandler->sendMessages(msg, msg->getType(), recipients);
}