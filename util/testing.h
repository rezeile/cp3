#ifndef __TESTING_H
#define __TESTING_H
#include <iostream>
#include <vector>
using namespace std;

template<typename T>
void compareOutput(T expected, T received) {
	cout << "Expected: " << expected << endl;
	cout << "Received: " << received << endl;
	cout << "===============================" << endl;
}

template<typename Type>
void printArray(vector<Type> &arr) {
    cout << "[";
    for(int i = 0; i < arr.size(); i++) {
        if(i != arr.size() - 1) cout << arr[i] << ",";
        else cout << arr[i]; 
    }
    cout << "]\n";
}
#endif
