#include "Core/Pawn.h"
#include <iostream>

Pawn::~Pawn()
{
}

void Pawn::AddComponent(std::shared_ptr<Component> Comp)
{
}

void Pawn::BeginPlay()
{
	std::cout << "Pawn's BeginPlay" << std::endl;
	for (auto& comp : Components) comp->Start();
}

void Pawn::OnTurn()
{
	std::cout << "Pawn's OnTurn" << std::endl;
	for (auto& comp : Components) comp->Update();
}
