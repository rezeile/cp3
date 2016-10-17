#include <iostream>
#include <cstdio>
#include <set> // for std::set
#include <string>
using namespace std;

set<string>printAllAnagramsHelper(string s) {
     if(s == "") {
        set<string> s;
        return s;
     }
     char c = s[0];
     set<string> rest = printAllAnagramsHelper(s.substr(1,s.size()));
     auto it = rest.begin();
     set<string> result;
     string s1;
     for(int i = 0; i < rest.size(); i++) {
         s1 = *(it++);
         result.insert(s1.substr(0,i) + to_string(c) + s1.substr(i,s1.size()));
     }
     return result;
}

void printAllAnagrams(string s) {
    set<string> anagrams = printAllAnagramsHelper(s);
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int N;
    cin >> N;
    string s;
    for(int i = 0; i < N; i++) {
       cin >> s;
       printAllAnagrams(s);
    }
    return 0;
}
