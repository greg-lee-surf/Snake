#ifndef SNAKE_HPP
#define SNAKE_HPP

#include <vector>

class Snake{

    // Attributs
    enum dir {Right, Left, Up, Down} direction;
    std::string name; // Player name
    unsigned short size; // The score/size of the snake
    std::vector<int> position; // Head is position[0]
    std::vector<int> bufferPosition; // Buffer for moving the snake
    bool isEating = false; // If the snake just ate an apple, he is growing

    // Methods
public:
    // Constructors
    Snake();
    Snake(std::string _name);
    Snake(std::string _name, int _size);

    // Destructor
    ~Snake();

    void Direction();
    void MoveRight();
    void MoveLeft();
    void MoveUp();
    void MoveDown();
    void Eat();
    bool Die();

    // Setters
    void setDirection(dir _direction);
    void setName(std::string _name);
    void setSize(unsigned short _size);
    void setPosition(std::vector<int> _position);
    void setBufferPosition(std::vector<int> _bufferPosition);
    void setEatingState(bool _isEating);

    // Getters
    dir getDirection();
    std::string getName();
    unsigned short getSize();
    std::vector<int> getPosition();
    std::vector<int> getBufferPosition();
    bool getEatingState();

private:
    std::vector<int> SavePreviousPos();
    void UpdatePos();
    void UpdateDir();
};

#endif