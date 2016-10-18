#include <iostream>
#include <cstdio>
#include <set> // for std::set
#include <string>
#include <algorithm> // for lexicographical_compare
#include <cctype>
#include <map>
#include <utility>
using namespace std;

void toLower(string &s) {
    for(int i = 0; i < s.size(); i++) {
        s[i] = tolower(s[i]);
    }
}

class Compare {
    public: 
        bool operator() (string s1,string s2) {
           if(s1.size() <= s2.size()) {
               for(int i = 0; i < s1.size(); i++) {
                    if(s1[i] < s2[i]) return true;
               }
           }
           return false;
        }
};

set<string,Compare> printAllAnagramsHelper(string s) {
     // base case
     if(s.empty()) { set<string,Compare> sset; return sset;}
     char c = s[0];
     set<string,Compare> rest = printAllAnagramsHelper(s.substr(1,s.size()));
     if(rest.size() == 0) { rest.insert(s); return rest;}
     
     // otherwise
     set<string,Compare> result;
     string s1;
     for(auto it = rest.begin(); it != rest.end(); it++) {
         s1 = *it;
         for(int i = 0; i <= s1.size(); i++) {
            string s2 = s1.substr(0,i) + c  + s1.substr(i,s1.size());
            result.insert(s2);
         }
     }
     return result;
}


void printAllAnagrams(string s) {
    set<string,Compare> anagrams = printAllAnagramsHelper(s);
    for(auto i = anagrams.begin(); i != anagrams.end(); i++) 
        cout << *i << endl;
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
