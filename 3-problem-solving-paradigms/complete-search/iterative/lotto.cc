#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string s;
    while(getline(cin,s)) {
        if(s.size() == 1 && stoi(s) == 0) break;
        stringstream ss(s);
        vector<int> v;
        int val;
        while(ss >> val) {
            v.push_back(val);
        }
        for(auto i : v) cout << i << " ";
        cout << endl;
    }
    return 0;
}
