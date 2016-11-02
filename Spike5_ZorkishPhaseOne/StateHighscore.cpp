//
// Created by Jessica Vilaysak on 31/08/2016.
//

#include "StateHighscore.h"
#include "string.h"
#include "StateMenu.h"


StateHighscore::StateHighscore(string world, int score, int moves)
{
    _name = "highscore";
    _world = world;
    _score = score;
    _moves = moves;
}

State* StateHighscore::commenceState()
{
    string output = "\n";
    output += "Zorkish :: New High Score\n";
    output += "-------------------------------------------\n\n";
    output += "Congratulations !!!\n\nYou have made it to the Zorkish Hall Of Fame :)\n\n";
    output += "Adventure: "+_world+"\n";
    output += "Score: "+to_string(_score)+"\n";
    output += "Moves; "+to_string(_moves)+"\n\n";
    output += "Please enter your name and press enter..\n:> ";
    cout << output;
    string playerName;
    cin >> playerName;

    cout << "Great job "+playerName+"!\nPress enter to continue back to the main menu...";

    char input;
    string sInput;
    cin.get();
    int num = cin.gcount();
    if(num != 0)
        getline(cin, sInput);

    StateMenu menu;
    return &menu;

}

void StateHighscore::getData()
{
    cout << "World is; " << _world << endl;
}