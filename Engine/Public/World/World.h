#ifndef __WORLD_H__
#define __WORLD_H__

#include "Core/Object.h"

class World
{
public:
	static void RegisterObject(const World* InWorld, Object* Obj);

	void BeginPlay();
	void OnTurn();

private:
	static std::vector<Object*> ObjectList;
};

#endif // !__WORLD_H__
