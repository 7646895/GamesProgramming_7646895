//
// Created by Jessica Vilaysak on 30/08/2016.
//

#include "StateSelectworld.h"
#include "StateGameplay.h"

StateSelectworld::StateSelectworld()
{
    _name = "select world";
    getWorldList();
}

string StateSelectworld::commenceState()
{
    string output = "\n";
    output += "Zorkish :: Select Adventure\n";
    output += "-------------------------------------------\n\n";

    int world = 0;
    string input;
    while(world == 0)
    {
        output += "Choose your adventure: \n\n";
        cout << output;
        printWorldList();

        cin >> input;
        world = validateWorld(input);
        if(world == 0)
            cout << "YOu chose an invalid option. Here are the options again:\n";
        output = "";
    }

    _game->setWorld(_world);

    return "gameplay";
}

int StateSelectworld::validateWorld(string input)
{
    int inputnum = input.at(0) - '0';
    if(inputnum > _numWorlds)
    {
        return 0;
    }
    int vCount = 0;
    for(auto i=_worldList.begin(); i!=_worldList.end(); i++)
    {
        vCount++;
        if(vCount == inputnum)
        {
            _world = (*i);
            return 1;
        }
    }
}

void StateSelectworld::setGame(StateGameplay *game)
{
    _game = game;
}

StateSelectworld::~StateSelectworld()
{
    delete _game;
}

void StateSelectworld::getWorldList()
{
    ifstream worldList("worldlist.txt");
    string worldName;
    vector<string> worldVector;
    int count = 0;
    if(worldList.is_open())
    {
        while(getline(worldList, worldName))
        {
            worldVector.push_back(worldName);
            count++;
        }
    }
    _numWorlds = count;
    _worldList = worldVector;
}

void StateSelectworld::printWorldList()
{
    int count = 0;
    for(auto i=_worldList.begin(); i!=_worldList.end(); i++)
    {
        count++;
        cout << "   " << count << ". " << (*i) << endl;
    }
    cout << "Select 1-" << count << ":> ";
}