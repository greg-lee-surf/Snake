#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unistd.h>

#include "Snake.hpp"
#include "Environment.hpp"

#define WIDTH 60
#define HEIGHT 20

int main() {
    Snake *snake = new Snake();
    Environment *env = new Environment();
    env->AddSnake(snake);
    // std::array<char,HEIGHT*WIDTH> window;
    // window.fill(' ');
    // std::string snake = "====0";
    // unsigned short snakeSize = snake.length();
    // std::array<unsigned short,2> snakePosition; // Tail and Head position

    // snakePosition[0] = 5 * WIDTH + 5;
    // snakePosition[1] = snakePosition[0] + snakeSize - 1;


    // Initialize the snake in the canvas
    // for (int i = 0; i < snakeSize - 1; i++){
    //     window[snakePosition[0]+i] = '=';
    // }
    // window[snakePosition[1]] = '0';

    // Move up
    // snakePosition[0] = snakePosition[0] - WIDTH; // Tail
    // // Move right
    // snakePosition[0] = snakePosition[0] + 1; // Tail
    // // Move left
    // snakePosition[0] = snakePosition[0] - 1; // Tail
    // // Move down
    // snakePosition[0] = snakePosition[0] + WIDTH; // Tail
    
    // window[snakePosition[0]] = '0';
    // // snakePosition[1] = snakePosition[0] + snakeSize - WIDTH - 1; // Head


    // window.insert(10 * (WIDTH+1) + 1, snake);
    while (true) {
        env->RefreshScreen(snake);
        usleep(10e4);
    }


    return 0;
}