#include <iostream> // for cout, cin, cerr
#include <cstdio>   // for freopen
#include <string>   // for std::string
#include <vector>   // for vector
#include <set>      // for multiset
#include <cctype>   // for tolower
#include <algorithm> // for sort
using namespace std;

bool isAnagram(string a, string b) {
    if(a.size() == b.size()) {
        string s1 = "",s2 = "";
        for(int i = 0; i < a.size(); i++) {
            s1 += tolower(a[i]);
            s2 += tolower(b[i]);
        }
        sort(s1.begin(),s1.end()); sort(s2.begin(),s2.end());
        return s1 == s2;
    }
    return false;
}
bool isAnanagram(string s,multiset<string> &words,multiset<string>::iterator it) {
    for(auto i = words.begin(); i != words.end(); i++) {
        if(i == it) continue;
        string s2 = *i;
        if(isAnagram(s,s2)) {
            return false;
        }
    }
    return true;
}

void printAnanagrams(multiset<string> words) {
    for(auto i = words.begin(); i != words.end(); i++) {
        string word = *i;
        if(isAnanagram(word,words,i))
            cout << word << endl;
    }
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string word;
    multiset<string> words;
    while(cin >> word) {
        if(word == "#") break;
        words.insert(word); 
    }
    printAnanagrams(words);
    return 0;
}
