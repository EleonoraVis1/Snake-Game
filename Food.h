#ifndef FOOD_H
#define FOOD_H
#include <windows.h>
#include <cstdlib>
#define WIDTH 50
#define HEIGHT 25
#include "Component.h"
using namespace std;
class Food : public Component
{
private:
    COORD pos;
public:
    void gen_food();
    COORD get_pos();
    void hello();
    ~Food();
};

#endif // FOOD_H
