//
// Created by Jessica Vilaysak on 28/08/2016.
//

#include "GameHandler.h"
#include "StateMenu.h"

GameHandler::GameHandler()
{
    _state = NULL;
}

void GameHandler::startGame()
{
    StateMenu _stateMenu;
    _state = &_stateMenu;
    while (_state->getStateName() != "exit")
    {
        _state = _state->commenceState();
    }

    cout << "Thanks for playing! Hope to see you again :)";

}

/*  State *temp;
   StateMenu _menu;
   temp = &_menu;
   temp = temp->commenceState();
   cout << "Round2: " << temp->getStateName() << endl;
   temp->commenceState();*/