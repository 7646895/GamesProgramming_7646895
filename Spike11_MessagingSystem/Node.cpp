//
// Created by Jessica Vilaysak on 14/09/2016.
//

#include "Node.h"

Node::Node()
{
    _Inventory = new Inventory();
}

Node::Node(string name, string description)
{
    _name = name;
    _description = description;
    _Inventory = new Inventory();
}

void Node::printDescription()
{
    cout << _description;
    if(_Inventory->getCapacity() == 0)
    {
        cout << "There are no items in this location!\n";
        return;
    }
    cout << "Objects in this location...\n";
    _Inventory->listInventory();
}

void Node::printInvDescription()
{
    if(_Inventory->getCapacity() == 0)
    {
        cout << "There are no items in this location!\n";
        return;
    }
    cout << "Objects in this location...\n";
    _Inventory->listInventory();
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

Inventory* Node::getInventoryObject()
{
    return _Inventory;
}



