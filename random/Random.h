#ifndef SDIZO_PROJ_1_RANDOM_H
#define SDIZO_PROJ_1_RANDOM_H


class Random {
public:
    static int getRandomInt();
    static int getRandomInt(int max);
    static int getRandomInt(int min, int max);
    static int* getRandomIntArray(int* array, int min, int max);
    static int* getRandomIntArray(int* array)
};


#endif //SDIZO_PROJ_1_RANDOM_H
