#include <iostream>

#include "Environment.hpp"
#include "Apple.hpp"

Environment::Environment() {
    ClearWindow();
}

Environment::~Environment() {

}

void Environment::AddSnake(Snake *snake) {
    for (auto const el: snake->getPosition()) {
        window[el] = 'X';
    }
    window[snake->getPosition().at(0)] = '0';
}

void Environment::SnakeEatsApple(Snake *snake, Apple *apple) {
    if (apple->getPosition() % (WIDTH*HEIGHT) == snake->getPosition().at(0)) {
        snake->setEatingState(true);
    }
}

void Environment::AddApple(Apple *apple, Snake *snake) {
    SnakeEatsApple(snake, apple);
    int applePos = SpawnApple(apple); // Apple inside of the window
    window[applePos] = 'Q'; // Q is an apple
}

int Environment::SpawnApple(Apple *apple) {
    int applePos = apple->getPosition() % (WIDTH*HEIGHT); // Apple inside of the window
    while (window[applePos] != ' ') {
        apple->Respawn();
        applePos = apple->getPosition() % (WIDTH*HEIGHT);
    }
    return applePos;
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
            } else if (i == 0) {
                window[i*(WIDTH)+j] = '*'; 
            } else if (i == HEIGHT - 1) {
                window[i*(WIDTH-3) + j - 2] = '*';
            }
        }
    window[i*WIDTH] = '\n';
    }
}

void Environment::RefreshScreen(Snake *snake, Apple *apple) {
    ClearWindow();
    keepPlaying = !PlayerOutOfBound(snake);
    snake->Direction();
    AddSnake(snake);
    AddApple(apple, snake);
    system("clear");
    std::cout << "\033[2J\033[H";
    ScoreBanner(snake); 
    for (auto const el : window) {
        std::cout << el;
    }
}


bool Environment::PlayerOutOfBound(Snake *snake) {
    if (window[snake->getPosition().front()] == '*') {
        return true;
    }
    if (snake->Die()) {
        return true;
    }
    return false;
}

void Environment::ScoreBanner(Snake *snake) {
    std::cout << "\n  Score : " << snake->getSize() - 5 << std::endl;
}   

