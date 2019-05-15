//#define DEBUG
#include <iostream>

using namespace std;

template <class T>
struct Node{
    const T* data;
    Node* next;
    Node(const T* data = NULL, Node* next = NULL)
    {
        this->data = data;
        this->next = next;
    }
    ~Node()
    {
#ifdef DEBUG
    	cerr << "Deleting Node " << data << endl;
#endif    	
	}
};

template <class T>
struct SLinkedList {
	
	~SLinkedList() {
		#ifdef DEBUG
		cerr << "Deleting the list..." << endl;
		#endif
		// delete all the nodes
		while ( head != NULL) {
			Node<T> * next = head->next;
			delete head;
			head = next;
		}
		#ifdef DEBUG
		cerr << "Done Deleting the list." << endl;
		#endif
	}
	
    Node<T>* head = NULL;

    Node<T>* addFirst(const T* data)
    {
        Node<T>* newNode = new Node<T>(data, head);
        head = newNode;
        return head;
    }
    
    void removeFirst()
    {
    	if (head!=NULL) {
        	Node<T>* oldHead = head;
        	head = head->next;
        	delete oldHead;
    	}
    }

	Node<T>* insertAfter(Node<T>* p, const T* data)
    {
        Node<T>* newNode = new Node<T>(data, p->next);
        p->next = newNode;
        return newNode;
    }
    
    void print() const
    {
        cerr << "list: [";
        for (Node<T> *p = head; p!=NULL; p=p->next) {
            cerr << p->data << " ";
        }
        cerr << "]" << endl;
    }
    SLinkedList* reverse() const
    {
    	SLinkedList* reversed = new SLinkedList();
    	
		for (Node<T> *p = head; p!=NULL; p=p->next) {
            reversed->addFirst(p->data);
        }	
    	// reverse
    	return reversed;
	}
};

template <class T>
Node<T>* reverse(Node<T>* head)
{
	Node<T>* reversedListHead = NULL;
	for (Node<T> *p = head; p!=NULL; p=p->next) {
    	Node<T>* newNode = new Node<T>(p->data, NULL);
    	newNode->next = reversedListHead;
    	reversedListHead = newNode;
    }	
    return reversedListHead;
}


int main() {
    SLinkedList<char>* list = new SLinkedList<char>();
    char * s = new char[10];
    s[0] = 'T'; s[1] = 'w'; s[2] = '\0';
    Node<char>* one = list->addFirst("One");
    Node<char>* two = list->addFirst(s);
    list->print();	//"Two", "One"
    Node<char>* three = list->insertAfter(one, "Three");
    list->print(); //"Two", "One", "Three"
    Node<char>* four = list->insertAfter(two, "Four");
    list->print(); // "Two", "four", "One", "Three"
    list->removeFirst();
    cout << s;
    list->print(); // "four", "One", "Three"
    
    delete list;
    //SLinkedList* reversed = list.reverse();
//    SLinkedList reversed;
//    reversed.head = reverse(list.head);
//    reversed.print();
}

