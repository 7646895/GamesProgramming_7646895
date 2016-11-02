#include <time.h>
#include <iostream>
#include <streambuf>
#include <thread>
using namespace std;

char pInput = ' ';

void getInput()
{
    cin >> pInput;
}

bool gameEnd = 0;
int playerRow = 7;
int playerCol = 2;
string playerStatus;
char playerInput;
string consoleText;
char moveArray[4];

char gridArray[8][8] =
        {{'#', '#', '#', '#', '#', '#', '#', '#'},
         {'#', 'G', ' ', 'D', '#', 'D', ' ', '#'},
         {'#', ' ', ' ', '#', '#', ' ', ' ', '#'},
         {'#', '#', ' ', '#', '#', ' ', 'D', '#'},
         {'#', ' ', ' ', '#', '#', ' ', ' ', '#'},
         {'#', ' ', '#', '#', '#', '#', ' ', '#'},
         {'#', ' ', ' ', ' ', ' ', ' ', ' ', '#'},
         {'#', '#', 'S', '#', '#', '#', '#', '#'}};

void drawGrid()
{
    for(int a=0; a<8; a++)
    {
        for(int b=0; b<8; b++)
        {
            if((a == playerRow) & (b == playerCol))
                cout << "X";
            else
                cout << gridArray[a][b];
            if(b==7)
                cout << endl;

        }
    }
}

void input()
{
    for(int c=0; c<4; c++)
    {
        moveArray[c] = 0;
    }
    if(playerRow == 7)
    {
        moveArray[0] = 'N';
        cout << "You can move N:> ";
    }
    else
    {
        int i = 0;
        //right
        if(gridArray[playerRow][playerCol+1] != '#')
        {
            moveArray[i] = 'W';
            i++;
        }
        //down
        if(gridArray[playerRow+1][playerCol] != '#')
        {
            moveArray[i] = 'S';
            i++;
        }
        //left
        if(gridArray[playerRow][playerCol-1] != '#')
        {
            moveArray[i] = 'E';
            i++;
        }
        //up
        if(gridArray[playerRow-1][playerCol] != '#')
        {
            moveArray[i] = 'N';
            i++;
        }
        string output = "You can move ";
        for(int x=i-1; x>=0; x--)
        {
            output += moveArray[x];
            if(x!=0)
                output += ", ";
        }
        output += ":> ";
        cout << output;
    }

    thread first(getInput);

    clock_t start_time = clock();
    clock_t timer;

    while (pInput == ' ')
    {
        if(pInput != ' ')
            break;
        timer = clock() - start_time;
        if(timer > 2700000)
        {
            start_time = clock();
            string output = "\nYou're taking sooOOoOOo long...\n";
            cout << output;
        }
    }
    first.join();
    first.~thread();
    playerInput = pInput;
    pInput = ' ';
}

void update()
{
    if(tolower(playerInput) == 'q')
    {
        consoleText = "You have quit! Thanks for playing :)\n";
        gameEnd = 1;
        return;
    }
    bool check = 0;
    for(int i=0; i<4; i++)
    {
        //cout << moveArray[i] << ", " << playerInput << ", " << check << endl;
        if(tolower(moveArray[i]) == tolower(playerInput))
        {
            consoleText = "";
            check = 1;
        }
    }
    if(check == 0)
    {
        consoleText = "That's an invalid move.\n";
        playerStatus = "wrongmove";
        return;
    }
    switch(tolower(playerInput))
    {
        case 'n':
            playerRow--;
            break;
        case 's':
            playerRow++;
            break;
        case 'e':
            playerCol--;
            break;
        case 'w':
            playerCol++;
            break;
    }
    if((playerRow == 1)&(playerCol == 1))
    {
        playerStatus = "won";
        consoleText = "Wow - you've discovered a large chest filled with GOLD coins !\nYOU WIN!\nThanks for playing. There probably won't be a next time.\n";
        gameEnd = 1;
    }
    if( ((playerRow == 1)&(playerCol == 3)) | ((playerRow == 1)&(playerCol == 5)) | ((playerRow == 3)&(playerCol == 6)))
    {
        playerStatus = "lost";
        consoleText = "Arrrrgh... you've fallen down a pit.\nYOU HAVE DIED!\nThanks for playing. Maybe next time.\n";
        gameEnd = 1;
    }
}

void render()
{
    if((playerStatus == "wrongmove") | (gameEnd == 1))
    {
        playerStatus = "";
    }
    else
        drawGrid();
    cout << consoleText;
}

int main (int argc, char *argv[])
{
    cout << "Welcome to GridWorld: Quantised Excitement. Fate is waiting for You!\nWhat's your name: ";
    string playerName;
    cin >> playerName;
    cout << "Hi there, " << playerName << endl;
    cout << "Valid commands: N, S, E and W for direction. Q to quit the game.\nThe X represents your position.\n\n";
    drawGrid();
    while (!gameEnd)
    {
        input();
        update();
        render();
    }

    return 0;
}




