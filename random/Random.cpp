//
// Created by micha on 07.03.2023.
//

#include <cstdlib>
#include <ctime>
#include "Random.h"
int Random::getRandomInt() {
    std::srand((unsigned ) std::time(NULL));
    return std::rand();
}
