#include "Core/Object.h"
#include "World/World.h"
#include "Engine/Engine.h"

void Object::BeginPlay()
{
}

void Object::OnTurn()
{
}

World* Object::GetWorld() const
{
    return Engine::CreateEngine().GetWorld();
}
