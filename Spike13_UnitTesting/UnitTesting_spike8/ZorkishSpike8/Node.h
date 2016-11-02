//
// Created by Jessica Vilaysak on 14/09/2016.
//
#pragma once
#include "GameObject.h"
#include "Edge.h"
#ifndef LOCATIONIMPLEMENTATION_NODE_H
#define LOCATIONIMPLEMENTATION_NODE_H
using namespace std;

class Node : public GameObject
{
private:
    vector<Edge*> _edgesVector;
    string _inventoryDescription;

public:
    Node();
    Node(string id, string description);

    void addEdge(Edge* edge);
    string printDescription();
    string printInvDescription();
    string getName();
    Edge* canTravel(string direction);
    vector<string> getDirections();
    void setInventoryDescription(string desc);
};


#endif //LOCATIONIMPLEMENTATION_NODE_H
