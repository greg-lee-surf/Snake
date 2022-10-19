#include <iostream>

#include "Environment.hpp"
#include "Apple.hpp"

Environment::Environment() {
    ClearWindow();
}

Environment::~Environment() {

}

void Environment::AddSnake(Snake *snake) {
    for (auto const el: snake->position) {
        window[el] = 'X';
    }
    window[snake->position.at(0)] = '0';
}

void Environment::AddApple(Apple *apple, Snake *snake) {
    int applePos = apple->getApplePosition() % (WIDTH*HEIGHT); // Apple inside of the window
    // std::vector<int> snakePos = snake->position();
    // if (applePos % WIDTH == 0 || applePos % WIDTH == 1) { // not in a wall
    //     applePos = (applePos + 2) % (WIDTH*HEIGHT);
    // for ()
    window[applePos] = 'Q'; // Q is an apple
}

void Environment::ClearWindow() {
    window.fill(' ');
    for (int i = 0; i < HEIGHT; i++) {
        for (int j = 0; j < WIDTH; j++) {
            if (j == 0 && i!= 0) {
                window[i*WIDTH+1] = '*';
            } else if (j == WIDTH - 1 && i != 0) {
                window[i*WIDTH+j] = '*';
                window[i*WIDTH+j+1] = '\n';
            } else if (i == 0 || i == HEIGHT - 1) {
                window[i*(WIDTH-3)+j] = '*'; 
            }
        }
    window[i*WIDTH] = '\n';
    }
}

void Environment::RefreshScreen(Snake *snake, Apple *apple) {
    ClearWindow();
    snake->Direction();
    AddSnake(snake);
    AddApple(apple, snake);
    system("clear");
    std::cout << "\033[2J\033[H";
    for (auto const el : window) {
        std::cout << el;
    }
}


bool Environment::PlayerOutOfBound() {
    return true;
}