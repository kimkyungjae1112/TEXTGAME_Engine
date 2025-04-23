#ifndef __MAP_H__
#define __MAP_H__

#include <vector>
#include <string>

class Map
{
public:
    Map(int Width, int Height);

    void SetPlayerPosition(int X, int Y);
    std::vector<std::string> GetMapLines() const;

private:
    int Width;
    int Height;
    int PlayerX;
    int PlayerY;
    std::vector<std::vector<char>> Grid;
};

#endif // __MAP_H__
