//
// Created by Jessica Vilaysak on 12/09/2016.
//

#include "GameObject.h"

GameObject::GameObject()
{

}

GameObject::GameObject(string name, vector<string> ids, string description, vector<Component*> components)
{
    _name = name;
    _description = description;
    _identifiers = ids;
    _components = components;
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

bool GameObject::isContainer()
{
    if(hasComponent("container") != 0)
        return true;
    else
        return false;
}


void GameObject::addComponent(Component* component)
{
    _components.push_back(component);
}

Component* GameObject::hasComponent(string id)
{
    for(auto i=_components.begin(); i!=_components.end(); i++)
    {
        if((*i)->getId() == id)
        {
            return (*i);
        }
    }
    return 0;
}

