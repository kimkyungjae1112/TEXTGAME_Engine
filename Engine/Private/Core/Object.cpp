#include "Core/Object.h"
#include "World/World.h"
#include "Engine/Engine.h"

World* Object::GetWorld() const
{
    return Engine::CreateEngine().GetWorld();
}
