//
// Created by Jessica Vilaysak on 30/08/2016.
//

#include "StateGameplay.h"
#include "StateMenu.h"
#include "StateHighscore.h"

StateGameplay::StateGameplay()
{
    _name = "gameplay";
    _nextAction = "";
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
    cout << "\n:> ";
    string input;
    cin >> input;
    while((input != "quit") && (input != "hiscore"))
    {
        validateAction(input);
        cout << ":> ";
        cin >> input;
    }

    if(input == "quit")
    {
        return "menu";
    }
    if(input == "hiscore")
    {
        _highscore->setValues(_world, _score, _moves);
        return "highscore";
    }

}

void StateGameplay::TESTPLAYER()
{

}

void StateGameplay::validateAction(string input)
{
    if(_currentWorld->validatePlayerCommand(input, _player->getCurrentLocation()) != 0)
    {
        Edge* edge = _currentWorld->validatePlayerCommand(input, _player->getCurrentLocation());
        _player->setCurrentLocation(edge->getDestination());
        cout << "You have moved to " << _player->getCurrentLocation()->getName() << "...\n";
        _player->getCurrentLocation()->printDescription();
        cout << endl;
        _moves++;
    }
    else
    {
        cout << "Oh man that's not an action...\n";
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
