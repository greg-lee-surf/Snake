#ifndef ENVIRONMENT_HPP
#define ENVIRONMENT_HPP

#include <iostream>
#include <vector>
#include <array>

#define WIDTH 60
#define HEIGHT 20

class Environment {
    
    // Attributs
    std::array<char,WIDTH*HEIGHT> window;
    std::vector<int> playerLocation;
    std::vector<int> appleLocation;

    // Methods
    Environment();
    ~Environment();

    void RefreshScreen();


};

#endif