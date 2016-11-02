//
// Created by Jessica Vilaysak on 14/10/2016.
//
#pragma once
#include <iostream>
#include <vector>
#ifndef MESSAGINGSYSTEM_MESSAGE_H
#define MESSAGINGSYSTEM_MESSAGE_H
using namespace std;

class Message
{
protected:
    string _type;

public:
    Message();
    string getType();

};


#endif //MESSAGINGSYSTEM_MESSAGE_H
