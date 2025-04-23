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

void Map::DrawMiniMap() const
{
    std::cout << "[ �̴ϸ� ]\n";
    for (int y = 0; y < Height; ++y)
    {
        for (int x = 0; x < Width; ++x)
        {
            if (x == PlayerX && y == PlayerY)
                std::cout << '@'; // �÷��̾� ��ġ
            else
                std::cout << Grid[y][x];
        }
        std::cout << "\n";
    }
}