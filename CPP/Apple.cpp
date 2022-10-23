#include <stdlib.h> // rand() 

#include "Apple.hpp"

Apple::Apple() {
    position = rand();
}

void Apple::Respawn() {
    position = rand();
}

int Apple::getPosition() {
    return position;
}
void Apple::setPosition(int _position) {
    position = _position;
}