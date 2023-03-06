#ifndef SDIZO_PROJ_1_DYNAMICARRAY_H
#define SDIZO_PROJ_1_DYNAMICARRAY_H


class DynamicArray {
private:
    int size;
    int *array;

    int reallocate(int newSize);

public:
    void add(int value);

    void addAt(int index, int value);

    int remove(int index);

    DynamicArray();

    ~DynamicArray();

    void printArray();
};


#endif //SDIZO_PROJ_1_DYNAMICARRAY_H
