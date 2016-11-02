//
// Created by Jessica Vilaysak on 30/08/2016.
//

#include "StateSelectworld.h"
#include "StateGameplay.h"

StateSelectworld::StateSelectworld()
{
    _name == "selectworld";
}

State* StateSelectworld::commenceState()
{
    string output = "\n";
    output += "Zorkish :: Select Adventure\n";
    output += "-------------------------------------------\n\n";

    int world = 0;
    string input;
    while(world == 0)
    {
        output += "Choose your adventure: \n\n";
        output += "   1. Cloudy Mountains\n";
        output += "   2. Pyramids of Gyoza\n\n";
        output += "Select 1-2:> ";
        cout << output;

        cin >> input;
        world = validateWorld(input);
        if(world == 0)
            cout << "YOu chose an invalid option. Here are the options again:\n";
        output = "";
    }

    State *_game;
    switch(world)
    {
        case 1:
        {
            _game = new StateGameplay("Cloudy Mountains");
            break;
        }
        case 2:
        {
            _game = new StateGameplay("Pyramids of Gyoza");
            break;
        }
    }
    return _game;
}

int StateSelectworld::validateWorld(string input)
{
    int inputnum = input.at(0) - '0';
    switch(inputnum)
    {
        case 1:
        case 2:
            return inputnum;
        default:
            return 0;
    }

}