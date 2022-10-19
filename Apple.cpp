#include <stdlib.h> // rand() 

#include "Apple.hpp"

Apple::Apple() {
    applePosition = rand();
}

int Apple::getApplePosition() {
    return applePosition;
}