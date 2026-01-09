#include "Food.h"
using namespace std;
void Food::gen_food()
{
    pos.X = (rand() % (WIDTH-3)) + 1;
    pos.Y = (rand() % (HEIGHT-3)) + 1;

}
void Food::hello(){}
COORD Food::get_pos(){return pos;}
Food::~Food()
{
    //dtor
}
