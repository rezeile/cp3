#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    int N;
    while(cin >> N) {
        vector<int> v(N);
        for(int i = 0; i < N; i++) {
            cin >> v[i];
        }
    }
    return 0;
}
