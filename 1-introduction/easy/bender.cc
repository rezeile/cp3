#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

/* test input */
void printVector(vector<string> &v) {
    cout << "[";
    for(int i = 0; i < v.size(); i++) {
        if(i != v.size() - 1) cout << v[i] << ",";
        else cout << v[i];
    }
    cout << "]\n";
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int L;
    string s;
    vector<string> v;
    while(cin >> L) {
        if(L == 0) break;
        v.clear();
        for(int i = 0; i < L - 1; i++) {
            cin >> s;
            v.push_back(s);
        }
        printVector(v);
    }
    return 0;
}
