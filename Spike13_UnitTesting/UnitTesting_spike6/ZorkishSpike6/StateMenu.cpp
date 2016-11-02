//
// Created by Jessica Vilaysak on 28/08/2016.
//

#include "StateMenu.h"
#include "StateAbout.h"
#include "StateExit.h"
#include "StateHelp.h"
#include "StateSelectworld.h"
#include "StateHallOfFame.h"

StateMenu::StateMenu()
{
    _name = "menu";
}

string StateMenu::commenceState()
{
    int userInput = 0;
    string output = "\n";
    output += "Zorkish :: Main Menu\n";
    output += "------------------------------------------------------\n";
    output += "\nWelcome to Zorkish Adventures\n";
    while(userInput == 0)
    {
        output += "\n   1. Select Adventure and Play\n";
        output += "   2. Hall Of Fame\n";
        output += "   3. Help\n";
        output += "   4. About\n";
        output += "   5. Quit\n";
        output += "\nSelect 1-5:>> ";
        cout << output;
        string input;
        cin >> input;
        userInput = validateInput(input);
        output = "";

        if(userInput == 0)
            cout << "You have made an invalid selection. \nHere's the menu for you again...\n";
    }

    switch(userInput)
    {
        case 1: {
            return "select world";
        }
        case 2: {
            return "hall of fame";
        }
        case 3: {
            return "help";
        }
        case 4: {
            return "about";
        }
        case 5: {
            return "exit";
        }
    }
    cout << "Returning to the main menu now...\n";
    return "menu";
}

int StateMenu::validateInput(string input)
{
    int inputnum = input.at(0) - '0';
    switch(inputnum)
    {
        case 1:
       /* case 2:
        case 3:
        case 4:*/
        case 5:
            return inputnum;
        default:
            return 0;
    }
}
