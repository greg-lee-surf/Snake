#include <conio.h>  // Console input/output
#include <string>
#include <iostream>
#include "Snake.hpp"
#include "Environment.hpp"

Snake::Snake() {
    snakeDirection = Right;
    snakeSize = 5;
    snakePosition.push_back(WIDTH*(HEIGHT/2) + WIDTH/2);
    for (int i = 0; i < snakeSize; i++) {
        snakePosition.push_back(snakePosition[i] - 1);
    }
}

Snake::~Snake() {
}

void Snake::Spawn() {}

void Snake::Grow() {}

void Snake::Direction() {
    bufferPosition = SavePreviousPos();
    UpdateDir(); 
    if (snakeDirection == Right) {
        MoveRight();
    } else if (snakeDirection == Left) {
        MoveLeft();
    } else if (snakeDirection == Up) {
        MoveUp();
    } else if (snakeDirection == Down) {
        MoveDown();
    }
    UpdatePos();
}

void Snake::MoveRight() {
    snakePosition.at(0) = snakePosition.at(0) + 1;
}

void Snake::MoveLeft() {
    snakePosition.at(0) = snakePosition.at(0) - 1;
}

void Snake::MoveUp() {
    snakePosition.at(0) = snakePosition.at(0) - WIDTH;
}

void Snake::MoveDown() {
    bufferPosition = SavePreviousPos();
    snakePosition.at(0) = snakePosition.at(0) + WIDTH;
}


void Snake::Die() {}

std::vector<int> Snake::SavePreviousPos() {
    std::vector<int> buffer;
    buffer.resize(snakePosition.size());
    for (int i = 0; i < snakeSize; i++) {
        buffer.at(i) = snakePosition.at(i);
    }
    return buffer;
}

void Snake::UpdatePos() {
    for (int i = 0; i < snakeSize - 1; i++) {
        snakePosition.at(i+1) = bufferPosition.at(i);
    }
}

void Snake::UpdateDir() {
    if (_kbhit()) { // something is happening !!
        if (getch() == '\033') { // if the first value is esc
            getch(); // skip the [
            switch(getch()) { // the real value
                case 'A':
                    snakeDirection = Up;// code for arrow up
                    break;
                case 'B':
                    snakeDirection = Down; // code for arrow down
                    break;
                case 'C':
                    snakeDirection = Right; // code for arrow right
                    break;
                case 'D':
                    snakeDirection = Left;// code for arrow left
                    break;
            }
        }
    }
}
