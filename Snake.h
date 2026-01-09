#ifndef SNAKE_H
#define SNAKE_H
#include <windows.h>
#include <vector>
#include "Component.h"
using namespace std;
class Snake : public Component
{
private:
    COORD pos;
    int len;
    int vel;
    char direction;
    vector<COORD> body;
public:
    Snake();
    Snake(COORD pos, int vel);
    void change_dir(char dir);
    void move_snake();
    vector<COORD> get_body();
    COORD get_pos();
    void hello();
    bool eaten(COORD food_pos);
    void grow();
    bool collided();
    ~Snake();
};

#endif // SNAKE_H
