#include <iostream>
#include <cstdio>
#include <algorithm>
#include <sstream> // for stringstream
#include <string>
#include <vector>
#include <numeric>
using namespace std;

typedef vector<vector<int>> table;

table t;// global

bool luggageFitsHelper(int i,vector<int> &v,int remW) {
   if(remW == 0) return true;
   if(i < v.size()) {
        bool take_it = luggageFitsHelper(i+1,v,remW-v[i]);
        bool leave_it = luggageFitsHelper(i+1,v,remW);
        return take_it || leave_it;
   }
   return false; 
}

void luggageFits(vector<int> &v) {
    int sum = accumulate(v.begin(),v.end(),0);
    if(sum % 2) cout << "NO\n";
    else {
        t.assign(v.size(),vector<int>(sum/2));
        if(luggageFitsHelper(0,v,sum/2)) cout << "YES\n";
        else cout << "NO\n";
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int TC;
    string s;
    getline(cin,s);
    TC = stoi(s);
    vector<int> v;
    int val;
    for(int i = 0; i < TC; i++) {
        v.resize(0);
        getline(cin,s);
        stringstream ss(s);
        while(ss >> val) {
            v.push_back(val);
        }
        luggageFits(v);
    }
    return 0;
}
