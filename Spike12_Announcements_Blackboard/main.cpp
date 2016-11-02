#include <iostream>
#include "GameHandler.h"
using namespace std;

int main() {
    GameHandler _game;
    _game.startGame();
    return 0;
}


/*

    TO ITERATE OVER A MULTIMAP

    multimap<char,int> firs;

    firs.insert(pair<char, int>('a', 12));
    firs.insert(pair<char, int>('a', 20));

    multimap<char, int>::iterator it;

    for(it=firs.begin(); it!=firs.end(); it++)
    {
        cout << it->first << ": " << it->second<< endl;
    }


    TO CONVERT INT TO STRING
    string input = '2';
    int inputnum = input.at(0) - '0';

 */