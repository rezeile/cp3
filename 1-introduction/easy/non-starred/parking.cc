#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cstdlib>
#include <vector>
#include <set>
using namespace std;

#define INF 1000000000

int minimalDist(set<int> &s) { 
    int min = INF;
    int loc;
    for(int i = 0; i <= 99; i++) {
        int cur_min = 0;
        loc = i;
        for(auto item: s) {
            cur_min += abs(item - loc);
            loc = item;
        }
        cur_min *= 2;
        if(cur_min < min){  min = cur_min; loc = i; }
    }
    return min;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    int TC,N;
    cin >> TC;
    for(int i = 0; i < TC; i++) {
        cin >> N;
        set<int> s;
        for(int i = 0; i < N; i++) { int val; cin >> val; s.insert(val);}
        printf("%d\n",minimalDist(s));
    }
    return 0;
}
