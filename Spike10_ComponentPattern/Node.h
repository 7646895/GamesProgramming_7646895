//
// Created by Jessica Vilaysak on 14/09/2016.
//
#pragma once
#include "Edge.h"
#include "Components/Inventory.h"
#ifndef LOCATIONIMPLEMENTATION_NODE_H
#define LOCATIONIMPLEMENTATION_NODE_H
using namespace std;

class Node
{
private:
    string _name;
    string _description;
    vector<Edge*> _edgesVector;
    Inventory* _Inventory;

public:
    Node();
    Node(string id, string description);

    void addEdge(Edge* edge);
    void printDescription();
    void printInvDescription();
    string getName();
    Edge* canTravel(string direction);
    vector<string> getDirections();
    Inventory* getInventoryObject();
};


#endif //LOCATIONIMPLEMENTATION_NODE_H
