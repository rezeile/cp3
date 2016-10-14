#include <iostream>
#include <cstdio>
#include <algorithm>
#include <set>
using namespace std;

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    int TC;
    cin >> TC;
    int N, val;
    set<int> s;
    for(int i = 1; i <= TC; i++) {
        cin >> N;
        for(int j = 0; j < N; j++) {
            cin >> val;
            s.insert(val);
        }
        int max = *(max_element(s.begin(),s.end()));
        printf("Case %d: %d\n",i,max);
        s.clear(); 
    }
    return 0;
}
