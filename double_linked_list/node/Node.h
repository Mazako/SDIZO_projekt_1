#ifndef SDIZO_PROJ_1_NODE_H
#define SDIZO_PROJ_1_NODE_H


class Node {
public:
    int data;
    Node *next;
    Node* previous;

    Node();
    Node(int data);
};


#endif //SDIZO_PROJ_1_NODE_H
