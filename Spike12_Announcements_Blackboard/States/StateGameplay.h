//
// Created by Jessica Vilaysak on 30/08/2016.
//
#pragma once
#include "State.h"
#include "StateHighscore.h"
#include "../Player.h"
#include "../Graph.h"
#include "../Commands/CommandController.h"
#ifndef ZORKISHPARTONE_STATEGAMEPLAY_H
#define ZORKISHPARTONE_STATEGAMEPLAY_H


class StateGameplay : public State
{
private:
    string _world;
    int _score;
    int _moves;
    StateHighscore *_highscore;
    Player *_player;
    Graph* _currentWorld;
    CommandController *_cmdHandler;
    MessageHandler *_msgHandler;

public:
    StateGameplay();
    ~StateGameplay();
    void setWorld(string world);
    string commenceState();
    void setHighscoreObj(StateHighscore *highscore);
    void setPlayer(Player *p);
};


#endif //ZORKISHPARTONE_STATEGAMEPLAY_H
