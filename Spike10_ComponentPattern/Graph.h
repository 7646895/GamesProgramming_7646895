//
// Created by Jessica Vilaysak on 14/09/2016.
//
#pragma once
#include "Node.h"
#include "Edge.h"
#include "Components/Inventory.h"
#include "Components/Component.h"
#include <vector>
#include <iostream>
#include <fstream>
#ifndef LOCATIONIMPLEMENTATION_GRAPH_H
#define LOCATIONIMPLEMENTATION_GRAPH_H
using namespace std;

class Graph {
private:
    string _worldName;
    vector<Node*> _locations;
    Node* _startingNode;
    vector<GameObject*> _objects;
public:
    Graph();
    Graph(string worldName);
    void loadTextFile();
    Node* getLocation(string name);
    void setStartingNode();
    Node* getStartingNode();
    vector<string> getStringstreamVector(string input);
    GameObject* getObject(string name);
    Component* getNewComponent(string id);
};


#endif //LOCATIONIMPLEMENTATION_GRAPH_H
