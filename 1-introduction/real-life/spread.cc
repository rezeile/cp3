#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

void spread(int sum, int diff) {
    if (sum < diff || (sum - diff) % 2 != 0) printf("impossible\n");
    else {
        int delta = (sum-diff) / 2;
        printf("%d %d\n",sum-delta,delta);
    }
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    int N;
    getline(cin,input);
    stringstream ss(input);
    ss >> N;
    for(int i = 0; i < N; i++) {
        getline(cin,input);
        stringstream ss(input);
        int S,D;
        ss >> S >> D;
        spread(S,D);
    }
    return 0;
}
