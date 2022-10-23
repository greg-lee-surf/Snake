#include <stdlib.h> // rand() 

#include "Apple.hpp"

Apple::Apple() {
    applePosition = rand();
}

void Apple::Respawn() {
    applePosition = rand();
}

int Apple::getApplePosition() {
    return applePosition;
}