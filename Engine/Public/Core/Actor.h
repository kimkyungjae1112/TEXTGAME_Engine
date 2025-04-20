#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "Object.h"
#include "Component.h"
#include <vector>
#include <memory>

class GameModeBase;
class PlayerController;

class Actor : public Object
{
public:
	Actor() = default;
	virtual ~Actor();

	void AddComponent(std::shared_ptr<Component> Comp);
	void BeginPlay();
	void OnTurn();

	GameModeBase* GetGameMode() const;
	PlayerController* GetController() const;

protected:
	std::vector<std::shared_ptr<Component>> Components;
};

#endif // !__ACTOR_H__
