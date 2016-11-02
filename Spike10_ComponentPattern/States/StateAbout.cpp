//
// Created by Jessica Vilaysak on 28/08/2016.
//

#include "StateAbout.h"
#include "StateMenu.h"

StateAbout::StateAbout()
{
    _name = "about";
}

string StateAbout::commenceState()
{
    string output = "";
    output += "Zorkish :: About\n";
    output += "-------------------------------------------\n\n";
    output += "Written by: Jessica Vilaysak\n";
    output += "Press Enter to return to the main menu\n";
    cout << output;

    char input;
    string sInput;
    cin.get();
    int num = cin.gcount();
    if(num != 0)
        getline(cin, sInput);

    return "menu";
}
