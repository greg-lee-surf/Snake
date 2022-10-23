#ifndef APPLE_HPP
#define APPLE_HPP

class Apple {
    // Attributs
    int position;

    // Methods
public:
    Apple();
    //~Apple();
    void Respawn();
    int getPosition();
    void setPosition(int _position);
};

#endif