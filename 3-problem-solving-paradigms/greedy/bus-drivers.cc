#include <algorithm>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <vector>
#include <utility>
#include <cmath>
#include <climits>
using namespace std;

void minimizeCost(vector<int> &m, vector<int> &e,int d, int r) {
  sort(m.begin(),m.end(),less<int>());
  sort(e.begin(),e.end(),greater<int>());
  
  int overtime_cost = 0;
  for (int i = 0; i < m.size(); i++) {
    int diff = abs(d-(m[i]+e[i]));
    if ((d - (m[i] + e[i])) < 0) {
      overtime_cost += diff;
    }
  }
  printf("%d\n",overtime_cost * r);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    string input;
    while(getline(cin,input)) {
      if (input[0] == '0') break;
      stringstream ss(input);
      int n, d, r;
      ss >> n >> d >> r;
      getline(cin,input);
      stringstream morning(input);
      getline(cin,input);
      stringstream evening(input);
      
      vector<int> m(n);
      vector<int> e(n);
      for (int i = 0; i < n; i++) {
        morning >> m[i];
        evening >> e[i];
      }

      minimizeCost(m,e,d,r);
    }
    
    return 0;
}
