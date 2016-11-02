//
// Created by Jessica Vilaysak on 14/09/2016.
//

#include "Graph.h"
#include <string>

Graph::Graph()
{

}

Graph::Graph(string worldName)
{
    _worldName = worldName;
    loadTextFile();
    setStartingNode();
}

void Graph::loadTextFile()
{
    ifstream _file(_worldName+".txt");
    string input;
    bool temp = _file.is_open();
    if(_file.is_open())
    {
        while(getline(_file, input))
        {
            if(input == "Locations")
            {
                getline(_file, input);
                while(input == "Name")
                {
                    getline(_file, input);
                    string name = input;

                    getline(_file, input);

                    string desc = "";
                    while(input != "Inventory")
                    {
                        desc += input + "\n";
                        getline(_file, input);
                    }
                    Node* temp = new Node(name, desc);
                    _locations.push_back(temp);

                    string inventoryDesc;
                    getline(_file, input);
                    while(input != "Items")
                    {
                        inventoryDesc += input + "\n";
                        getline(_file, input);
                    }
                    temp->setInventoryDescription(inventoryDesc);

                    string itemName;
                    string itemDesc;
                    getline(_file, input);
                    while(input != "Name")
                    {
                        itemName = input;
                        getline(_file, input);
                        itemDesc = input;
                        Item* item = new Item(itemName, itemDesc);
                        temp->addInventoryItem(item);
                        getline(_file, input);
                        if(input == "")
                            break;
                    }
                }
            }
            if(input == "Paths")
            {
                vector<string> tempIDS;
                getline(_file, input);
                while(input == "new")
                {
                    getline(_file, input);
                    string from = input;
                    getline(_file, input);
                    string to = input;

                    Node* nFrom = getLocation(from);
                    Node* nTo = getLocation(to);
                    Edge* newEdge = new Edge(nFrom, nTo);
                    nFrom->addEdge(newEdge);
                    getline(_file, input);
                    tempIDS.clear();

                    while(input != "new")
                    {
                        tempIDS.push_back(input);
                        getline(_file, input);
                        if(input == "")
                            break;
                    }
                    newEdge->addIdentifiers(tempIDS);
                }
            }
        }
    }
    /*for(auto i=_locations.begin(); i!=_locations.end(); i++)
    {
        cout << (*i)->getName() << ": " << endl;
        (*i)->printDescription();

    }*/
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


