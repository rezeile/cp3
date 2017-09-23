#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;

int getIndex(int d, int k) {
  double c = -((2*k) / (double)d);
  int root = (int) ceil((-1 + sqrt(1 - 4*c))/2);
  return root;
}

void solution(vector<long> &v,int d,int k) {
  // identify the polynomial index
  
  int x = getIndex(d,k);
  long res = 0;
  for(int i = 0; i < v.size(); i++) {
    res += v[i] > 0 ? v[i] * pow(x,i) : 0;
  }
  printf("%ld\n",res);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    int C;
    scanf("%d",&C);
    for(int i = 0; i < C; i++) {
      int deg,d,k;
      scanf("%d",&deg);
      vector<long> v(deg + 1);
      for(int j = 0; j <= deg; j++) {
        int num; scanf("%d",&num);
        v[j] = num;
      }
      scanf("%d",&d);
      scanf("%d",&k);
      solution(v,d,k);
    }
    return 0;
}
