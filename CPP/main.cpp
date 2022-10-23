#include <iostream>
#include <vector>
#include <array>
#include <string>
#include <unistd.h>

#include "Snake.hpp"
#include "Environment.hpp"


int main() {
    Snake *snake = new Snake();
    Apple *apple = new Apple();
    Environment *env = new Environment();
    env->AddSnake(snake);
    env->AddApple(apple, snake);
    while (env->keepPlaying) {
        env->RefreshScreen(snake, apple);
        usleep(10e4);
    }

    std::cout << "\nYou lost, loooooooser!" << std::endl;

    return 0;
}