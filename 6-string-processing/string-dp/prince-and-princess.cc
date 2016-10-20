/*
 * This problem is basically a variant of the Longest Common Subsequence
 * Problem.
 */

#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
using namespace std;

typedef vector<int> vi;
typedef vector<vector<int>> mtx;

int longestRouteHelper(vi &prince,vi &princess,int pce,int pcess, mtx &m) {
    if(pce <= 0  || pcess <= 0) return 0;
    // both have atleast a single element
    if(prince[pce] == princess[pcess]) {
        if(m[pce][pcess] == 0) 
            m[pce][pcess] = 1 + longestRouteHelper(prince,princess,pce - 1,pcess-1,m);
        return 1 + m[pce-1][pcess-1];
    } else {
        int max_1,max_2;
        if(m[pce][pcess-1] == 0) 
            max_1 = m[pce][pcess-1] = longestRouteHelper(prince,princess,pce,pcess-1,m);
        if(m[pce-1][pcess] == 0)
            max_2 = m[pce-1][pcess] = longestRouteHelper(prince,princess,pce-1,pcess,m);
        return max(max_1,max_2);
    }
}

int longestRoute(vector<int> &prince, vector<int> &princess) {
    // let r denote row and c column
    int r = prince.size(), c = princess.size();
    mtx m(r,vector<int>(c,0));
    return longestRouteHelper(prince,princess,r-1,c-1,m);
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
        for(int j = 0; j <= p; j++) cin >> prince[j];
        for(int k = 0; k <= q; k++) cin >> princess[k];
        printf("Case %d: %d\n",i,longestRoute(prince,princess));
    }
    return 0;
}
