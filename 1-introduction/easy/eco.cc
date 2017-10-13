#include <cstdio>
using namespace std;

using ll = long long;
int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    ll N,F,a,b,c; scanf("%lld\n",&N);
    for(int i = 0; i < N; i++) {
      scanf("%lld\n",&F);
      ll burden = 0;
      while(F-- > 0) {
        scanf("%lld %lld %lld\n",&a,&b,&c);
        burden += a*c;
      }
      printf("%lld\n",burden);
    }
    return 0;
}
