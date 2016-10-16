#include <iostream>
#include <cstdio>
#include <sstream> // for std::sstream
#include <string>       // for std::string
#include <vector>
using namespace std;

bool isAnanagram(string s, vector<string> &words) {
    return true;
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string word;
    vector<string> words;
    while(cin >> word) {
        if(word == "#") break;
        words.push_back(word); 
    }
    return 0;
}
