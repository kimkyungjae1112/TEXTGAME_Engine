#ifndef __ENGINE_H__
#define __ENGINE_H__
#include <string>
class GameModeBase;
class PlayerController;
class World;

class Engine
{
public:
	static Engine& CreateEngine();

	bool Initialize();
	void Run();
	void Shutdown();

	inline void SetGameMode(GameModeBase* InGameMode) { GameMode = InGameMode; }

	inline GameModeBase* GetGameMode() const { return GameMode; }
	inline PlayerController* GetController() const { return Controller; }
	inline World* GetWorld() const { return GameWorld; }

private:
	Engine() = default;
	Engine(const Engine&) = default;
	Engine& operator=(const Engine&) = default;
	~Engine() {};

	void ProcessInput();
	void OnTurn();
	void Render();


	GameModeBase* GameMode;
	PlayerController* Controller;
	World* GameWorld;
	std::string Input;
	bool bIsRunning = false;
	bool bIsBeforeRun = false;
};

#endif // !__ENGINE_H__
