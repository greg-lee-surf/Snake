#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <vector>
#include <array>

#include "Snake.hpp"
#include "Apple.hpp"

#define WIDTH 60
#define HEIGHT 20

class Environment {
public:    
    // Attributs
    std::array<char,WIDTH*HEIGHT> window;
    std::vector<int> playerLocation;
    std::vector<int> appleLocation;
    
    // Methods
    Environment();
    ~Environment();

    void AddSnake(Snake *snake);
    void AddApple(Apple *apple, Snake *snake);
    void ClearWindow();
    void RefreshScreen(Snake *snake, Apple *apple);

private:
    bool PlayerOutOfBound(); 

};

#endif