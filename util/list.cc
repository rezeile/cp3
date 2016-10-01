#include <set>
#include <iostream>
#include <sstream>
#include <vector>
#include "list.h"
using namespace std;

void clear_stack(stack<int> &s) {
	stack<int> empty;
	swap(s,empty);
}

void add_to_stack(stack<int> &stack,stringstream &s) {
	int N;
	while(s >> N) {
		stack.push(N);
	}
}

void print_stack(stack<int> &s) {
	stack<int> s_cpy(s);
	while(!s_cpy.empty()) {
		cout << s_cpy.top() << " ";
		s_cpy.pop();
	}
	cout << endl;
}

void print_node(const node *head) {
	const node *cur = head;
	while(cur != nullptr) {
		cout << cur->data << " ";
		cur = cur->next;
	}
	cout << endl;
}

/* 
 * Reads the stringstream which contains a sequence
 * of integers and constructs a forward linked list.
 * The memory is dynamically allocated and should be 
 * freed by the user.
 */
node *construct_list(stringstream &s) {
	vector<int> v;
	int N;
	while(s >> N) {
		v.push_back(N);
	}
	
	node *head = new node;
	head->next = nullptr;
	node *cur = head;
	for(size_t i = 0; i < v.size(); i++) {
		cur->data = v[i];
		if(i == v.size() - 1) {
			cur->next = nullptr;
		} else {
			cur->next = new node;
		}
		cur = cur->next;
	}
	return head;
}

void delete_list(node *head) {
	node *cur = head;
	while(cur != nullptr) {
		node *temp = cur->next;
		delete cur;
		cur = temp;
	}
}
