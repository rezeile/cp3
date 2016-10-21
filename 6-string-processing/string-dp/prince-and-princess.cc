/*
 * This problem is basically a variant of the Longest Common Subsequence
 * Problem.
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> mtx;

void lisHelper(vi &v,vi &L,int j) {
    // know that v and L > 1 
    if(v[j] > v[j-1]) {
        L[j] = L[j-1] + 1;
    } else {
        int max = 1;
        for(int i = j-1; i >= 0; i--) {
            if(v[j] > v[i] && (L[i] + 1 > max)) max = L[i] + 1;    
        }
        L[j] = max;
    }
}

int longestIncreasingSubsequence(vector<int> &v) {
    if(v.size() <= 1) return v.size();
    // let V[i] be the longest increasing subsequence (LIS) ending at index i
    vector<int> L(v.size(),1);
    lisHelper(v,L,v.size() - 1);
}

int longestRoute(vector<int> &prince, vector<int> &princess,int n) {
    int MAX = n * n;
    vector<int> v(MAX + 1,-1);
    unordered_set<int> s(princess.begin(),princess.end());
    for(int i = 1; i <= prince.size(); i++) {
        int val = prince[i];
        if(s.find(val) != s.end()) v[val] = i;
    }
    for(int i = 0; i < v.size(); i++) 
        if(v[i] != -1) cout << i << " ";
    return longestIncreasingSubsequence(v);
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int TC,n,p,q;
    cin >> TC;
    vector<int> prince,princess;
    for(int i = 1; i <= TC; i++) {
        cin >> n >> p >> q;
        prince.resize(p + 1); princess.resize(q + 1);
        for(int j = 0; j < p + 1; j++) cin >> prince[j];
        for(int k = 0; k < q + 1; k++) cin >> princess[k];
        printf("Case %d: %d\n",i,longestRoute(prince,princess,n));
    }
    return 0;
}
