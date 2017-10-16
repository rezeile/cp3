#include <cstdio>
#include <climits>
#include <algorithm>
#include <string>
using namespace std;

int bottleIndex(char c) {
  switch(c) {
    case 'B':
      return 0;
    case 'G':
      return 1;
    case 'C':
      return 2;
    default:
      return -1;
  }
}

int costToMove(char c, int bin, int *arr) {
  int cost = 0;
  for(int i = 0; i < 3; i++) {
      if (i != bin) cost += arr[i*3 + bottleIndex(c)];
  }
  return cost;
}

void solve(int *arr) {
  string s = "BCG";
  string ans;
  int min = INT_MAX;
  do {
    int cost = costToMove(s[0],0,arr) + costToMove(s[1],1,arr) + costToMove(s[2],2,arr);
    if (cost < min) {
      min = cost;
      ans = s;
    }
  } while(next_permutation(s.begin(),s.end())); 
  printf("%s %d\n",ans.c_str(),min);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int arr[9];
    while (scanf("%d",&arr[0]) != EOF) {
      for(int i = 1; i < 9; i++) {
        if (i == 8) scanf("%d\n",&arr[i]);
        else scanf("%d",&arr[i]);
      }
      solve(arr);
    }
    return 0;
}
