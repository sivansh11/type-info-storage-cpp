#ifndef COMPONENTMANAGER_H
#define COMPONENTMANAGER_H

#include "mypch.h"
#include "type.h"

class ComponentManager
{
public:
    ComponentManager() {}
    ~ComponentManager() {}

    void registerComponentType(std::string componentName, BaseType* type)
    {
        map[componentName] = type;
    }
    BaseType* getComponentType(std::string componentName)
    {
        return map[componentName];
    }
private:
    std::unordered_map<std::string, BaseType*> map;
};

#endif