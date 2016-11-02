//
// Created by Jessica Vilaysak on 30/08/2016.
//

#include "StateHelp.h"
#include "StateMenu.h"

StateHelp::StateHelp()
{
    _name = "help";
}

State* StateHelp::commenceState()
{
    string output = "\n";
    output += "Zorkish :: Help\n";
    output += "-------------------------------------------\n\n";
    output += "The following commands are supported:\n";
    output += "   quit,\n   hiscore (for testing)\n";
    output += "Press Enter to return to the Main Menu...";
    cout << output;

    char input;
    string sInput;
    cin.get();
    int num = cin.gcount();
    if(num != 0)
        getline(cin, sInput);

    State *_menu = new StateMenu();
    return _menu;
}
