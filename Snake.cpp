#include <conio.h>  // Console input/output
#include "Snake.hpp"
#include "Environment.hpp"

Snake::Snake() {

}

Snake::~Snake() {
}

void Snake::Spawn() {}

void Snake::Grow() {}

void Snake::Direction() {
    
}

void Snake::MoveRight() {
    snakePosition[0] = snakePosition[0] + 1;
}

void Snake::MoveLeft() {
    snakePosition[0] = snakePosition[0] - 1;
}

void Snake::MoveUp() {
    snakePosition[0] = snakePosition[0] - WIDTH;
}

void Snake::MoveDown() {
    snakePosition[0] = snakePosition[0] + WIDTH;
}

void Snake::Die() {}