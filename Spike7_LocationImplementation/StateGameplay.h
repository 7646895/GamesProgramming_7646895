//
// Created by Jessica Vilaysak on 30/08/2016.
//
#pragma once
#include "State.h"
#include "StateHighscore.h"
#include "Player.h"
#include "Graph.h"
#ifndef ZORKISHPARTONE_STATEGAMEPLAY_H
#define ZORKISHPARTONE_STATEGAMEPLAY_H


class StateGameplay : public State
{
private:
    string _world;
    int _score;
    int _moves;
    string _nextAction;
    StateHighscore *_highscore;
    Player *_player;
    vector<Graph*> _worldGraphs;
    Graph* _currentWorld;


public:
    StateGameplay();
    ~StateGameplay();
    void setWorld(string world);
    string commenceState();
    void validateAction(string input);
    void setHighscoreObj(StateHighscore *highscore);
    void setPlayer(Player *p);
    void TESTPLAYER();
};


#endif //ZORKISHPARTONE_STATEGAMEPLAY_H
