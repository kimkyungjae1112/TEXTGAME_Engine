#include "Core/Actor.h"
#include "Engine/Engine.h"

Actor::~Actor() = default;

void Actor::AddComponent(std::shared_ptr<Component> Comp)
{
    Components.push_back(Comp);
}

void Actor::BeginPlay()
{
    for (auto& comp : Components) comp->Start();
}

void Actor::OnTurn()
{
    for (auto& comp : Components) comp->Update();
}

GameModeBase* Actor::GetGameMode() const
{
    return Engine::CreateEngine().GetGameMode();
}

PlayerController* Actor::GetController() const
{
    return Engine::CreateEngine().GetController();
}

