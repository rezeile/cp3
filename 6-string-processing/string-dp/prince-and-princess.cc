/*
 * This problem is basically a variant of the Longest Common Subsequence
 * Problem. However the O(mn) solution to the longest common subsequence
 * would take too long in this case.
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
#include <algorithm>
#include <deque>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> mtx;

int longestIncreasingSubsequence(vector<int> &v) {
    //if(v.size() <= 1) return v.size();
    // let L[i] be the smallest value of a length i LIS
    int pos = 0;
    deque<int> L;
    for(int i = 0; i < v.size(); i++) {
        pos = (lower_bound(L.begin(),L.end(),v[i]) - L.begin());
        if(pos <= 0 && L.size() == 0) L.push_front(v[i]);
        else if(pos >= L.size()) L.push_back(v[i]);
        else if(L[pos] > v[i]) L[pos] = v[i];
    }
    return L.size();
}

int longestRoute(vector<int> &prince, vector<int> &princess,int n) {
    int MAX = n * n;
    vector<int> v(MAX + 1,1);
    unordered_set<int> s(princess.begin(),princess.end());
    for(int i = 0; i < prince.size(); i++) {
        int val = prince[i];
        if(s.find(val) != s.end()) {
            printf("val = %d\n",val);
            v[val] = i + 1;
        }
    }
    for(auto i : v) cout << i << " ";
    cout << endl;
    return longestIncreasingSubsequence(v);
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
