#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <unordered_map>
#include <unordered_set>
using namespace std;

using um = unordered_map<char,char>;
using us = unordered_set<char>;

us own_reverse = {'A','H','I','M','O','T','U','V','W','X',
                  'Y','1','8'};
um reverse_map = {{'E','3'},{'J','L'},{'L','J'},{'S','2'},
                  {'Z','5'},{'2','S'},{'3','E'},{'5','Z'}};

bool is_palindrome (string input) {
    if (input.size() <= 1) return true;
    char beg = input[0];
    char end = input[input.size() - 1];
    if (beg != end) return false;
    return is_palindrome(string(input.begin() + 1,input.end() - 1));
}

bool is_mirrored_string (string input) {
    if(input.empty()) return true;
    if(input.size() == 1) return own_reverse.find(input[0]) != own_reverse.end();
    char beg = input[0];
    char end = input[input.size() - 1];
    if (beg == end) {
        if (own_reverse.find(beg) == own_reverse.end()) return false;
        else return is_mirrored_string(string(input.begin() + 1,input.end() - 1));
    }
    auto search = reverse_map.find(beg);
    bool unmapped = search == reverse_map.end() || search->second != end;
    if (unmapped) return false;
    return is_mirrored_string(string(input.begin() + 1,input.end() - 1));
}

void palindromes(string input) {
    bool palindrome = is_palindrome (input);
    bool mirrored = is_mirrored_string (input);

    if (palindrome && mirrored) printf("%s -- is a mirrored palindrome.\n",input.c_str());
    else if (palindrome) printf("%s -- is a regular palindrome.\n",input.c_str());
    else if (mirrored) printf("%s -- is a mirrored string.\n",input.c_str());
    else printf("%s -- is not a palindrome.\n",input.c_str());
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    while(getline(cin,input)) {
        palindromes(input);
        printf("\n"); 
    }
    return 0;
}
