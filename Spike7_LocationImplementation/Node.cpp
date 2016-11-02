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

void Node::printDescription()
{
    cout << _description;
   /* cout << "Edges include: \n";
    for(auto i=_edgesVector.begin(); i!=_edgesVector.end(); i++)
    {
        cout << (*i)->getDestination()->getName() << endl;
        cout << "IDS include: \n";
        for(auto j=(*i)->getIdentifiers().begin(); j!=(*i)->getIdentifiers().end(); j++)
        {
            cout << "\t" << *j << endl;
        }
    }

    cout << endl;*/
}

void Node::addEdge(Edge *edge)
{
    _edgesVector.push_back(edge);
}

string Node::getName()
{
    return _name;
}

Edge* Node::validateCommand(string command)
{
    for(auto i=_edgesVector.begin(); i!=_edgesVector.end(); i++)
    {
        for(auto j=(*i)->getIdentifiers().begin(); j!=(*i)->getIdentifiers().end(); j++)
        {
            if((*j) == command)
            {
               return (*i);
            }
        }
    }
    return 0;
}