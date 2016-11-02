#include <iostream>
#include "Commands/CommandController.h"
#include "GameHandler.h"
#include "Player.h"
#include <fstream>
#include "Graph.h"
#include "Node.h"
#include "Edge.h"
using namespace std;

int main() {
    GameHandler _handler;
    _handler.startGame();
/*

    Graph* graph = new Graph("Cloudy Mountains");
    Player* p = new Player();
    p->setCurrentLocation(graph->getStartingNode());

   // p->getCurrentLocation()->printDescription();
    CommandController cmd;
    int count = 0;
    while(count != 10)
    {
        cmd.run("Hello World", p);
        count++;
    }
*/



    return 0;
}

/*

*** convert string to lowercase ***
    for(int i=0; i<input.length(); i++)
    {
        lInput += tolower(input[i]);
    }





 */