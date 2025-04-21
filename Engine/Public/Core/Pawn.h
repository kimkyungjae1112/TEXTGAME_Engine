#ifndef __PAWN_H__
#define __PAWN_H__

#include "Actor.h"

class Pawn : public Actor
{
public:
	Pawn() = default;
	virtual ~Pawn();

	virtual void AddComponent(std::shared_ptr<Component> Comp);
	virtual void BeginPlay() override;
	virtual void OnTurn() override;
};


#endif // !__PAWN_H__

