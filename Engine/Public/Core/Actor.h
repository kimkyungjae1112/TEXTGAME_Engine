#ifndef __ACTOR_H__
#define __ACTOR_H__

#include "Object.h"
#include "Component.h"
#include "Math/Vector.h"

class GameModeBase;
class PlayerController;

class Actor : public Object
{
public:
	Actor() = default;
	virtual ~Actor();

	virtual void AddComponent(std::shared_ptr<Component> Comp);
	virtual void BeginPlay() override;
	virtual void OnTurn() override;

	GameModeBase* GetGameMode() const;
	PlayerController* GetController() const;

public:
	inline Vector GetActorLocation() const { return Location; }
	inline void SetActorLocation(const Vector& InLocation) { Location = InLocation; }

protected:
	std::vector<std::shared_ptr<Component>> Components;

protected:
	Vector Location{ 0,0 };
};

#endif // !__ACTOR_H__
