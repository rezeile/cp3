#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
using namespace std;

int maxSmoked(int C,int K) {
    return 10;
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    
    while(getline(cin,input)) {
        int C,K;
        stringstream ss(input);
        ss >> C >> K;
        cout << maxSmoked(C,K) << endl;
    }
    return 0;
}
