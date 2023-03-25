#ifndef SDIZO_PROJ_1_MAXHEAP_H
#define SDIZO_PROJ_1_MAXHEAP_H


class MaxHeap {
private:
    int size;
    int *array;

    static inline int parent(int i);

    static inline int leftChild(int i);

    static inline int rightChild(int i);

    static void swap(int *a, int *b);

    void heapify(int i);

    void reallocate(int newSize);

public:
    MaxHeap();

    MaxHeap(int *array, int n);

    ~MaxHeap();

    int getMax();

    void insert(int data);

    int removeMax();

    int getSize();

    void printHeap();

};


#endif //SDIZO_PROJ_1_MAXHEAP_H
