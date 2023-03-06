#include <iostream>
#include "DoubleLinkedList.h"

DoubleLinkedList::~DoubleLinkedList() {
    while (head != nullptr) {
        Node* previous = head;
        head = head->next;
        delete previous;
    }
}

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

int DoubleLinkedList::pop() {
    if (size == 0) {
        throw std::logic_error("List empty");
    }
    if (size == 1) {
        int data = head->data;
        delete head;
        return data;
    }
    Node* nodePtr = head;
    while (nodePtr->next->next != nullptr) {
        nodePtr = nodePtr->next;
    }
    int data = nodePtr->next->data;
    delete nodePtr->next;
    nodePtr->next = nullptr;
    return data;
}

void DoubleLinkedList::printList() {
    auto* nodePtr = head;
    while (nodePtr != nullptr) {
        std::cout << nodePtr->data << " ";
        nodePtr = nodePtr->next;
    }
    std::cout << std::endl;
}

void DoubleLinkedList::printReversed() {
    auto* nodePtr = head;
    while (nodePtr->next != nullptr) {
        nodePtr = nodePtr->next;
    }
    while (nodePtr != nullptr) {
        std::cout << nodePtr->data << " ";
        nodePtr = nodePtr->previous;
    }
    std::cout << std::endl;

}
