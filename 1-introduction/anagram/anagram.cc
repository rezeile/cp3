#include <iostream>
#include <cstdio>
#include <set> // for std::set
#include <string>
#include <algorithm> // for lexicographical_compare
#include <cctype>
#include <vector>
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
            int s1_size = s1.size();
            int s2_size = s2.size();
            int size = s1_size > s2_size ? s1_size : s2_size;
            for(int i = 0; i < size; i++) {
                if((tolower(s1[i]) == tolower(s2[i]) && s1[i] == s2[i])) continue;
                else if(tolower(s1[i]) == tolower(s2[i])) return s1[i] < s2[i];
                else return tolower(s1[i]) < tolower(s2[i]);
            }
            return false;
        }
} mycmp;

void printAllAnagramsHelper(string s,set<string,Compare> &result) {
     // base case
     if(!s.empty()) {
         char c = s[0];
         set<string,Compare> rest;
         printAllAnagramsHelper(s.substr(1,s.size()),rest);
         if(rest.size() == 0) { rest.insert(s); result = rest; return;}
         
         // otherwise
         string s1;
         for(auto it = rest.begin(); it != rest.end(); it++) {
             s1 = *it;
             for(int i = 0; i <= s1.size(); i++) {
                string s2 = s1.substr(0,i) + c  + s1.substr(i,s1.size());
                result.insert(s2);
             }
         }
     }
}

void printAllAnagrams(string s) {
    set<string,Compare> anagrams; 
    printAllAnagramsHelper(s,anagrams);
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
