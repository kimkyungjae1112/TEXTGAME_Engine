#ifndef __GAMEMODEBASE_H__
#define __GAMEMODEBASE_H__

#include <string>
#include <vector>

class World;
class Map;
class Slate;

class GameModeBase
{
public:
    GameModeBase(World* InWorld);
    virtual ~GameModeBase();

    virtual void OnTurn();
    virtual void Render(std::string Input);

protected:
    World* GameWorld;
    Map* GameMap;
    Slate* SlatePopup;

private:
    void GetConsoleSize(int& Width, int& Height);
    void DrawConsoleBox(const std::vector<std::string>& InnerLines);
    void DrawCenteredText(const std::string& Text);

private:
    bool bIsBeforeRun{ false };
};

#endif // !__GAMEMODEBASE_H__
