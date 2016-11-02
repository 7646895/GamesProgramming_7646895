//
// Created by Jessica Vilaysak on 14/09/2016.
//

#include "Node.h"

Node::Node()
{

}

Node::Node(string name, string description)
{
    _name = name;
    _description = description;
}

string Node::printDescription()
{
    return _description;
}

string Node::printInvDescription()
{
    return _inventoryDescription;
}

void Node::addEdge(Edge *edge)
{
    _edgesVector.push_back(edge);
}

string Node::getName()
{
    return _name;
}

Edge* Node::canTravel(string direction)
{
    for(auto i=_edgesVector.begin(); i!=_edgesVector.end(); i++)
    {
        for(auto j=(*i)->getIdentifiers().begin(); j!=(*i)->getIdentifiers().end(); j++)
        {
            if((*j) == direction)
            {
                return (*i);
            }
        }
    }
    return 0;
}

vector<string> Node::getDirections()
{
    vector<string> directions;
    for(auto i=_edgesVector.begin(); i!=_edgesVector.end(); i++)
    {
        for(int j=0; j<(*i)->getIdentifiers().capacity(); j++)
        {
            directions.push_back((*i)->getIdentifiers().at(j));
        }
    }
    return directions;
}

void Node::setInventoryDescription(string desc)
{
    _inventoryDescription = desc;
}


