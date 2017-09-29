#include <cstdio>
#include <string>
#include <iostream>
#include <utility>
#include <set>
using namespace std;

void solve(pair<string,string> &pair) {
  multiset<char> s(pair.first.begin(), pair.first.end());
  multiset<char> common;
  for(auto &c: pair.second) {
    if (s.find(c) != s.end() && common.count(c) < s.count(c)) common.insert(c);
  }

  for(auto &c: common)
    printf("%c",c);
  printf("\n");
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    while(getline(cin,input)) {
      pair<string,string> pair;
      pair.first = input;
      getline(cin,input);
      pair.second = input;
      solve(pair);
    }
    
    freopen(argv[1],"r",stdin);
    return 0;
}
