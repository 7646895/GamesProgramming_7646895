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
public:
    Node();
    Node(string id, string description);

    void addEdge(Edge* edge);
    void printDescription();
    string getName();
    Edge* validateCommand(string command);
};


#endif //LOCATIONIMPLEMENTATION_NODE_H
