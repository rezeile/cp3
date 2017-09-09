#include <cstdio>
#include <string>
#include <iostream>
#include <set>
using namespace std;

typedef struct {
  string Palindrome = "You won't be eaten!";
  string NotPalindrome = "Uh oh..";
} StringType;

set<char> punc = {' ','.',',','!','?'};

string removePunc(string s) {
  // adjust left edge of string 
  string ls = s;
  for (int i = 0; i < s.size(); i++) {
    if (punc.find(s[i]) == punc.end()) {
      break;
    }
    ls = s.substr(i+1);
  }
  // adjust right edge of string
  string rs = ls;
  for (int i = ls.size() - 1; i >= 0; i--) {
    if (punc.find(ls[i]) == punc.end()) {
      break;
    }
    rs = ls.substr(0,i);
  }
  return rs;
}

bool isPalindrome(string s) {
  if (s.size() <= 1) return true;
  s = removePunc(s);
  if (s.size() <= 1) return true;
  if (tolower(s[0]) == tolower(s[s.size()-1])) {
    return isPalindrome(s.substr(1,s.size()-2));
  }
  return false;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    string input; 
    StringType ST; 
    while(getline(cin,input)) {
      if (input == "DONE") break;
      if (isPalindrome(input)) 
        cout << ST.Palindrome << endl;
      else 
        cout << ST.NotPalindrome << endl;
    }
    
    return 0;
}
