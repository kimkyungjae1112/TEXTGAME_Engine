#ifndef __COMPONENT_H__
#define __COMPONENT_H__

class Component : public Object
{
public:
    Component() = default;

    virtual void Start() {}
    virtual void Update() {}
};

#endif // !__COMPONENT_H__
