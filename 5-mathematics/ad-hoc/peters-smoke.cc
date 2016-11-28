#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <deque>
using namespace std;

int maxSmoked(int C,int K) {
    if(K == 1) return C;
    int smkd = 0;
    deque<int> q(C,1);
    int cnt = 0;
    while(!q.empty()) {
       q.pop_front();
       smkd++;
       cnt++;
       if(cnt == K) { cnt = 0;q.push_back(1);}
    }
    return smkd;
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    
    while(getline(cin,input)) {
        if(input == "") break;
        int C,K;
        stringstream ss(input);
        ss >> C >> K;
        cout << maxSmoked(C,K) << endl;
    }
    return 0;
}
