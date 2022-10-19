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
    int whiteSpace; // Amount of white space in the window (to spawn the apple)
    
    // Methods
    Environment();
    ~Environment();

    void AddSnake(Snake *snake);
    void AddApple();
    void ClearWindow();
    void RefreshScreen(Snake *snake);

private:
    bool PlayerOutOfBound(); 

};

#endif