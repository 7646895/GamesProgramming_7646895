//
// Created by Jessica Vilaysak on 30/08/2016.
//
#pragma once
#include "StateGameplay.h"

#ifndef ZORKISHPARTONE_STATESELECTWORLD_H
#define ZORKISHPARTONE_STATESELECTWORLD_H


class StateSelectworld : public State
{
private:
    string _world;
    int _numWorlds;
    StateGameplay *_game;
    vector<string> _worldList;

public:
    StateSelectworld();
    ~StateSelectworld();
    string commenceState();
    int validateWorld(string input);
    void setGame(StateGameplay *game);
    void getWorldList();
    void printWorldList();
};


#endif //ZORKISHPARTONE_STATESELECTWORLD_H
