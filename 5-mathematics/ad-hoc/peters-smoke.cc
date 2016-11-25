#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int maxSmoked(int C,int K) {
    int smkd = 0;
    int cnt = 0;
    while(--C >= 0) {
        cnt += 1;
        smkd += 1;
        if(cnt == K) {cnt = 0;C++;}
    }
    return smkd;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    
    while(getline(cin,input)) {
        int C,K;
        stringstream ss(input);
        ss >> C >> K;
        cout << maxSmoked(C,K) << endl;
    }
    return 0;
}
