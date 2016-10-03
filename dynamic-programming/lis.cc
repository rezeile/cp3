/* 
 * Longest Increasing Subsequence
 * UVa 481: What Goes Up
 *
 * Author: Eliezer Abate
 * Last Updated October 3 2016
 *
 */
 
#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

void printLongestIncreasingSubsequence(vector<int> &v) {
    if(v.size() == 0) return;
    vector<int> sl(v.size()); // subsequence length
    sl[0] = 1;
    int max_index = 0;
    for(int i = 1; i < v.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(sl[i] < (sl[j] + 1) && v[j] < v[i]) {
                sl[i] = sl[j] + 1;
                max_index = sl[i] >= sl[max_index] ? i : max_index;
            }
        }
    }
} 

int main() {
    vector<int> v;
    int val;
    while(cin >> val) {
        v.push_back(val);
    }
    cout << v.size() << endl;
    cout << "-" << endl;
    printLongestIncreasingSubsequence(v);
    return 0;
}
