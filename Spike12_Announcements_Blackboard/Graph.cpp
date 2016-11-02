//
// Created by Jessica Vilaysak on 14/09/2016.
//

#include "Graph.h"
#include "Components/Attack.h"
#include "Components/Container.h"
#include "Components/Damage.h"
#include "Components/Drop.h"
#include "Components/GamePoints.h"
#include "Components/Level.h"
#include "Components/Life.h"
#include "Components/Open.h"
#include "Components/Take.h"
#include "Components/Health.h"
#include <sstream>

Graph::Graph()
{

}

Graph::Graph(string worldName, Player *p, MessageHandler *msgHandler)
{
    _player = p;
    _msgHandler = msgHandler;
    _worldName = worldName;
    loadTextFile();
    setStartingNode();
}

void Graph::loadTextFile()
{
    ifstream _ItemFile(_worldName+"/"+_worldName+" Items.txt");
    string input;
    bool isContainer;
    bool canOpen;

    if(_ItemFile.is_open())
    {
        getline(_ItemFile, input);
        if(input == "Items")
        {
            while(getline(_ItemFile, input))
            {
                if(input == "Containers")
                    break;
                if(input == "")
                    continue;
                string objName = input;
                getline(_ItemFile, input);
                vector<string> identifiers = getStringstreamVector(input);
                getline(_ItemFile, input);
                string objDescription = input;
                //get components
                getline(_ItemFile, input);
                vector<string> sComponents = getStringstreamVector(input);
                vector<Component*> cComponents;
                for(auto s=sComponents.begin(); s!=sComponents.end(); s++)
                {
                    if((*s) == "container")
                        isContainer = true;
                    if((*s) == "open")
                        canOpen = true;
                    cComponents.push_back(getNewComponent((*s)));
                }
                //create GameObject
                GameObject* newObj = new GameObject(objName, identifiers, objDescription, cComponents, _msgHandler);
                _msgHandler->addReceiver(newObj);
                //for container you need to instantiate a new inventory
                if(newObj->hasComponent("container") != 0)
                {
                    Inventory* newInv = new Inventory();
                    Container* lContainer = (Container*)newObj->hasComponent("container");
                    lContainer->setInventoryObject(newInv);
                }
                //take in extra lines with details for components
                //if the object is a container and can be opened then get vector of strings that can open it
                if(newObj->hasComponent("open") != 0)
                {
                    getline(_ItemFile, input);
                    vector<string> canOpenWith = getStringstreamVector(input);
                    Open* openObj = (Open*)newObj->hasComponent("open");
                    openObj->setCanOpenWith(canOpenWith);
                }
                //if the object can attack, take in vector of strings that you can attack it with
                if(newObj->hasComponent("attack") != 0)
                {
                    getline(_ItemFile, input);
                    vector<string> canAttackWith = getStringstreamVector(input);
                    Attack* attackObj = (Attack*)newObj->hasComponent("attack");
                    attackObj->setVector(canAttackWith);
                }
                //if the object deals damage AND can take damage, take in damage int
                if(newObj->hasComponent("damage") != 0)
                {
                    getline(_ItemFile, input);
                    int iDamage = input.at(0) - '0';
                    Damage* damageObj = (Damage*)newObj->hasComponent("damage");
                    damageObj->setDamage(iDamage);
                }
                //if the object has health, once it loses all health (through receiving/giving attacks) it will die.
                if(newObj->hasComponent("health") != 0)
                {
                    getline(_ItemFile, input);
                    int iHealth = input.at(0) - '0';
                    Health* healthObj = (Health*)newObj->hasComponent("health");
                    healthObj->setHealth(iHealth);
                }
                _objects.push_back(newObj);
            }
        }

        if(input == "Containers")
        {
            while(getline(_ItemFile, input))
            {
                if(input == "")
                    continue;
                GameObject* current = getObject(input);
                getline(_ItemFile, input);
                vector<string> containsTheFollowing = getStringstreamVector(input);
                vector<GameObject*> inventory;
                for(auto i=containsTheFollowing.begin(); i!=containsTheFollowing.end(); i++)
                {
                    inventory.push_back(getObject((*i)));
                }
                Container* containerObj = (Container*)current->hasComponent("container");
                containerObj->getInventoryObject()->setInventory(inventory);
            }
        }
    }

    //load location text file
    ifstream _LocationFile(_worldName+"/"+_worldName+" Locations.txt");
    if(_LocationFile.is_open())
    {
        getline(_LocationFile, input);
        if(input == "Locations")
        {
            while(getline(_LocationFile, input))
            {
                if(input == "Paths")
                    break;
                if(input == "")
                    continue;
                string locationName = input;
                string locationDescription;
                getline(_LocationFile, input);
                while(input != "Inventory")
                {
                    locationDescription += input + "\n";
                    getline(_LocationFile, input);
                }
                Node* location = new Node(locationName, locationDescription);
                _locations.push_back(location);

                getline(_LocationFile, input);

                vector<string> inventoryObjects = getStringstreamVector(input);
                for(auto a=inventoryObjects.begin(); a!=inventoryObjects.end(); a++)
                {
                    GameObject* obj = getObject((*a));
                    location->getInventoryObject()->addInventoryObject(obj);
                }
            }
        }


        if(input == "Paths")
        {
            while(getline(_LocationFile, input))
            {
                if(input == "")
                    continue;
                Node* nFrom = getLocation(input);
                getline(_LocationFile, input);
                Node* nTo = getLocation(input);
                Edge* newEdge = new Edge(nFrom, nTo);
                nFrom->addEdge(newEdge);
                getline(_LocationFile, input);
                vector<string> _identifiers = getStringstreamVector(input);
                newEdge->addIdentifiers(_identifiers);
            }
        }
    }
    _msgHandler->setDefaultObjects(_locations, _player);
}

GameObject* Graph::getObject(string name)
{
    for(auto i=_objects.begin(); i!=_objects.end(); i++)
    {
        if((*i)->getName() == name)
        {
            return (*i);
        }
    }
    return 0;
}

vector<string> Graph::getStringstreamVector(string input)
{
    vector<string> output;
    string temp;
    stringstream ss(input);
    while(ss.good())
    {
        ss >> temp;
        output.push_back(temp);
    }
    return output;
}

Node* Graph::getLocation(string name)
{
    for(auto i=_locations.begin(); i!=_locations.end(); i++)
    {
        if((*i)->getName() == name)
        {
            return (*i);
        }
    }
}

void Graph::setStartingNode()
{
    _startingNode = _locations.front();
}

Node* Graph::getStartingNode()
{
    return _startingNode;
}

Component* Graph::getNewComponent(string id)
{
    if(id == "attack")
    {
        return (new Attack());
    }
    if(id == "container")
    {
        return (new Container());
    }
    if(id == "damage")
    {
        return (new Damage());
    }
    if(id == "drop")
    {
        return (new Drop());
    }
    if(id == "points")
    {
        return (new GamePoints());
    }
    if(id == "health")
    {
        return (new Health());
    }
    if(id == "level")
    {
        return (new Level());
    }
    if(id == "life")
    {
        return (new Life());
    }
    if(id == "open")
    {
        return (new Open());
    }
    if(id == "take")
    {
        return (new Take());
    }
}
