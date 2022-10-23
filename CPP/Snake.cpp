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
    Eat(); // Is the snake eating?
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
    position.at(0) = position.at(0) + WIDTH;
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
}

void Snake::Eat() {
    if(getEatingState() == true) {
        setSize(getSize() + 1);
        position.push_back(*position.end());
        isEating = false;
    }
}

bool Snake::Die() {
    for (auto body {std::begin(position) + 1}; body != std::end(position); body++) {
        if (*body == position.front()) {
            return true;
        }
    }
    return false;
}

// Setters
void Snake::setDirection(dir _direction) {
    direction = _direction;
}
void Snake::setName(std::string _name) {
    name = _name;
}

void Snake::setSize(unsigned short _size) {
    size = _size;
}

void Snake::setPosition(std::vector<int> _position) {
    position = _position;
}

void Snake::setBufferPosition(std::vector<int> _bufferPosition) {
    bufferPosition = _bufferPosition;
}

void Snake::setEatingState(bool _isEating) {
    isEating = _isEating;
}


// Getters
Snake::dir Snake::getDirection() {
    return direction;
}

std::string Snake::getName() {
    return name;
}

unsigned short Snake::getSize() {
    return size;
}

std::vector<int> Snake::getPosition() {
    return position;
}

std::vector<int> Snake::getBufferPosition() {
    return bufferPosition;
}

bool Snake::getEatingState() {
    return isEating;
}


void Snake::UpdateDir() {
    if (_kbhit()) { // something is happening !!
        if (getch() == '\033') { // if the first value is esc
            getch(); // skip the [
            switch(getch()) { // the real value
                case 'A':
                    if (direction != Down) {
                        direction = Up;// code for arrow up
                        break;
                    }
                case 'B':
                    if (direction != Up) {
                        direction = Down; // code for arrow down
                        break;
                    }
                case 'C':
                    if (direction != Left) {
                        direction = Right; // code for arrow right
                        break;
                    }
                case 'D':
                    if (direction != Right) {
                        direction = Left; // code for arrow left
                        break;
                    }
            }
        }
    }
}
