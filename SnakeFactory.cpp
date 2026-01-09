#include "SnakeFactory.h"
Component* SnakeFactory::create() {
    return new Snake();
}
