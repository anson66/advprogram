#include <iostream>
#include "SLinkedList.h"

using namespace std;

int main() {
    SLinkedList list;
    /*list.print();  // ''
    list.head = new Node("1");
    list.print();  // 1
    Node* secondNode = new Node("2");
    list.head->next = secondNode;
    list.print();  // 1 2*/

    list.addFirst("first");
    list.print();   // expect: first
    list.addFirst("second");
    list.print();   // expect: second first

    cout << "Delete last. Expected: 'second'\n";
    const char * dat = list.deleteLast();
    list.print();   // expect: second
    cout << "deleted=" << dat << endl; // first
    cout << "Delete last. Expected: ''\n";
    dat = list.deleteLast();
    list.print();   // expect: ''
    cout << "deleted=" << dat << endl; // second
    cout << "Delete last. Expected: '', dat = NULL\n";
    dat = list.deleteLast();
    list.print();   // expect: ''
    if (dat != NULL) {
        cout << "deleted should have been NULL"<< endl; // NULL
    }
    /*const char* data = list.deleteFirst();
    list.print();   // expect: first
    cout << "deleted=" << data << endl; // second
    data = list.deleteFirst();
    list.print();   // expect: ''
    cout << "deleted=" << data << endl; // first
    data = list.deleteFirst();
    list.print();   // expect: ''
    if (data != NULL) {
        cout << "deleted should have been NULL"<< endl; // NULL
    }*/
}
