#ifndef SNAKEFACTORY_H_INCLUDED
#define SNAKEFACTORY_H_INCLUDED
#include "Snake.h"
#include "factory.h"
#include "Component.h"
class SnakeFactory : public ComponentFactory {
public:
    Component* create();
};

#endif // SNAKEFACTORY_H_INCLUDED
