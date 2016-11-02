//
// Created by Jessica Vilaysak on 14/09/2016.
//

#include "Graph.h"
#include <sstream>

Graph::Graph()
{

}

Graph::Graph(string worldName)
{
    _worldName = worldName;
    loadTextFile();
    //Container* temp = (Container*)_objects.at(16);
    setStartingNode();
}

void Graph::loadTextFile()
{
    ifstream _ItemFile(_worldName+"/"+_worldName+" Items.txt");
    string input;

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
                getline(_ItemFile, input);
                string locDescription = input;
                //check if object is container or not
                getline(_ItemFile, input);
                stringstream ssparams(input);
                string temp;
                vector<bool> params;
                bool boolParam;
                while(ssparams.good())
                {
                    ssparams >> temp;
                    boolParam = false;
                    if(temp == "T")
                        boolParam = true;
                    params.push_back(boolParam);
                }
                GameObject* newObj;
                if(params.at(0))
                {
                    //IS container
                    Container* container = new Container(objName, objDescription, locDescription, params.at(1));
                    getline(_ItemFile, input);
                    vector<string> openWithIds = getStringstreamVector(input);
                    container->setOpenWith(openWithIds);
                    newObj = (GameObject*)container;
                }
                else
                {
                    Item* item = new Item(objName, objDescription, locDescription, params.at(1));
                    newObj = (GameObject*)item;
                }
                newObj->setIdentifiers(identifiers);
                _objects.push_back(newObj);
            }
        }

        if(input == "Containers")
        {
            while(getline(_ItemFile, input))
            {
                if(input == "")
                    continue;
                Container* current = (Container*)getObject(input);
                getline(_ItemFile, input);

                vector<string> canOpenWith = getStringstreamVector(input);
                vector<GameObject*> inventory;

                for(auto i=canOpenWith.begin(); i!=canOpenWith.end(); i++)
                {
                    inventory.push_back(getObject((*i)));
                }
                current->setInventory(inventory);
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
                    location->addInventoryObject(obj);
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


