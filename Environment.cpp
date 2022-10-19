#include <iostream>

#include "Environment.hpp"
#include "Apple.hpp"

Environment::Environment() {
    whiteSpace = 0;
    ClearWindow();
    // for (int i = 0; i < HEIGHT; i++) {
    //     for (int j = 0; j < WIDTH; j++) {
    //         if (j == 0 && i!= 0) {
    //             window[i*WIDTH+j] = '|';
    //         } else if (j == WIDTH - 1 && i != 0) {
    //             window[i*WIDTH+j-1] = '|';
    //             window[i*WIDTH+j] = '\n';
    //         } else if (i == 0 || i == HEIGHT - 1) {
    //             window[i*WIDTH+j] = '_';
    //         } else {
    //             whiteSpace++;
    //         }
    //     }
    // }
}

Environment::~Environment() {

}

void Environment::AddSnake(Snake *snake) {
    for (auto const el: snake->snakePosition) {
        window[el] = 'X';
    }
    window[snake->snakePosition.at(0)] = '0';
}

void Environment::AddApple() {
    //apple->getApplePosition();
}

void Environment::ClearWindow() {
    window.fill(' ');
    for (int i = 0; i < HEIGHT; i++)
    {
        window[i*WIDTH] = '\n';
    }
}
void Environment::RefreshScreen(Snake *snake) {
    ClearWindow();
    snake->Direction();
    AddSnake(snake);
    system("clear");
    std::cout << "\033[2J\033[H";
    for (auto const el : window) {
        std::cout << el;
    }
}


bool Environment::PlayerOutOfBound() {
    return true;
}
