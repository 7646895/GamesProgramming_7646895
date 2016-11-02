//
// Created by Jessica Vilaysak on 28/08/2016.
//
#pragma once
#include <iostream>
#ifndef ZORKISHPARTONE_STATE_H
#define ZORKISHPARTONE_STATE_H
using namespace std;

class State {
protected:
    string _name;
public:
    State();
    virtual string commenceState();
    string getStateName();

};


#endif //ZORKISHPARTONE_STATE_H
