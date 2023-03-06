//
// Created by micha on 06.03.2023.
//

#include "Node.h"

Node::Node() {
    this->next = nullptr;
    this->previous = nullptr;
}

Node::Node(int data) {
    this->next = nullptr;
    this->previous = nullptr;
    this->data = data;
}
