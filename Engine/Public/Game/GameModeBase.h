#ifndef __GAMEMODEBASE_H__
#define __GAMEMODEBASE_H__

#include <string>

class World;

class GameModeBase
{
public:
    GameModeBase(World* InWorld);
    virtual ~GameModeBase();

    virtual void OnTurn();
    virtual void Render(std::string Input);

protected:
    World* GameWorld;

private:
    bool bIsBeforeRun{ false };
};

#endif // !__GAMEMODEBASE_H__
