//
// Created by Jessica Vilaysak on 31/08/2016.
//

#include "StateHallOfFame.h"
#include "StateMenu.h"

StateHallOfFame::StateHallOfFame()
{
    _name = "hall of fame";
}

State* StateHallOfFame::commenceState()
{
    string output = "\n";
    output += "Zorkish :: New High Score\n";
    output += "-------------------------------------------\n\n";
    output += "Top 10 Zorkish Adventure Champions\n\n";
    output += "   1. Freddie Krueger, Cloudy Mountains, 157\n";
    output += "   2. Adam Sandler, Cloudy Mountains, 62\n";
    output += "   3. Katie Johnson, Pyramids of Gyoza, 109\n";
    output += "   4. Jessica Vilaysak, Pyramids of Gyoza, 21\n";
    output += "\nPress Enter to return to the main menu...";
    cout << output;

    char input;
    string sInput;
    cin.get();
    int num = cin.gcount();
    if(num != 0)
        getline(cin, sInput);

    StateMenu menu;
    return &menu;
}