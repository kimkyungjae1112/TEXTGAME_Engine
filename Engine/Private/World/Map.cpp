#include "World/Map.h"
#include <iostream>

Map::Map(int Width, int Height) 
	: Width(Width), Height(Height), PlayerX(0), PlayerY(0)
{
	Grid.resize(Height, std::vector<char>(Width, '.'));
}

void Map::SetPlayerPosition(int X, int Y)
{
    PlayerX = X;
    PlayerY = Y;
}

std::vector<std::string> Map::GetMapLines() const
{
    std::vector<std::string> Lines;
    Lines.push_back("[ ¹Ì´Ï¸Ê ]");

    for (int y = 0; y < Height; ++y)
    {
        std::string row;
        for (int x = 0; x < Width; ++x)
        {
            if (x == PlayerX && y == PlayerY)
                row += "@ ";
            else
                row += std::string(1, Grid[y][x]) + " ";
        }
        Lines.push_back(row);
    }

    return Lines;
}

