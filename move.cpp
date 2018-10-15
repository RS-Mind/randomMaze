/** ********************************************************************************
    RS_Mind
    9/21/18

    Overworld Movement
    Receives a directional input and modifies the player's coordinates accordingly.
****************************************************************************** * **/
#include <iostream>
#include <stdlib.h>
#include "map.h"
#include <vector>

using namespace std;

twoNumbers movement(int locationX, int locationY, int scale, std::vector< vector<char> >& walls, std::vector< vector<char> >& floors)
{
    char dir;
    int playerY;
    int playerX;

    playerX = locationX;
    playerY = locationY;

    cout << endl << endl << "\t\t\t\t" << endl << endl << "\t\t\t\t\t\t\t\t      N " << endl << "\t\t\t\t\t\t\t\t    W   E" << endl << "\t\t\t\t\t\t\t\t      S " << endl << "\t\t\t\t\t\t\t\t      ";

    cin >> dir;
    cin.get();

    if(dir == 'n' && !(floors[playerX][playerY-1] == '-')) //move north
    {
        playerY -= 1;
        if(playerY <= -1)
        {
            playerY += 1;
        }
    }

    if(dir == 'e' && !(walls[playerX][playerY] == '|')) //move east
    {
        playerX += 1;
        if(playerX >= scale)
        {
            playerX -= 1;
        }
    }

    if(dir == 's' && !(floors[playerX][playerY] == '-')) //move south
    {
        playerY += 1;
        if(playerY >= scale)
        {
            playerY -= 1;
        }
    }

    if(dir == 'w' && !(walls[playerX-1][playerY] == '|')) //move west
    {
        playerX -=1 ;
        if(playerX <= -1)
        {
            playerX += 1;
        }
    }

    return twoNumbers{playerX,playerY};
}
