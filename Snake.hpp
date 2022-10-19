#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>

class Snake{
public:   
    // Attributs
    enum dir {Right, Left, Up, Down} snakeDirection;
    std::string snakeName; // Player name
    unsigned short snakeSize; // The score/size of the snake
    std::vector<int> snakePosition; // Head is snakePosition[0]
    std::vector<int> bufferPosition; // Buffer for moving the snake


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

private:
    std::vector<int> SavePreviousPos();
    void UpdatePos();
    void UpdateDir();
};


#endif