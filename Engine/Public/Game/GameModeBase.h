#ifndef __GAMEMODEBASE_H__
#define __GAMEMODEBASE_H__

class World;

class GameModeBase
{
public:
    GameModeBase(World* InWorld);
    virtual ~GameModeBase();

    virtual void Update();
    virtual void Render();

protected:
    World* GameWorld;
};

#endif // !__GAMEMODEBASE_H__
