#include <iostream>
#include "Util.h"
#include "Engine/Engine.h"
#include "Core/Pawn.h"
#include "World/World.h"

int main()
{
    Pawn* MyActor = new Pawn();
    World::RegisterObject(MyActor->GetWorld(), MyActor);

    Engine& engine = Engine::CreateEngine();
    engine.Initialize();
    engine.Run();
    engine.Shutdown();
    

	return 0;
}