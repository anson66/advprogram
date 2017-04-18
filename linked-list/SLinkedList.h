#ifndef SLINKEDLIST_H
#define SLINKEDLIST_H

#include <iostream>

using namespace std;

struct Node{
    const char* data;
    Node* next;
    Node(const char* data = NULL, Node* next = NULL)
    {
        this->data = data;
        this->next = next;
    }
};

struct SLinkedList {
    Node* head = NULL;

    void print() const;
    void addFirst(const char* data);
    const char* deleteFirst();
    const char * deleteLast();
};

#endif // SLINKEDLIST_H
