#include "World/World.h"
#include <iostream>

std::vector<Object*> World::ObjectList;

void World::RegisterObject(const World* InWorld, Object* Obj)
{
	InWorld->ObjectList.push_back(Obj);
}

void World::BeginPlay()
{
	for (auto Obj : ObjectList) Obj->BeginPlay();
}

void World::OnTurn()
{
	std::cout << "[월드가 갱신됨]\n";
	for (auto Obj : ObjectList) Obj->OnTurn();
}
