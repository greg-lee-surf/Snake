#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>

class Snake{
public:   
    // Attributs
    enum dir {Right, Left, Up, Down} direction;
    std::string name; // Player name
    unsigned short size; // The score/size of the snake
    std::vector<int> position; // Head is position[0]
    std::vector<int> bufferPosition; // Buffer for moving the snake
    bool isEating = false; // If the snake just ate an apple, he is growing

    // Methods
    // Constructors
    Snake();
    Snake(std::string _name);
    Snake(std::string _name, int _size);

    // Destructors
    ~Snake();

    // Public methods
public:
    void Direction();
    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();
    void Eat();
    bool Die();


private:
    std::vector<int> SavePreviousPos();
    void UpdatePos();
    void UpdateDir();
};


#endif