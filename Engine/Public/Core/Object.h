#ifndef __OBJECT_H__
#define __OBJECT_H__

#include <vector>
#include <memory>
#include <string>

class World;

class Object
{
public:
	Object() = default;
	virtual ~Object() = default;

	inline std::string GetName() const { return Name; }
	inline void SetName(const std::string& InName) { Name = InName; }

	virtual void BeginPlay();
	virtual void OnTurn();
	
	World* GetWorld() const;


private:
	std::string Name = "UnnamedObject";

};

#endif // !__OBJECT_H__
