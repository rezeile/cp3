/* 
 * Longest Increasing Subsequence
 * UVa 481: What Goes Up
 *
 * This solution requires the reconstruction of the longest 
 * increasing subsequence of the array rather than simply
 * the length of the longest increasing subsequence.
 *
 * The following implementation uses bottom-up (i.e. true 
 * Dynamic Programming)
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
    // there is atleast a subsequence of size one for each element 
    vector<int> sl(v.size(),1); // subsequence length
    vector<vector<int>> subseq(v.size());
    for(int i = 0; i < v.size(); i++) {
        subseq[i].push_back(v[i]);
    }
    sl[0] = 1;
    int max_index = 0;
    for(int i = 1; i < v.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(sl[i] <= (sl[j] + 1) && v[j] < v[i]) {
                sl[i] = sl[j] + 1;
                subseq[i] = subseq[j]; subseq[i].push_back(v[i]);
                max_index = sl[i] >= sl[max_index] ? i : max_index;
            }
        }
    }
    vector<int> lis = subseq[max_index];
    cout << lis.size() << endl;
    cout << "-" << endl;
    for(int i = 0; i < lis.size(); i++) {
        cout << lis[i] << endl;
    }
} 

int main(int argc, char *argv[]) {
    /*if(argc < 2) {
        cerr << "enter an input file" << endl; return -1;
    }
    freopen(argv[1],"r",stdin);*/
    vector<int> v;
    int val;
    while(cin >> val) {
        v.push_back(val);
    }
    printLongestIncreasingSubsequence(v);
    return 0;
}
