/* 
 * Longest Increasing Subsequence
 * UVa 481: What Goes Up
 *
 * This solution requires the reconstruction of the longest 
 * increasing subsequence of the array rather than simply
 * the length of the longest increasing subsequence.
 *
 * The following file includes both the O(n^2) implementation
 * and the much faster O(nlog(n)) implementation of the 
 * longest increasing subsequence problem.
 *
 * Author: Eliezer Abate
 * Last Updated October 3 2016
 *
 */
 
#include <iostream>
#include <cstdio>
#include <vector>
#include <iterator>
#include <set>
#include <deque>
#include <algorithm>
using namespace std;
typedef vector<int> si;

template<typename Container>
void printResult(int size, Container begin,Container end) {
    cout << size << endl;
    cout << "-" << endl;
    Container i;
    for(i = begin; i != end; i++) {
        cout << *i << endl;
    }
}

void greedyLIS(vector<int> &V) {
    if(V.size() == 0) return;
    deque<int> L;
    for(int i = 0; i < V.size(); i++) {
       int pos = lower_bound(L.begin(),L.end(),V[i]) - L.begin(); 
       if(pos <= 0 && L.size() == 0) L.push_front(V[i]);
       else if(pos >= L.size()) L.push_back(V[i]);
       else if(L[pos] > V[i]) L[pos] = V[i];
    }
    printf("%lu\n-\n",L.size());
}

void printLongestIncreasingSubsequence(vector<int> &v) {
    if(v.size() == 0) return;
    // there is atleast a subsequence of size one for each element 
    vector<int> sl(v.size(),1); // subsequence length
    vector<vector<int>> subseq(v.size());
    int max_index = 0;
    for(int i = 1; i < v.size(); i++) {
        subseq[i].push_back(v[i]);
        for(int j = 0; j < i; j++) {
            if(sl[i] <= (sl[j] + 1) && v[j] < v[i]) {
                sl[i] = sl[j] + 1;
                subseq[i] = subseq[j]; subseq[i].push_back(v[i]);
                max_index = sl[i] >= sl[max_index] ? i : max_index;
            }
        }
    }
    vector<int> lis = subseq[max_index];
    printResult(lis.size(),lis.begin(),lis.end());
} 


int main(int argc, char *argv[]) {
    if(argc < 2) {
        cerr << "enter an input file" << endl; return -1;
    }
    freopen(argv[1],"r",stdin);
    vector<int> v;
    int val;
    while(cin >> val) {
        v.push_back(val);
    }
    //printLongestIncreasingSubsequence(v);
    greedyLIS(v);
    return 0;
}
