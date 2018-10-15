/** **********************************************************************
    RS_Mind
    9/21/18

    Random Maze
    Renders a randomized maze into the console that a player can navigate
********************************************************************** **/

#include <iostream>
#include <stdlib.h>
#include "map.h"
#include <cstdlib>
#include <time.h>
#include <vector>

using namespace std;

void *__gxx_personality_v0;

void mazeGenerator (int scale, vector< vector<char> >& walls, vector< vector<char> >& floors)
{
    cout << "Generating maze..." << endl;
    vector< vector<int> > wallGen(scale*2, vector<int>(scale));
    for(int i = 0; i < scale*2; i++)
    {
        for(int j = 0; j < scale; j++)
        {
            wallGen[i][j] = 0;
        }
    }

    vector< vector<int> > wallTag(scale*2, vector<int>(scale));
    for(int i = 0; i < scale*2; i++)
    {
        for(int j = 0; j < scale; j++)
        {
            wallTag[i][j] = 0;
        }
    }

    vector< vector<int> > mazeGen(scale*2, vector<int>(scale));
    for(int i = 0; i < scale; i++)
    {
        for(int j = 0; j < scale; j++)
        {
            mazeGen[i][j] = 0;
        }
    }

    int genX;
    int genY;
    int random;
    vector <int> activeWallX;
    vector <int> activeWallY;

    genX = rand()%scale;
    genY = rand()%scale;

    mazeGen[genX][genY] = 1;

    if(genY < scale-1) //Bottom Floor Coords
    {
        activeWallX.push_back(genX);
        activeWallY.push_back(genY);
        wallTag [genX][genY] = 1;
    }

    if(genY > 0) //Top Floor Coords
    {
        activeWallX.push_back(genX);
        activeWallY.push_back(genY-1);
        wallTag [genX][genY-1] = 1;
    }

    if(genX < scale-1) //Right Wall Coords
    {
        activeWallX.push_back(genX+scale);
        activeWallY.push_back(genY);
        wallTag [genX+scale][genY] = 1;
    }

    if(genX > 0) //Left Wall Coords
    {
        activeWallX.push_back(genX+scale-1);
        activeWallY.push_back(genY);
        wallTag [genX+scale-1][genY] = 1;
    }

    int listSize = static_cast<int>(activeWallX.size());

    while(listSize > 0)
    {
        random = rand()%listSize;
        genX = activeWallX [random];
        genY = activeWallY [random];

        activeWallX.erase(activeWallX.begin() + random);
        activeWallY.erase(activeWallY.begin() + random);

        if(genX < scale)
        {
            if(mazeGen[genX][genY] == 0) //Top Cell
            {
                mazeGen[genX][genY] = 1;
                wallGen[genX][genY] = 1;

                if(genY > 0 && wallTag[genX][genY-1] == 0) //Top Floor Coords
                {
                    activeWallX.push_back(genX);
                    activeWallY.push_back(genY-1);
                    wallTag [genX][genY-1] = 1;
                }

                if(genX < scale-1 && wallTag[genX+scale][genY] == 0) //Right Wall Coords
                {
                    activeWallX.push_back(genX+scale);
                    activeWallY.push_back(genY);
                    wallTag [genX+scale][genY] = 1;
                }

                if(genX > 0 && wallTag[genX+scale-1][genY] == 0) //Left Wall Coords
                {
                    activeWallX.push_back(genX+scale-1);
                    activeWallY.push_back(genY);
                    wallTag [genX+scale-1][genY] = 1;
                }
            }
            else if (mazeGen[genX][genY+1] == 0) //Bottom Cell
            {
                mazeGen[genX][genY+1] = 1;
                wallGen[genX][genY] = 1;

                if(genY < scale-1 && wallTag[genX][genY+1] == 0) //Bottom Floor Coords
                {
                    activeWallX.push_back(genX);
                    activeWallY.push_back(genY+1);
                    wallTag [genX][genY+1] = 1;
                }

                if(genX < scale-1 && wallTag[genX+scale][genY+1] == 0) //Right Wall Coords
                {
                    activeWallX.push_back(genX+scale);
                    activeWallY.push_back(genY+1);
                    wallTag [genX+scale][genY+1] = 1;
                }

                if(genX > 0 && wallTag[genX+scale-1][genY+1] == 0) // Left Wall Coords
                {
                    activeWallX.push_back(genX+scale-1);
                    activeWallY.push_back(genY+1);
                    wallTag [genX+scale-1][genY+1] = 1;
                }
            }
        }
        else
        {
            genX -= scale;

            if(mazeGen[genX][genY] == 0) //Left Cell
            {
                mazeGen[genX][genY] = 1;
                wallGen[genX+scale][genY] = 1;

                if(genY > 0 && wallTag[genX][genY-1] == 0) //Top Floor Coords
                {
                    activeWallX.push_back(genX);
                    activeWallY.push_back(genY-1);
                    wallTag [genX][genY-1] = 1;
                }

                if(genY < scale-1 && wallTag[genX][genY] == 0) //Bottom Floor Coords
                {
                    activeWallX.push_back(genX);
                    activeWallY.push_back(genY);
                    wallTag [genX][genY] = 1;
                }

                if(genX > 0 && wallTag[genX+scale-1][genY] == 0) //Left Wall Coords
                {
                    activeWallX.push_back(genX+scale-1);
                    activeWallY.push_back(genY);
                    wallTag [genX+scale-1][genY] = 1;
                }
            }
            else if (mazeGen[genX+1][genY] == 0) //Right Cell
            {
                mazeGen[genX+1][genY] = 1;
                wallGen[genX+scale][genY] = 1;

                if(genY < scale-1 && wallTag[genX+1][genY] == 0) //Bottom Floor Coords
                {
                    activeWallX.push_back(genX+1);
                    activeWallY.push_back(genY);
                    wallTag [genX+1][genY] = 1;
                }

                if(genX < scale-1 && wallTag[genX+scale+1][genY] == 0) //Right Wall Coords
                {
                    activeWallX.push_back(genX+scale+1);
                    activeWallY.push_back(genY);
                    wallTag [genX+scale+1][genY] = 1;
                }

                if(genY > 0 && wallTag[genX+1][genY-1] == 0) //Top Floor Coords
                {
                    activeWallX.push_back(genX+1);
                    activeWallY.push_back(genY-1);
                    wallTag [genX+1][genY-1] = 1;
                }
            }
        }
        listSize = static_cast<int>(activeWallX.size());
    }

    int buildX = 0;
    int buildY = 0;

    while(buildY < scale-1)
    {
        while(buildX < scale)
        {
            if(wallGen[buildX][buildY] == 1)
            {
                floors [buildX][buildY] = ' ';
            }
            buildX += 1;
        }
        buildY += 1;
        buildX = 0;
    }

    buildY = 0;

    while(buildY < scale)
    {
        while(buildX < scale-1)
        {
            if(wallGen[buildX+scale][buildY] == 1)
            {
                walls[buildX][buildY] = ' ';
            }
            buildX += 1;
        }
        buildY += 1;
        buildX = 0;
    }
}

int main()
{
    while(true)
    {
        srand(time(NULL));
        int scale = 0;
        char ent = 'n';
        char ext = 'n';
        int exitX = 0;
        int exitY = 0;
        int playerX = -1;
        int playerY = -1;

        while(scale < 2)
        {
            cin.clear();
            fflush(stdin);
            cout << "\t\t\t\tGrid size: ";
            cin >> scale;
        }

        cout << endl << "\t\t\t\tRandom entrance (y/n): ";
        cin >> ent;

        if(ent == 'y')
        {
            playerX = rand()%scale;
            playerY = rand()%scale;
        }
        else
        {
            while(playerX < 0 || playerX >= scale || playerY > 0 || playerY >= scale)
            {
                cout << endl << "\t\t\t\tEntrance X: ";
                cin >> playerX;
                cout << endl << "\t\t\t\tEntrance Y: ";
                cin >> playerY;
            }
        }

        cout << endl << "\t\t\t\tRandom exit (y/n): ";
        cin >> ext;

        vector< vector<char> > grid(scale, vector<char>(scale));
        for(int i = 0; i < scale; i++)
        {
            for(int j = 0; j < scale; j++)
            {
                grid[i][j] = ' ';
            }
        }

        if(ext == 'y')
        {
            grid [rand()%scale][rand()%scale] = '!';
        }
        else
        {
            while(exitX < 0 || exitX >= scale || exitY < 0 || exitY >= scale)
            {
                cout << endl << "\t\t\t\tExit X: ";
                cin >> exitX;
                cout << endl << "\t\t\t\tExit Y: ";
                cin >> exitY;
            }
            grid [exitX][exitY] = '!';
        }

        vector< vector<char> > walls(scale, vector<char>(scale));
        for(int i = 0; i < scale-1; i++)
        {
            for(int j = 0; j < scale; j++)
            {
                walls[i][j] = '|';
            }
        }

        vector< vector<char> > floors(scale, vector<char>(scale));
        for(int i = 0; i < scale; i++)
        {
            for(int j = 0; j < scale-1; j++)
            {
                floors[i][j] = '-';
            }
        }

        mazeGenerator(scale, walls, floors);

        while(true)
        {
            render(playerX,playerY,scale,walls,floors,grid);
            cin.clear();
            fflush(stdin);
            //cout << " (" << playerX << "," << playerY << ")" << endl;
            twoNumbers result = movement(playerX,playerY,scale,walls,floors);
            playerX = result.newX;
            playerY = result.newY;

            if(grid[playerX][playerY] == '!')
            {
                render(playerX,playerY,scale,walls,floors,grid);
                return 1;
            }
        }

    }

    return 0;
}
