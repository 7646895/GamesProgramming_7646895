//
// Created by Jessica Vilaysak on 12/09/2016.
//

#include "GameObject.h"

GameObject::GameObject()
{

}

string GameObject::getName()
{
    return _name;
}

string GameObject::getDescription()
{
    return _description;
}

bool GameObject::hasIdentifier(string id)
{
    for(auto i=_identifiers.begin(); i!=_identifiers.end(); i++)
    {
        if((*i) == id)
            return true;
    }
    return false;
}

void GameObject::setIdentifiers(vector<string> identifiers)
{
    _identifiers = identifiers;
}

bool GameObject::isContainer()
{
    return _isContainer;
}

string GameObject::getLocationDescription()
{
    return _locationDescription;
}




