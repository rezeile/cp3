#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

#define YES "is immediately decodable"
#define NO "is not immediately decodable"

int lineCounter = 0;

void decode(vector<string> &v) {
  int N = v.size();
  for(int mask = 0; mask < 1 << N; mask++) {
    if(__builtin_popcount(mask) == 2) {
      int count = 0, p, q;
      for(int i = 0; i < N; i++) {
        if (1 << i & mask) {
          if (!count++) {
            p = i;
          } else {
            q = i;
          }
        }
      }
      int r = (int) v[p].size(), s = (int) v[q].size();
      int min = r < s ? r : s;
      string s1 = v[p].substr(0,min);
      string s2 = v[q].substr(0,min);
      if (s1.find(s2) != string::npos) {
        printf("Set %d %s\n",++lineCounter,NO);
        return;
      }
    }
  }
  printf("Set %d %s\n",++lineCounter,YES);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    string input;
    while(getline(cin,input)) {
      vector<string> v;
      while(input != "9") {
        v.push_back(input);
        getline(cin,input);
      }
      decode(v);
    }
    return 0;
}
