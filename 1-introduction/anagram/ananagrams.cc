#include <iostream>
#include <cstdio>
#include <sstream> // for std::sstream
#include <string>       // for std::string
#include <vector>
#include <set>
#include <cctype>
using namespace std;

bool isAnagram(string a, string b) {
    if(a.size() == b.size()) {
        for(int i = 0; i < a.size(); i++) {
            if(tolower(a[i]) != tolower(b[i])) return false;
        }
        return true;
    }
    return false;
}
bool isAnanagram(string s, multiset<string> &words,multiset<string>::iterator it) {
    string s1 = s,s2;
    sort(s1.begin(),s1.end());
    for(auto i = words.begin(); i != words.end(); i++) {
        if(i == it) continue;
        s2 = *i;
        sort(s2.begin(),s2.end());
        if(isAnagram(s1,s2)) return false;
    }
    return true;
}

void printAnanagrams(multiset<string> words) {
    for(auto i = words.begin(); i != words.end(); i++) {
        string word = *i;
        words.erase(i);
        if(isAnanagram(word,words,i))
            cout << word << endl;
        words.insert(word);
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string word;
    multiset<string> words;
    while(cin >> word) {
        if(word == "#") break;
        words.insert(word); 
    }
    printAnanagrams(words);
    return 0;
}
