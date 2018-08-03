#include <cstdio>
#include <iostream>
using namespace std;

/* 
 * Problem Statement 
 * -----------------------------
 *
 * starting at corner (1,1) on a chess board, an ant travels in a snake like path. 
 * first it travels:
 *   north to (1,2) 
 *   east to (2,2)
 *   south to (2,1) 
 *   east (3,1)
 *   north to (3,2), 
 *   ...
 *
 */

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
