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
	std::cout << "[���尡 ���ŵ�]\n";
	for (auto Obj : ObjectList) Obj->OnTurn();
}
