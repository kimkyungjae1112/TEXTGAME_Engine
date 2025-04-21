#include "Engine/Engine.h"
#include <iostream>

Engine& Engine::CreateEngine()
{
    static Engine InitEngine;
    if (InitEngine.Initialize())
    {
        return InitEngine;
    }
    Engine DumpEngine;
    return DumpEngine;
}

bool Engine::Initialize()
{
    std::cout << "Initializing Engine...\n";
    GameWorld = new World();
    GameMode = new GameModeBase(GameWorld);
    Controller = new PlayerController();

    bIsRunning = true;
    bIsBeforeRun = true;

    if (GameWorld && GameMode && Controller) return true;
    else return false;
}

void Engine::Run()
{
    std::cout << "Starting Game Loop...\n";
    while (bIsBeforeRun)
    {
        Render();
        if (Input == "게임시작")
        {
            bIsBeforeRun = false;
            break;
        }
        ProcessInput();
    }

    GameWorld->BeginPlay();

    while (bIsRunning)
    {
        ProcessInput();
        OnTurn();
        Render();
    }
}

void Engine::Shutdown()
{
    std::cout << "Shutting down Engine...\n";
    delete GameWorld;
    delete GameMode;
    delete Controller;
}

void Engine::ProcessInput()
{
    bIsRunning = Controller->HandleInput(Input);
}

void Engine::OnTurn()
{
    GameMode->OnTurn();
}

void Engine::Render()
{
    GameMode->Render(Input);
}

