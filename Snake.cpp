#include <conio.h>  // Console input/output
#include <string>
#include <iostream>
#include "Snake.hpp"
#include "Environment.hpp"

Snake::Snake() {
    direction = Right;
    size = 5;
    position.push_back(WIDTH*(HEIGHT/2) + WIDTH/2);
    for (int i = 0; i < size - 1; i++) {
        position.push_back(position[i] - 1);
    }
}

Snake::~Snake() {
}

void Snake::Direction() {
    bufferPosition = SavePreviousPos();
    UpdateDir(); 
    if (direction == Right) {
        MoveRight();
    } else if (direction == Left) {
        MoveLeft();
    } else if (direction == Up) {
        MoveUp();
    } else if (direction == Down) {
        MoveDown();
    }
    UpdatePos();
}

void Snake::MoveRight() {
    position.at(0) = position.at(0) + 1;
}

void Snake::MoveLeft() {
    position.at(0) = position.at(0) - 1;
}

void Snake::MoveUp() {
    position.at(0) = position.at(0) - WIDTH;
}

void Snake::MoveDown() {
    bufferPosition = SavePreviousPos();
    position.at(0) = position.at(0) + WIDTH;
}


void Snake::Die() {
}

std::vector<int> Snake::SavePreviousPos() {
    std::vector<int> buffer;
    buffer.resize(position.size());
    for (int i = 0; i < size; i++) {
        buffer.at(i) = position.at(i);
    }
    return buffer;
}

void Snake::UpdatePos() {
    for (int i = 0; i < size - 1; i++) {
        position.at(i+1) = bufferPosition.at(i);
    }
    if (isGrowing) {
        position.push_back(bufferPosition.at(size - 1)); // Growing snake
    }
}

void Snake::UpdateDir() {
    if (_kbhit()) { // something is happening !!
        if (getch() == '\033') { // if the first value is esc
            getch(); // skip the [
            switch(getch()) { // the real value
                case 'A':
                    direction = Up;// code for arrow up
                    break;
                case 'B':
                    direction = Down; // code for arrow down
                    break;
                case 'C':
                    direction = Right; // code for arrow right
                    break;
                case 'D':
                    direction = Left;// code for arrow left
                    break;
            }
        }
    }
}
