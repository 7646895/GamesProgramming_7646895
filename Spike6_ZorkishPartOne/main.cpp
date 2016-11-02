#include <iostream>
#include "GameHandler.h"
using namespace std;

int main() {
    GameHandler _gameHandler;
    _gameHandler.startGame();
    return 0;
}

/*
For 'press enter to continue' use:

    char input;
    string sInput;
    cin.get();
    int num = cin.gcount();
    if(num != 0)
        getline(cin, sInput);

 */