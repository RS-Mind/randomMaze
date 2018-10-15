/** *********************************************************************************************************
    RS_Mind
    9/21/18

    Overworld Concept
    Renders a map that a player can navigate in into the console. Intended to be used in other functions.
********************************************************************************************************* **/
#include <iostream>
#include <stdlib.h>
#include <vector>
using namespace std;

extern char grid[21][21];

void render(int locationX, int locationY, int scale, std::vector< vector<char> >& walls, std::vector< vector<char> >& floors, std::vector< vector<char> >& grid)
{
    int renderX; //initialize variables
    int renderY;
    int playerX;
    int playerY;

    playerX = locationX; //set default values
    playerY = locationY;

    system("CLS"); //Clear the console
    renderX = 0; //Set the render vars to 0
    renderY = 0;

    cout << "\t\t\t\t+----";
    for(int i = 2; i < scale; i++)
    {
        cout << "----";
    }
    cout << "---+";

    while (renderY <= (scale - 1)) ///Render
    {
        cout << endl << "\t\t\t\t|";
        while (renderX <= (scale - 1))
        {
            if(renderX == playerX && renderY == playerY)
            {
                cout << grid[renderX][renderY] << "@" << grid[renderX][renderY]; //Player location
                if (renderX <= (scale - 2))
                {
                    cout << walls[renderX][renderY];
                }
            }
            else
            {
                cout << grid[renderX][renderY] << grid[renderX][renderY] << grid[renderX][renderY];
                if (renderX <= (scale - 2))
                {
                    cout << walls[renderX][renderY];
                }
            }
            renderX += 1;
        }
        cout << "|";
        renderX = 0;
        if (renderY <= (scale - 2))
        {
            cout << endl << "\t\t\t        |";
            while(renderX <= (scale - 1))
            {
                cout << floors[renderX][renderY]<< floors[renderX][renderY] << floors[renderX][renderY];
                if(renderX <= (scale - 2))
                {
                    cout << "+";
                }
                renderX += 1;
            }
            cout << "|";
        }
        renderX = 0;
        renderY += 1;
    } ///Render end
    cout << endl << "\t\t\t\t+----";
    for(int i = 2; i < scale; i++)
    {
        cout << "----";
    }
    cout << "---+";
    return;
}
