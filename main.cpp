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
    Apple *apple = new Apple();
    Environment *env = new Environment();
    env->AddSnake(snake);
    env->AddApple(apple, snake);
    while (true) {
        env->RefreshScreen(snake, apple);
        usleep(10e4);
    }


    return 0;
}