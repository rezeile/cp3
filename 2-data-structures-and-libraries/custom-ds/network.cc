#include <vector>
#include <sstream>
#include <string>
#include <iostream>
#include "union-find.hh"

typedef struct comp_pair {
  char c;
  int i;
  int j;
} comp_pair;

void solve(int C,vector<comp_pair> &v) {
  int correct = 0, incorrect = 0;
  UnionFind UF(C);
  for(comp_pair p: v) {
    int x = p.i-1, y = p.j-1;
    if (p.c == 'c') {
      UF.UnionSet(x,y);
    } else {
      if (UF.isSameSet(x,y)) {
        correct++;
      } else {
        incorrect++;
      }
    }
  }
  printf("%d,%d\n",correct, incorrect);
}

int main(int argc, char *argv[]) {
    if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    freopen(argv[1],"r",stdin);
    int N,C,i,j; 
    char c;
    string input;
    getline(cin,input); stringstream ss(input); ss >> N;
    getline(cin,input); // blank line 
    while(N-- > 0) {
      getline(cin,input); stringstream ss(input); ss >> C;
      vector<comp_pair> v;
      while(getline(cin,input)) {
        if (input == "") break;
        stringstream ss(input);
        ss >> c; ss >> i; ss >> j;
        comp_pair p = comp_pair();
        p.c = c; p.i = i; p.j = j;
        v.push_back(p);
      }
      solve(C,v);if (N != 0) printf("\n");
    }
    return 0;
}
