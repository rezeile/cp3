#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

int lineCounter = 0;

void roads(int R, int N, vector<int> &v) {
  int left = R - N;
  int q = left / N;
  int r = left % N;
  int s = q + (r > 0);
  
  if (s > 26) printf("Case %d: impossible\n",++lineCounter);
  else printf("Case %d: %d\n",++lineCounter,s);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int a,b;
    while(scanf("%d %d",&a,&b) != EOF) {
      if (a == 0 && b == 0) break;
      vector<int> v(b+1,26);
      roads(a,b,v);
    }
    return 0;
}
