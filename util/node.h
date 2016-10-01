#ifndef __NODE
#define __NODE
#include <iostream>
using namespace std;

template<typename T>
struct Node {
	T data;
	Node<T> *next;
};

struct node {
	int data;
	node *next;
};

template<typename T>
void print_list(Node<T> *head) {
	Node<T> *cur = head;
	while(cur != nullptr) {
		cout << "(" <<  cur->data << ")" << " ";
		cur = cur->next;
	}
	cout << endl;
}
#endif 
