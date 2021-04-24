#include <iostream>
#include <cstring>

using namespace std;

struct Node {
   const char* element;
   Node* next;

   Node(const char* e = NULL, Node* n = NULL)
   :element(e), next(n)   { }
};

struct SList {
	Node* head = NULL;

	void print() {
		cout << "(";
		for (Node *p = head; p != NULL; p = p->next) {
			cout << p->element << ".";
		}
		cout << ")" << endl;
	}

	Node* addFirst(const char* data)	{
		head = new Node(data, head);
		return head;
	}

	int count() {
		int c = 0;
		for (Node *p = head; p != NULL; p = p->next) {
			c++;
		}
		return c;
	}

	Node* findMax() {
		Node* _maxPtr = head;
		for (Node *p = head; p != NULL; p = p->next) {
			if (strcmp(_maxPtr->element, p->element) < 0) {
				_maxPtr = p;
			}
		}
		return _maxPtr;
	}

	Node* find(string data) {
		for(Node* p = head; p != NULL; p=p->next) {
            if (strcmp(p->element, data)==0) return p;
		}
		return NULL;
	}

	const char* max() {
		if (head == NULL) return "";

		const char* _max = head->element;
		for (Node *p = head; p != NULL; p = p->next) {
			if (strcmp(p->element, _max) > 0)
				_max = p->element;
		}
		return _max;
	}

	const char* removeFirst() {
		if (head == NULL) return NULL;

		Node* second = head->next;
		const char* data = head->element;
		delete head;
		head = second;
		return data;
	}

	void removeLast() {
		if (head == NULL) return;

		if (head->next == NULL) {
			delete head;
			head = NULL;
		}
		else {
			Node* secondLast = head;
			for (; secondLast->next->next != NULL;
					secondLast = secondLast->next) {}
			delete secondLast->next;
			secondLast->next = NULL;
		}
	}
	Node* append(const char* data) {
		if (head == NULL) {
			return addFirst(data);
		}
		else {
			Node* last = head;
			for (; last->next != NULL; last = last->next) {}
			last->next = new Node(data, NULL);
			return last->next;
		}
	}

	Node* insertAfter(Node* n, const char* data) {
	    if (n==NULL) return NULL;
	    n->next = new Node(data, n->next);
	    return n->next;
	}

	const char* deleteNode(Node* n) {
	    if (head == n) return removeFirst();
	    if (n==NULL) return NULL;

	    //find node before n
	    Node* p = head;
	    for (; p!=NULL && p->next != n; p=p->next) {}

	    if (p==NULL) return NULL;

	    p->next = n->next;
	    const char* data = n->element;
        delete n;
        return data;
	}

	void removeFirst(const char* data) {
        Node * p = find(data);
        deleteNode(p);
	}
};

char two[4] = "Two";

int main(int argc, char** argv)
{
	SList list;
	Node * n1 = list.append("One");
	cout << n1->element << endl;
	Node * n2 = list.append("Two");
	Node * n3 = list.append("Three");

	//list.removeFirst("Two");
	list.removeFirst(two);
	list.print(); //One Three

/*	cout << "deleting null "<< endl;
	list.deleteNode(NULL) ;
	list.print();

    cout << "deleting " << list.deleteNode(n1) << endl;
	list.print(); //

	cout << "deleting " << list.deleteNode(n2) << endl;
	list.print(); // One Three

    cout << "deleting ONE " <<  endl;
    list.deleteNode(n1);
	list.print(); // Three

	cout << "deleting " << list.deleteNode(n3) << endl;
	list.print(); // One

	cout << "deleting "  << endl;
	list.deleteNode(NULL);
	list.print(); // One
*/
	/*
    list.insertAfter(n3, "Four");
    list.print(); // One Two Three Four

    list.insertAfter(n1, "Five");
    list.print(); // One Five Two Three Four

    Node* n = NULL;

    list.insertAfter(n, "Six");
    list.print(); // One Five Two Three Four
*/
	cout << "END";
}
