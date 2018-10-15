#ifndef MAP
#define MAP
#include <vector>

struct twoNumbers
{
    int newX;
    int newY;
};

struct twoNumbers;
twoNumbers movement(int locationX, int locationY, int scale, std::vector< std::vector<char> >& walls, std::vector< std::vector<char> >& floors);
void render(int locationX, int locationY, int scale, std::vector< std::vector<char> >& walls, std::vector< std::vector<char> >& floors, std::vector< std::vector<char> >& grid);

#endif // MAP
