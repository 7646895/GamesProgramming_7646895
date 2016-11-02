//
// Created by Jessica Vilaysak on 30/08/2016.
//

#include "StateGameplay.h"

StateGameplay::StateGameplay()
{
    _name = "gameplay";

}

StateGameplay::~StateGameplay()
{
    delete _highscore;
    delete _player;
}

void StateGameplay::setWorld(string world)
{
    _world = world;
    _currentWorld = new Graph(_world);
    _player->setCurrentLocation(_currentWorld->getStartingNode());
}

/*
 * There are two options for this state:
 * return to main menu (quit)
 * new high score (hiscore)
 */
string StateGameplay::commenceState()
{
    _moves = 0;
    cout << "You have chosen the world "+_world+"\n";
    cout << "You are starting at the " << _player->getCurrentLocation()->getName() << endl;
    _player->getCurrentLocation()->printDescription();
    string input;
    string output = " ";
    getline(cin, input);
    while((output != "1") && (output != "2"))
    {
        cout << ":> ";
        getline(cin, input);
        output = _cmdHandler.run(input, _player);
    }

    if(output == "1")
    {
        return "menu";
    }
    if(output == "2")
    {
        _highscore->setValues(_world, _score, _moves);
        return "highscore";
    }

}


void StateGameplay::setHighscoreObj(StateHighscore *highscore)
{
    _highscore = highscore;
}

void StateGameplay::setPlayer(Player *p)
{
    _player = p;
}
