#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

int lineCounter = 0;

void solution(string &s1, string &s2) {
  int res = 0;
  if (s1.empty() || s2.empty()) 
    res = 0;
  else {
    int grid[s1.size()][s2.size()];
    grid[0][0] = s1[0] == s2[0];
    for(int i = 0; i < s1.size(); i++) {
      for(int j = 0; j < s2.size(); j++) {
        int val = 0;
        if (s1[i] != s2[j]) {
          if (i > 0) val = grid[i-1][j];
          if (j > 0) val = max(val,grid[i][j-1]);
          grid[i][j] = val;
        } else {
          if (i > 0 && j > 0) val = grid[i-1][j-1];
          grid[i][j] = val + 1;
        }
      }
    }
    res = grid[s1.size()-1][s2.size()-1];
  }
  printf("Case #%d: you can visit at most %d cities.\n",++lineCounter,res);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    string city, sequence;
    while(getline(cin,city)) {
      if (city[0] == '#') break;
      getline(cin,sequence);
      solution(city,sequence);
    }
    return 0;
}
