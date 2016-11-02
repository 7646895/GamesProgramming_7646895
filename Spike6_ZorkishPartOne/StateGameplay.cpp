//
// Created by Jessica Vilaysak on 30/08/2016.
//

#include "StateGameplay.h"
#include "StateMenu.h"
#include "StateHighscore.h"

StateGameplay::StateGameplay()
{
    _name = "gameplay";
    _nextAction = "";
}

StateGameplay::~StateGameplay()
{
    delete _highscore;
    delete _player;
}

void StateGameplay::setWorld(string world)
{
    _world = world;
}

/*
 * There are two options for this state:
 * return to main menu (quit)
 * new high score (hiscore)
 */
string StateGameplay::commenceState()
{
    string output = "You have chosen the world "+_world+"\n";
    /*string output = "\nWelcome to Zorkish: "+_world+"\n";
    if(_world == "Cloudy Mountains")
    {
        output += "You have landed on top of the tallest Tibetan mountain! \nThere is a lone wolf on a peak to your left looking your way...\nThere's nothing for you to do here.\n:> ";
    }
    else if(_world == "Pyramids of Gyoza")
    {
        output += "BAM! You were hit by a gyoza! \nYou look around and there's a young boy holding hot gyozas in a bamboo basket.\nWhere are his parents you think to yourself...\n:> ";
    }*/

    TESTPLAYER();

    cout << endl;
    string input;
    cout << output;
    cin >> input;
    validateAction(input);

    if(_nextAction == "quit")
    {
        return "menu";
    }
    if(_nextAction == "hiscore")
    {
        _highscore->setValues(_world, _score, _moves);
        return "highscore";
    }

}

void StateGameplay::TESTPLAYER()
{
    cout << "Whats your name:> ";
    string input;
    cin >> input;
    _player->setName(input);
    int tempbreak = 0;

    while(tempbreak == 0)
    {
        input = "";
        cout << "What would you like to do [add, remove, list, quit]: ";
        cin >> input;
        if(input == "quit")
        {
            tempbreak = 1;
        }
        if(input == "add")
        {
            string name;
            cout << "What's the name of your new item: \n";
            cin >> name;
            string desc;
            cout << "Type a small description about your " << name << ": \n";
            cin >> desc;
            string extraDesc;
            getline(cin, extraDesc);
            Item *temp = new Item(name, desc+extraDesc);
            _player->addInventoryItem(temp);
            cout << "Your " << name << " has been added to your inventory :)\n";
        }
        else if(input == "remove")
        {
            _player->listInventory();
            cout << "Choose an item name: ";
            string itemname;
            cin >> itemname;
            _player->removeInventoryItem(itemname);
        }
        else if(input == "list")
        {
            if(_player->getInventoryCount() == 0)
            {
                cout << "There's nothing in your inventory right now..\n";
            }
            else
                _player->listInventory();
        }
        else
        {
            cout << "Invalid input....\n";
        }

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

void StateGameplay::setHighscoreObj(StateHighscore *highscore)
{
    _highscore = highscore;
}

void StateGameplay::setPlayer(Player *p)
{
    _player = p;
}

