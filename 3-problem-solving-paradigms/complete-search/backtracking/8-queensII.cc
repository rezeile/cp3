#include <cstdio>
#include <cstring>
#include <cstdlib>
#include <string>
#include <iostream>
#include <climits>
#include <sstream>
#include <vector>
using namespace std;

vector<int> row(8);
vector<vector<int>> storage;
int caseCounter = 0;

bool place(int r, int c) {
  for(int prev = 0; prev < c; prev++) {
    if (row[prev] == r) return false;
    if (abs(row[prev] - r) == abs(prev - c)) return false;
  }
  return true;
}

void backtrack(int c) {
  if (c == 8) {
    storage.push_back(row);
    return;
  }

  for (int r = 0; r < 8; r++) {
    if (place(r,c)) {
      row[c] = r;
      backtrack(c+1);
    }
  }
}

void findClosestPermutation() {
  int min = INT_MAX;
  for(int i = 0; i < storage.size(); i++) {
    int count = 0; 
    vector<int> v = storage[i];
    for (int j = 0; j < 8; j++) {
      if ((v[j] + 1) != row[j]) count++;
      if (count > min) break;
    }
    if (count < min)  min = count;
  }
  printf("Case %d: %d\n",++caseCounter, min);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    // generate all permutations 
    backtrack(0);
    
    string input;
    while(getline(cin,input)) {
      stringstream ss(input);
      for(int i = 0; i < 8; i++) ss >> row[i];
      findClosestPermutation();
    }
    return 0;
}
