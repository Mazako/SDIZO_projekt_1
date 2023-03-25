#include <iostream>
#include "DynamicArray.h"


DynamicArray::DynamicArray() {
    this->array = new int[1];
    this->size = 0;
}

DynamicArray::~DynamicArray() {
    delete[] this->array;
}

void DynamicArray::add(int value) {
    array[size++] = value;
    DynamicArray::reallocate(size + 1);
}

int DynamicArray::remove(int index) {
    if (index < 0 || index >= size) {
        throw std::invalid_argument("Invalid array index");
    }
    int value = array[index];
    for (int i = index; i < size; i++) {
        array[i] = array[i + 1];
    }
    reallocate(--size);

    if (size > 0) {
        DynamicArray::reallocate(size);
    }
    return value;
}

int DynamicArray::reallocate(int newSize) {
    int *tmpArray = new int[newSize];
    int *oldArray = this->array;
    for (int i = 0; i < size; i++) {
        tmpArray[i] = array[i];
    }
    this->array = tmpArray;
    delete[] oldArray;
}

void DynamicArray::addAt(int index, int value) {
    if (index == size) {
        DynamicArray::add(value);
    } else if (index > size) {
        throw std::invalid_argument("Size of array is too big");
    } else {
        DynamicArray::reallocate(++size);
        for (int i = size - 1; i >= index; i--) {
            array[i + 1] = array[i];
        }
        array[index] = value;
    }
}

void DynamicArray::printArray() {
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
    }
    std::cout << std::endl;
}