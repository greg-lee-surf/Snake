#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unistd.h>

#include "Snake.hpp"

#define WIDTH 60
#define HEIGHT 20



int main() {
    std::array<char,HEIGHT*WIDTH> window;
    window.fill(' ');
    std::string snake = "====0";
    unsigned short snakeSize = snake.length();
    std::array<unsigned short,2> snakePosition; // Tail and Head position

    // snakePosition[0] = 5 * WIDTH + 5;
    // snakePosition[1] = snakePosition[0] + snakeSize - 1;


    // Initialize the snake in the canvas
    // for (int i = 0; i < snakeSize - 1; i++){
    //     window[snakePosition[0]+i] = '=';
    // }
    // window[snakePosition[1]] = '0';

    // Move up
    snakePosition[0] = snakePosition[0] - WIDTH; // Tail
    // Move right
    snakePosition[0] = snakePosition[0] + 1; // Tail
    // Move left
    snakePosition[0] = snakePosition[0] - 1; // Tail
    // Move down
    snakePosition[0] = snakePosition[0] + WIDTH; // Tail
    
    window[snakePosition[0]] = '0';
    // snakePosition[1] = snakePosition[0] + snakeSize - WIDTH - 1; // Head


    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0 && i!= 0) {
                window[i*WIDTH+j] = '|';
            } else if (j == WIDTH - 1 && i != 0) {
                window[i*WIDTH+j-1] = '|';
                window[i*WIDTH+j] = '\n';
            } else if (i == 0 || i == HEIGHT - 1) {
                window[i*WIDTH+j] = '_';
            }
        }
    }

    // window.insert(10 * (WIDTH+1) + 1, snake);
    while (true) {
        if (system("CLS")) system("clear");
        std::cout << "\033[2J\033[H";
        for (auto const el : window) {
            std::cout << el;
        }
        usleep(10e5);
    }


    return 0;
}