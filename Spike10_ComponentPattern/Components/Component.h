//
// Created by Jessica Vilaysak on 9/10/2016.
//
#pragma once
#include <iostream>
#include <vector>
#ifndef COMPONENTPATTERN_COMPONENT_H
#define COMPONENTPATTERN_COMPONENT_H
using namespace std;

class Component
{
protected:
    string _id;

public:
    Component();
    string getId();
};


#endif //COMPONENTPATTERN_COMPONENT_H
