#ifndef __TESTING_H
#define __TESTING_H
#include <iostream>
using namespace std;

template<typename T>
void compareOutput(T expected, T received) {
	cout << "Expected: " << expected << endl;
	cout << "Received: " << received << endl;
	cout << "===============================" << endl;
}

#endif
