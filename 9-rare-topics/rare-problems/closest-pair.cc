#include <cstdio>
#include <utility>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

#define INF "INFINITY"

using pii = pair<int,int>;


double dist(double a1,double b1,double a2,double b2) {
  double a = abs(a1-a2);
  double b = abs(b1-b2);
  return sqrt(a*a+b*b);
}

void solve(vector<pii> &v) {
  int N = v.size();
  double ans = 10000.0;

  for(int i = 0; i < N; i++) {
    for(int j = i+1; j < N; j++) {
      double d = dist(v[i].first,v[i].second,v[j].first,v[j].second);
      if (d < ans) ans = d;  
    }
  }
  
  if (ans < 10000.0) {
    printf("%.4f\n",ans);
  } else {
    cout << INF << endl;
  }
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int x,y,N;
    while(scanf("%d\n",&N) != EOF) {
      if (N == 0) break;
      vector<pii> v(N);
      for(int i = 0; i < v.size(); i++) {
        scanf("%d %d\n",&x,&y);
        v[i].first = x; v[i].second = y;
      }
      solve(v);
    }
    return 0;
}
