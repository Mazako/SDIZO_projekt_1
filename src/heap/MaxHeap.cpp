#include <iostream>
#include <valarray>
#include "MaxHeap.h"

int MaxHeap::parent(int i) { return (i - 1) / 2; }

int MaxHeap::leftChild(int i) { return 2 * i + 1; }

int MaxHeap::rightChild(int i) { return 2 * i + 2; }

void MaxHeap::swap(int *a, int *b) {
    int tmp = *a;
    *a = *b;
    *b = tmp;
}

MaxHeap::MaxHeap() {
    this->size = 0;
    this->array = nullptr;
}

MaxHeap::~MaxHeap() {
    delete[] this->array;
}

void MaxHeap::reallocate(int newSize) {
    int *tmpArray = nullptr;

    if (newSize > 0) {
        tmpArray = new int[newSize];
        for (int i = 0; i < newSize; i++) {
            tmpArray[i] = array[i];
        }
    }

    if (this->array != nullptr) {
        delete[] this->array;
    }

    this->array = tmpArray;
    this->size = newSize;
}

int MaxHeap::getMax() { return array[0]; }

void MaxHeap::insert(int data) {
    if (size == 0) {
        array = new int[1];
        array[0] = data;
        size++;
        return;
    }
    reallocate(size + 1);
    int i = size - 1;
    array[i] = data;
    while (i > 0 && array[parent(i)] < array[i]) {
        swap(&array[parent(i)], &array[i]);
        i = parent(i);
    }
}

void MaxHeap::printHeap() {
    if (size == 0) {
        std::cout << "Kopiec jest pusty" << std::endl;
        return;
    }

    int currentLevel = 0;
    int elementsInCurrentLevel = 1;
    int elementsPrinted = 0;

    for (int i = 0; i < size; ++i) {
        std::cout << array[i] << " ";

        ++elementsPrinted;

        if (elementsPrinted == elementsInCurrentLevel) {
            std::cout << std::endl;

            ++currentLevel;
            elementsInCurrentLevel = std::pow(2, currentLevel);
            elementsPrinted = 0;
        } else {
            std::cout << " ";
        }
    }

    std::cout << std::endl;
}

void MaxHeap::heapify(int i) {
    int left = leftChild(i);
    int right = rightChild(i);
    int largest = i;
    if (left < size && array[left] > array[largest]) {
        largest = left;
    }
    if (right < size && array[right] > array[largest]) {
        largest = right;
    }

    if (largest != i) {
        swap(&array[i], &array[largest]);
        heapify(largest);
    }
}

int MaxHeap::removeMax() {
    if (size == 0) {
        throw std::logic_error("Heap is empty");
    }
    int data = array[0];

    array[0] = array[size - 1];
    reallocate(size - 1);
    heapify(0);
    return data;
}

MaxHeap::MaxHeap(int *array, int n) {
    this->size = n;
    this->array = array;
    for (int i = n / 2; i >= 0; i--) {
        heapify(i);
    }
}

int MaxHeap::getSize() {
    return this->size;
}

