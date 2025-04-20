#include "Game/GameModeBase.h"
#include "World/World.h"
#include <iostream>

GameModeBase::GameModeBase(World* InWorld) : GameWorld(InWorld)
{
}

GameModeBase::~GameModeBase() = default;

void GameModeBase::Update()
{
	GameWorld->Tick();
}

void GameModeBase::Render()
{
	std::cout << "[World State Rendered Here]\n";
}
