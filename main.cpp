#include <iostream>
#include <conio.h>
#include <ctime>
#include <fstream>
#include "Snake.h"
#include "Food.h"
#include "FoodFactory.h"
#include "SnakeFactory.h"

using namespace std;

ComponentFactory* snakeFactory = new SnakeFactory();
ComponentFactory* foodFactory = new FoodFactory();
Snake* snake = (Snake*)snakeFactory->create();
Food* food = (Food*)foodFactory->create();
int score = 0;
void saveScore(int score, string name);
void board()
{
    COORD snake_pos = snake->get_pos();
    COORD food_pos = food->get_pos();

    vector<COORD> snake_body = snake->get_body();

    cout << "\nSCORE: " << score << "\n\n";
    for(int i = 0; i < HEIGHT; ++i)
    {
        cout << "\t\t#";
        for(int j = 0; j < WIDTH - 2; ++j)
        {
            if(i == 0 || i == HEIGHT - 1) cout << '#';
            else if(i == snake_pos.Y && j + 1 == snake_pos.X) cout << '0';
            else if(i == food_pos.Y && j + 1 == food_pos.X) cout << '*';
            else
            {
                bool is_body_part = false;
                for(int k = 0; k < snake_body.size() - 1; ++k)
                {
                    if(i == snake_body[k].Y && j + 1 == snake_body[k].X)
                    {
                        cout << 'o';
                        is_body_part = true;
                        break;
                    }
                }
                if(!is_body_part) cout << ' ';
            }
        }
        cout << "#\n";
    }
}


int main()
{
    string name;
    srand(time(NULL));
    food->gen_food();
    bool game_over = false;
    cout << "Iveskite varda: ";
    cin >> name;
    SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    while(!game_over)
    {
        board();
        if(kbhit())
        {
            switch(getch())
            {
                case 'w': snake->change_dir('u'); break;
                case 's': snake->change_dir('d'); break;
                case 'a': snake->change_dir('l'); break;
                case 'd': snake->change_dir('r'); break;
            }

        }
        if(snake->collided()) game_over = true;
        if(snake->eaten(food->get_pos()))
        {
            food->gen_food();
            snake->grow();
            ++score;
        }

        snake->move_snake();
        SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), {0, 0});
    }

    saveScore(score, name);
    delete snakeFactory;
    delete foodFactory;
    delete snake;
    delete food;
}

void saveScore(int score, string name) {
    ofstream file("scores.txt", ios::app);
    if(file.is_open()) {
        file << name <<": " << score << endl;
        file.close();
    } else {
        cerr << "Failed to open file." << endl;
    }
}
