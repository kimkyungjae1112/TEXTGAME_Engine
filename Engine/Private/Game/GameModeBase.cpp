#include "Game/GameModeBase.h"
#include "World/World.h"
#include <iostream>
#include <Windows.h>

GameModeBase::GameModeBase(World* InWorld) : GameWorld(InWorld)
{
	bIsBeforeRun = true;
}

GameModeBase::~GameModeBase() = default;

void GameModeBase::OnTurn()
{
	GameWorld->OnTurn();
}

void GameModeBase::Render(std::string Input)
{
	if (bIsBeforeRun)
	{
		if (Input == "���ӽ���")
		{
			bIsBeforeRun = false;
		}
		else if (Input == "��������")
		{
			exit(0);
		}
		else
		{
			std::cout << "[MainMenu]\n";
			return;
		}
	}


	std::cout << "[World State Rendered Here]\n";
}


