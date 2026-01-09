#include "FoodFactory.h"
Component* FoodFactory::create() {
    return new Food();
}
