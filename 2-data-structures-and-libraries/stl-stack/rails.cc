#include <cstdio>
#include <iostream>
#include <vector>
#include <string>
#include <sstream>
#include <numeric>
#include <stack>
using namespace std;

void rails(vector<int> &v) {
    stack<int> s;
    int N = 1;
    while(N++ <= v.size()) {
        s.push(N);
    }
    int start = s.top();
}

int main(int argc, char *argv[]) {
    if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    freopen(argv[1],"r",stdin);
    int N;
    while(scanf("%d\n",&N) != EOF) {
        if(N == 0) break;
        string input;
        while(getline(cin,input)) {
            if(input == "0") break;
            stringstream (ss);
            vector<int> v(N);
            for(int i = 0; i < v.size(); i++)
                ss >> v[i];
            rails(v);
        }
        printf("\n");
    }
    return 0;
}
