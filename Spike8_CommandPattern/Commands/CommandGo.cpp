//
// Created by Jessica Vilaysak on 24/09/2016.
//

#include "CommandGo.h"
//#include "../Node.h"

CommandGo::CommandGo()
{
    _identifiers.push_back("go");
}

void CommandGo::run(vector<string> input, Player *p)
{
    string direction;
    if(input.capacity() == 1)
        direction = input.at(0);
    if(input.capacity() == 2)
        direction = input.at(1);
    Node* currentLocation = p->getCurrentLocation();
    Edge* canTravel = currentLocation->canTravel(direction);
    if(canTravel == 0)
    {
        cout << "That's not a valid direction..choose from:";
        vector<string> directions = currentLocation->getDirections();
        for(auto i=directions.begin(); i!=directions.end(); i++)
        {
            if((*i) != directions.front())
                cout << ",";
            cout << " "<< *i;
        }
        cout << endl;
        return;
    }
    p->setCurrentLocation(canTravel->getDestination());
    cout << "You are now at " << p->getCurrentLocation()->getName() << endl;
    p->getCurrentLocation()->printDescription();
}