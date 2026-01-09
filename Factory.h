#ifndef FACTORY_H_INCLUDED
#define FACTORY_H_INCLUDED
#include "Component.h"
class ComponentFactory
{
public:
    virtual Component* create() = 0;
};

#endif // FACTORY_H_INCLUDED
