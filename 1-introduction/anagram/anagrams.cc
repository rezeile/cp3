#include <iostream>
#include <cstdio>
#include <vector>
#include <string>
#include <set>
#include <sstream>
#include <utility>
#include <algorithm>
#include <cctype>
using namespace std;

typedef pair<string,string> pss;
class Compare {
    public:
    bool operator() (pss p1,pss p2) {
        if(p1.first < p2.first) return true;
        if(p1.first == p2.first && p1.second < p2.second) return true;
        return false;
    }
};

void printAnagrams(vector<string> &v) {
    multiset<pss,Compare> s;
    string s1,s2;
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            pair<string,string> p;
            s1 = v[i];
            s1.erase(remove_if(s1.begin(),s1.end(),::isspace),s1.end());
            sort(s1.begin(),s1.end());
            s2 = v[j]; 
            s2.erase(remove_if(s2.begin(),s2.end(),::isspace),s2.end());
            sort(s2.begin(),s2.end());
            if(s1 == s2) {
                if(v[i] < v[j]) {p.first = v[i]; p.second = v[j]; s.insert(p); }
                else { p.first = v[j]; p.second = v[i]; s.insert(p); }
            }
        }
    }
    // print results
    for(auto i : s) cout << i.first << " = " << i.second << endl;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    int TC;
    string T;
    getline(cin,T);
    stringstream ss(T);
    ss >> TC;
    string s;
    getline(cin,s);
    for(int i = 0; i < TC; i++) {
        vector<string> v;
        while(getline(cin,s)) {
            if(s == "") break;
            v.push_back(s);
        }
        printAnagrams(v);
        if(i != (TC-1)) cout << endl;
    }
    return 0;
}
