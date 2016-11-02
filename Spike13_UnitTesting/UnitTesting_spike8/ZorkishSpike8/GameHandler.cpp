//
// Created by Jessica Vilaysak on 28/08/2016.
//

#include "GameHandler.h"
/*
 * set up game
 *  initialise game states
 *  initialisation includes ensuring relevant game states
 *  know about relevant other game states
 *  (ie. StateSelectworld needs to know about StateGameplay)
 */
GameHandler::GameHandler()
{
    State *about = new StateAbout();
    _stateVector.push_back(about);
    State *exit = new StateExit();
    _stateVector.push_back(exit);
    State *gameplay = new StateGameplay();
    _stateVector.push_back(gameplay);
    State *hallOfFame = new StateHallOfFame();
    _stateVector.push_back(hallOfFame);
    State *help = new StateHelp();
    _stateVector.push_back(help);
    State *highscore = new StateHighscore();
    _stateVector.push_back(highscore);
    State *menu = new StateMenu();
    _stateVector.push_back(menu);
    State *selectWorld = new StateSelectworld();
    _stateVector.push_back(selectWorld);

    //assigns select world object the relevant game play object
    StateSelectworld* lSelect = (StateSelectworld*)getState("select world");
    StateGameplay* lGame = (StateGameplay*)getState("gameplay");
    lSelect->setGame(lGame);

    //assigns gameplay object the relevant highscore object
    StateHighscore* lHigh = (StateHighscore*)getState("highscore");
    lGame->setHighscoreObj(lHigh);

    //create a Player
    //assigns gameplay object this player
    GameObject *p = new Player();
    _player = (Player*)p;
    lGame->setPlayer((Player*)p);

    _currentState = menu;
}

void GameHandler::startGame()
{
    while(_currentState->getStateName() != "exit")
    {
        string nextStateName = _currentState->commenceState();
        _currentState = getState(nextStateName);
    }

    cout << "Thank you\n";
}

State* GameHandler::getState(string name)
{
    for(auto i=_stateVector.begin(); i!=_stateVector.end(); i++)
    {
        if((*i)->getStateName() == name)
        {
            return (*i);
        }
    }
}

/*  State *temp;
   StateMenu _menu;
   temp = &_menu;
   temp = temp->commenceState();
   cout << "Round2: " << temp->getStateName() << endl;
   temp->commenceState();*/

GameHandler::~GameHandler()
{
    for(auto i=_stateVector.begin(); i!=_stateVector.end(); i++)
    {
        delete (*i);
    }
    delete _player;
}