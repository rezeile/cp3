#include <vector>
#include <set>
#include <iostream>            // for cout,cin
#include <cstdio>              // for freopen
using namespace std;
typedef vector<vector<int>> vii;

void printResult(vii &result) {
    if(result.size() == 0) {
        cout << "NONE\n"; return;
    }
    for(int i = 0; i < result.size(); i++) {
        vector<int> v = result[i];
        for(int j = 0; j < v.size(); j++) {
            if(j != v.size() - 1) cout << v[j] << "+";
            else cout << v[j] << "\n";
        }
    }
}

vii sumItUp(int total,multiset<int> s) {
    vii v;
    return v;
}

int main(int argc, char *argv[]) {
    int total,N;
    if(argc < 2) {
        cerr << "enter an input file" << endl; return -1;
    }
    freopen(argv[1],"r",stdin);
    while(cin >> total) {
        if(!total) break; // done 
        cin >> N;
        multiset<int> s;
        int val;
        printf("Sums of %d:\n",total);
        for(int i = 0; i < N; i++) {
            cin >> val;
            s.insert(val);
        }
        vii result = sumItUp(total,s);
        printResult(result);
    }
    return 0;
}
