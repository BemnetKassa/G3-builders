#include <iostream>
#include <cstdlib>
#include <ctime>
#include <conio.h> // For _kbhit() and _getch()
#include <windows.h> // For Sleep()

using namespace std;


const int WIDTH = 20;
const int HEIGHT = 10;
const int MAX_SNAKE_LENGTH = 100;

enum Direction { STOP = 0, LEFT, RIGHT, UP, DOWN };

class SnakeGame {
private:
    int grid[HEIGHT][WIDTH]; 
    pair<int, int> snake[MAX_SNAKE_LENGTH];
    pair<int, int> food; 
    Direction dir;
    bool gameOver;
    int score;
    int snakeLength;


public:
    SnakeGame() {
        for (int i = 0; i < HEIGHT; ++i) {
            for (int j = 0; j < WIDTH; ++j) {
                grid[i][j] = 0;
            }
        }
        snake[0] = make_pair(WIDTH / 2, HEIGHT / 2);
        snakeLength = 1; 
        dir = STOP;
        gameOver = false;
        score = 0;
        placeFood();
    }

    void placeFood() {
        while (true) {
            int x = rand() % WIDTH;
            int y = rand() % HEIGHT;
            if (grid[y][x] == 0) {
                food = make_pair(x, y);
                break;
            }
        }
    }
