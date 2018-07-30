#include <cstdio>
#include <iostream>
using namespace std;

void solve(int N) {
  int c = 2, r = 3;;
   
  printf("%d %d\n", c, r);
}

int main(int argc, char *argv[]) {
  if(argc < 2) { fprintf(stderr,"enter an input file\n"); return -1; }
  freopen(argv[1],"r",stdin);
  int N;
  while (cin >> N) {
    if (N == 0) break;
    solve(N);
  }
  return 0;
}
