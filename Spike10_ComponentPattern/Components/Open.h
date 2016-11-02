//
// Created by Jessica Vilaysak on 9/10/2016.
//
#pragma once
#include "Component.h"
#ifndef COMPONENTPATTERN_OPEN_H
#define COMPONENTPATTERN_OPEN_H


class Open : public Component
{
private:
    vector<string> _canOpenWith;
    bool _open;

public:
    Open();
    void setCanOpenWith(vector<string> openwith);
    void openObject();
    bool isOpen();
    bool canOpenWith(string id);
    string getOpenWithVector();
};


#endif //COMPONENTPATTERN_OPEN_H
