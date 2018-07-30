#include <cstdio>
using namespace std;

using ull = unsigned long long;
using ld = long double;

const ull CASE_COUNTER = 0;
const ull ZERO = 0.0000;
const double EPSILON = 0.0001;
const char* CANT = "can't determine";

/* Variable Definitions
 * --------------------
 * d = [width of river]
 * v = [river flow velocity]
 * u = [boat speed up rate]
 */
void solve(ull d, ull v, ull u) {
  
  /* BEGIN TO SOLVE */
  if (v - ZERO < EPSILON) {
    printf("%s\n",CANT);
  } else {
     ld res = 1.0;
     printf("Case %llu: %.3Lf\n",CASE_COUNTER,res); 
  }
  /* END SOLVING SECTION */
 }

int main(int argc, char *argv[]) {
  if(argc < 2) { fprintf(stderr,"enter an input file\n"); return -1; }
  freopen(argv[1],"r",stdin);
  ull TC,a,b,c;
  scanf("%llu\n",&TC);
  while(TC-- > 0) {
    scanf("%llu %llu %llu\n",&a,&b,&c);
    solve(a,b,c); 
  }
  return 0;
}
