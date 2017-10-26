#include <cstdio>
#include <cmath>
using namespace std;

#define DELTA 1e-9

using I = int;
using D = double;

D compute(I p,I q,I r,I s,I t,I u,D x) {
  D left = p*exp(-x) + q*sin(x) + r*cos(x);
  D right = s*tan(x) + t*x*x + u;
  return left + right;
}

bool leftCloserToZero(D l,D r,D m) {
  if (m > 0.0) {
    if (l < 0.0 && r < 0.0) {
      return abs(l) < abs(r);
    } else {
      return l < 0.0;
    }
  } else {
    if (l > 0.0 && r > 0.0) {
      return l < r;
    } else {
      return l > 0.0;
    }
  }
}

bool isZero(D x) {
  return abs(x) - 0.0 <= 0.000001;
}

bool areEqual(D x,D y) {
  return abs(x-y) <= 0.000000001;; 
}

void printOutput(D x) {
  printf("%.4lf\n",x); 
  //printf("%.4lf\n",trunc(x*10000)/10000); 
}

bool noSolution(D x, D y) {
  return (x > 0.0 && y > 0.0) || (x < 0.0 && y < 0.0);
}

void debugPrint(D x,D m,D y,D left,D mid, D right) {
  printf("x = "); printOutput(x);
  printf("m = "); printOutput(m);
  printf("y = "); printOutput(y);
  
  printf("left = "); printOutput(left);
  printf("mid = "); printOutput(mid);
  printf("right = "); printOutput(right);
  printf("\n");
}

void solve(I p,I q,I r,I s,I t,I u,D x,D y) {
  D left = compute(p,q,r,s,t,u,x);
  D m = (x+y)/2.0;
  D mid = (compute(p,q,r,s,t,u,m));;
  D right = compute(p,q,r,s,t,u,y);

  //debugPrint(x,m,y,left,mid,right);
    
  if (isZero(left)) { printOutput(x); return; }
  if (isZero(mid)) { printOutput(m); return; }
    
  //printf("No solution: (left,mid): %s\n",(noSolution(left,mid) ?  "true": "false"));
  if (isZero(right)) { printOutput(y); return; }
  if (areEqual(x,y)) { printf("No solution\n"); return; }

  if (leftCloserToZero(left,right,mid)) {
    solve(p,q,r,s,t,u,x,m);
  } else {
    solve(p,q,r,s,t,u,m+DELTA,y);
  }
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int p,q,r,s,t,u;
    while(scanf("%d %d %d %d %d %d\n",&p,&q,&r,&s,&t,&u) != EOF) {
      solve(p,q,r,s,t,u,0.0,1.0);
    }
    return 0;
}
