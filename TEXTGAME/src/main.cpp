#include <iostream>
#include "Util.h"
#include "Engine/Engine.h"
#include "Core/Actor.h"

int main()
{
    Engine& engine = Engine::CreateEngine();
    engine.Initialize();
    engine.Run();
    engine.Shutdown();

    Actor* MyActor = new Actor();
    MyActor->BeginPlay();

	return 0;
}