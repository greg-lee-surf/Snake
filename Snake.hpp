#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <vector>
#include <string>
#include <array>

class Snake{
    
    // Attributs
    std::string name; // Player name
    unsigned short size; // The score/size of the snake
    std::vector<unsigned short> snakePosition;

    // Methods
    
    // Constructors
    Snake();
    Snake(std::string _name);
    Snake(std::string _name, int _size);

    // Destructors
    ~Snake();

    // Public methods
public:
    void Spawn();
    void Grow();
    void Direction();
    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();
    void Die();
};


#endif