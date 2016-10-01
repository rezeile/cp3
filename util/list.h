#ifndef __LIST
#define __LIST

#include "node.h"
#include <stack>
#include <sstream>
#include <iostream>
using namespace std;

void clear_stack(stack<int> &s);
void print_stack(stack<int> &s);
void add_to_stack(stack<int> &stack,stringstream &s);
void print_node(const node *head);
node *construct_list(stringstream &s);
void delete_list(node *head);

#endif
