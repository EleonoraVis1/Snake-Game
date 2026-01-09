#ifndef FOODFACTORY_H_INCLUDED
#define FOODFACTORY_H_INCLUDED
#include "Food.h"
#include "factory.h"

class FoodFactory : public ComponentFactory {
public:
    Component* create();
};

#endif // FOODFACTORY_H_INCLUDED
