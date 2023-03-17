#include <iostream>
#include "DoubleLinkedList.h"

DoubleLinkedList::~DoubleLinkedList() {
    while (head != nullptr) {
        Node *previous = head;
        head = head->next;
        delete previous;
    }
}

//COMPLEXITY: O(N)
void DoubleLinkedList::push(int data) {
    Node *node = new Node(data);
    if (head == nullptr) {
        head = node;
        size++;
        return;
    }
    Node *nodePtr = head;
    while (nodePtr->next != nullptr) {
        nodePtr = nodePtr->next;
    }
    nodePtr->next = node;
    node->previous = nodePtr;
    size++;
}

//COMPLEXITY: O(N)
int DoubleLinkedList::pop() {
    if (size == 0) {
        throw std::logic_error("List empty");
    }
    if (size == 1) {
        int data = head->data;
        delete head;
        head = nullptr;
        return data;
    }
    Node *nodePtr = head;
    while (nodePtr->next->next != nullptr) {
        nodePtr = nodePtr->next;
    }
    int data = nodePtr->next->data;
    delete nodePtr->next;
    nodePtr->next = nullptr;
    size--;
    return data;
}

void DoubleLinkedList::printList() {
    auto *nodePtr = head;
    while (nodePtr != nullptr) {
        std::cout << nodePtr->data << " ";
        nodePtr = nodePtr->next;
    }
    std::cout << std::endl;
}

void DoubleLinkedList::printReversed() {
    auto *nodePtr = head;
    if (nodePtr == nullptr) {
        return;
    }
    while (nodePtr->next != nullptr) {
        nodePtr = nodePtr->next;
    }
    while (nodePtr != nullptr) {
        std::cout << nodePtr->data << " ";
        nodePtr = nodePtr->previous;
    }
    std::cout << std::endl;

}

//COMPLEXITY O(1)
int DoubleLinkedList::shift() {
    if (size == 0) {
        throw std::invalid_argument("Empty erray");
    }

    int data = head->data;
    if (head->next == nullptr) {
        delete head;
        head = nullptr;
    } else {
        Node *headPtr = head;
        head = head->next;
        head->previous = nullptr;
        delete headPtr;
    }
    size--;
    return data;

}

// COMPLEXITY: O(1)
void DoubleLinkedList::unshift(int data) {
    Node *newNode = new Node(data);
    if (head == nullptr) {
        head = newNode;
    } else {
        newNode->next = head;
        head->previous = newNode;
        head = newNode;
    }
}

//COMPLEXITY: O(N)
void DoubleLinkedList::addAt(int index, int data) {
    if (index > size) {
        throw std::invalid_argument("List index out of bound");
    }
    if (index == 0) {
        unshift(data);
        return;
    }
    Node *newNode = new Node(data);
    Node *headPtr = head;
    for (int i = 0; i < index - 1; i++) {
        headPtr = headPtr->next;
    }
    if (headPtr->next == nullptr) {
        headPtr->next = newNode;
        newNode->previous = headPtr;
    } else {
        headPtr->next->previous = newNode;
        newNode->next = headPtr->next;
        newNode->previous = headPtr;
        headPtr->next = newNode;
    }
    size++;
}

//COMPLEXITY: O(N)
int DoubleLinkedList::removeAt(int index) {
    if (index >= size) {
        throw std::invalid_argument("List index out of range");
    }
    int data;
    if (index == 0) {
        return shift();
    }
    Node *nodePtr = head;
    for (int i = 0; i < index - 1; i++) {
        nodePtr = nodePtr->next;
    }
    if (nodePtr->next->next == nullptr) {
        data = pop();
    } else {
        nodePtr->next->next->previous = nodePtr;
        Node *nodeToRemove = nodePtr->next;
        nodePtr->next = nodePtr->next->next;
        data = nodeToRemove->data;
        delete nodeToRemove;
        size--;
    }
    return data;
}
