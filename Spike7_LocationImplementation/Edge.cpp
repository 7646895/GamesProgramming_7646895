//
// Created by Jessica Vilaysak on 14/09/2016.
//

#include "Edge.h"

Edge::Edge()
{

}


Edge::Edge(Node *current, Node *destination)
{
    _currentLocation = current;
    _destination = destination;
}

bool Edge::isCurrent(Node *current)
{
    if(_currentLocation == current)
        return true;

    return false;
}

Node* Edge::getDestination()
{
    return _destination;
}

void Edge::addIdentifiers(vector<string> ids)
{
    _identifiers = ids;
}

vector<string> Edge::getIdentifiers()
{
    return _identifiers;
}
