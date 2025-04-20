#ifndef __OBJECT_H__
#define __OBJECT_H__
#include <string>

class World;

class Object
{
public:
	Object() = default;
	virtual ~Object() = default;

	virtual std::string GetName() const { return Name; }

	World* GetWorld() const;


private:
	std::string Name = "UnnamedObject";

};

#endif // !__OBJECT_H__
