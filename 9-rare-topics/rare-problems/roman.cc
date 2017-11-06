#include <cstdio>
using namespace std;

typedef struct digits {
  int i;
  int v;
  int x;
  int l;
  int c;
} digits;

void computeDigits(int N,digits &d) {
  if (N == 100) {
    d.c += 1;
  } else if (N >= 90) {
    d.x += 1; 
    d.c += 1;
    computeDigits(N-90,d);
  } else if (N >= 50) {
    d.l += 1;
    computeDigits(N-50,d);
  } else if (N >= 40) {
    d.x += 1;
    d.l += 1;
    computeDigits(N-40,d);
  } else if (N >= 10) {
    d.x += 1;
    computeDigits(N-10,d);
  } else if (N == 9) {
    d.x += 1;
    d.i += 1;
  } else if (N >= 5) {
    d.v += 1;
    computeDigits(N-5,d);
  } else if (N == 4) {
    d.v += 1;
    d.i += 1;
  } else {
    d.i += N;
  }
}

void solve(int N) {
  digits d = digits();
  for(int i = 1; i <= N; i++) {
    computeDigits(i,d);
  }
  printf("%d: %d i, %d v, %d x, %d l, %d c\n",N,d.i,d.v,d.x,d.l,d.c);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N;
    while(scanf("%d\n",&N) != EOF) {
      if (N == 0) break;
      solve(N);
    }
    return 0;
}
