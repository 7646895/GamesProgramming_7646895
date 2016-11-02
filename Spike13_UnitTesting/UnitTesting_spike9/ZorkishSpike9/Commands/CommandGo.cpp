//
// Created by Jessica Vilaysak on 24/09/2016.
//

#include "CommandGo.h"
//#include "../Node.h"

CommandGo::CommandGo()
{
    _identifiers.push_back("go");
}

string CommandGo::run(vector<string> input, Player *p)
{
    string output;
    string direction;
    if(input.capacity() == 1)
        direction = input.at(0);
    if(input.capacity() == 2)
        direction = input.at(1);
    Node* currentLocation = p->getCurrentLocation();
    Edge* canTravel = currentLocation->canTravel(direction);
    if(canTravel == 0)
    {
        output = "That's not a valid direction..choose from:";
        vector<string> directions = currentLocation->getDirections();
        for(auto i=directions.begin(); i!=directions.end(); i++)
        {
            if((*i) != directions.front())
                output += ",";
            output += " "+ *i;
        }
        output += "\n";
        return output;
    }
    p->setCurrentLocation(canTravel->getDestination());
    output = "You are now at " + p->getCurrentLocation()->getName() +"\n";
    output += p->getCurrentLocation()->printDescription();
    return output;
}