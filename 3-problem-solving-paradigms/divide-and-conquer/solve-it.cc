#include <cstdio>
#include <cmath>
#include <string>
using namespace std;
using i = int;
#define EPS 1e-5


double getSum(i p,i q,i r,i s,i t,i u,double x) {
    return p*exp(-x) + q*sin(x) + r*cos(x) + s*tan(x) + t*x*x + u;
}

bool can(i p,i q,i r,i s,i t,i u,double x) {
    double ans = getSum(p,q,r,s,t,u,x);
    return abs(ans-0.0) < EPS;
}

void solveIt(i p,i q,i r,i s,i t,i u) {
    double lo = 0.0, hi = 1.0, mid = 0.0, ans = 0.0;
    while(abs(hi-lo) > EPS) {
        double l = getSum(p,q,r,s,t,u,lo);
        double h = getSum(p,q,r,s,t,u,hi);
        printf("lo = %f, hi = %f\n",lo,hi);
        mid = (lo+hi)/2.0; 
        double m = getSum(p,q,r,s,t,u,mid);
        if (l == h) { lo += 0.0001; hi -= 0.0001; }
        else if (can(p,q,r,s,t,u,mid)) { ans = mid;}
        else if (abs(l-m) < abs(h-m)) { hi = mid; }
        else lo = mid;
    }
    printf("%.4f\n",ans);
}

int main(int argc, char *argv[]) {
    if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    freopen(argv[1],"r",stdin);
    int p,q,r,s,t,u;
    while(scanf("%d %d %d %d %d %d\n",&p,&q,&r,&s,&t,&u) != EOF)  {
        solveIt(p,q,r,s,t,u);
    }
    return 0;
}
