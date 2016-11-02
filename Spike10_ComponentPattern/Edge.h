//
// Created by Jessica Vilaysak on 14/09/2016.
//
#pragma once
#include <iostream>
#include <vector>
#ifndef LOCATIONIMPLEMENTATION_EDGE_H
#define LOCATIONIMPLEMENTATION_EDGE_H
using namespace std;
class Node;
class Edge {
private:
    Node *_currentLocation;
    Node *_destination;
    vector<string> _identifiers;

public:
    Edge();
    Edge(Node *current, Node *destination);
    bool isCurrent(Node* current);
    Node* getDestination();
    void addIdentifiers(vector<string> ids);
    vector<string> getIdentifiers();
};


#endif //LOCATIONIMPLEMENTATION_EDGE_H
