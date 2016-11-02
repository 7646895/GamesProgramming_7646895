//
// Created by Jessica Vilaysak on 30/08/2016.
//

#include "StateGameplay.h"
#include "StateMenu.h"
#include "StateHighscore.h"

StateGameplay::StateGameplay(string world)
{
    _name = "gameplay";
    _world = world;
    _nextAction = "";
}
/*
 * There are two options for this state:
 * return to main menu (quit)
 * new high score (hiscore)
 */
State* StateGameplay::commenceState()
{
    string output = "\nWelcome to Zorkish: "+_world+"\n";
    if(_world == "Cloudy Mountains")
    {
        output += "You have landed on top of the tallest Tibetan mountain! \nThere is a lone wolf on a peak to your left looking your way...\nThere's nothing for you to do here.\n:> ";
    }
    else if(_world == "Pyramids of Gyoza")
    {
        output += "BAM! You were hit by a gyoza! \nYou look around and there's a young boy holding hot gyozas in a bamboo basket.\nWhere are his parents you think to yourself...\n:> ";
    }

    string input;

    cout << output;
    cin >> input;
    validateAction(input);

    if(_nextAction == "quit")
    {
        static StateMenu _menu;
        return &_menu;
    }
    if(_nextAction == "hiscore")
    {
        static StateHighscore _highscore(_world, 0, 0);
        return &_highscore;
    }

}

void StateGameplay::validateAction(string input)
{
    string lInput = input;
    while((lInput != "quit") && (lInput != "hiscore"))
    {
        cout << "That's an invalid action! Valid actions are: quit, hiscore.\n:> ";
        cin >> lInput;
    }
    _nextAction = lInput;
}