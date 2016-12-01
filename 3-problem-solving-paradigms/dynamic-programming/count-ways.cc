#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

void printResult(int N,int w) {
    if(w == 1) {
        printf("There is only %d way to produce %d cents change.\n",w,N);
    } else {
        printf("There are %d ways to produce %d cents change.\n",w,N);
    }
}

void countWays(int N,vector<int> &D,int &ways) {
    if(N == 0) { ways += 1; return; }
    if(N < 0) return;
    for(auto i : D) {
        if(i <= N) {
            countWays(N-i,D,ways);
        }
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    int N;
    vector<int> D = {1,5,10,25,50};
    while(cin >> N) {
        int w = 0;
        countWays(N,D,w);
        printResult(N,w);
    }
    return 0;
}
