#include "SLinkedList.h"
#include <iostream>

using namespace std;

void SLinkedList::print() const
    {
        cout << "list: ";
        for (Node *p = head; p!=NULL; p=p->next) {
            cout << p->data << " ";
        }
        cout << endl;
    }
    void SLinkedList::addFirst(const char* data) {
        Node* newNode = new Node(data, head);
        head = newNode;
    }
    const char* SLinkedList::deleteFirst()
    {
        if (head != NULL) {
            const char* data = head->data;
            Node* deletedNode = head;
            head = head->next;
            delete deletedNode;
            return data;
        }
        return NULL;
    }

    const char * SLinkedList::deleteLast()
    {
        if (head == NULL)
            return NULL;
        else if (head->next == NULL)
        {
            const char* data = head->data;
            delete head;
            head = NULL;
            return data;
        }
        else
        {
            Node* p = head;
            while (p->next->next != NULL) p = p->next;
            //now p is new end node
            Node* deletedNode = p->next;
            const char* data = deletedNode->data;
            delete deletedNode;
            p->next = NULL;
            return data;
        }
    }
