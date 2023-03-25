#include <iostream>
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
    delete this->array;
}

void MaxHeap::reallocate(int newSize) {
    if (newSize == 0) {
        this->size--;
        return;
    }
    int *tmpArray = new int[newSize];
    for (int i = 0; i < size; i++) {
        tmpArray[i] = array[i];
    }
    int *arrayPtr = array;
    this->array = tmpArray;
    delete arrayPtr;
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
    for (int i = 0; i < size; i++) {
        std::cout << array[i] << " ";
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
        new std::logic_error("Stack is empty");
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

