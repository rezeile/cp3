#include <cstdio>
#include <cstring>
using namespace std;
using ll = long long;
ll coins[5] = {1,5,10,25,50}, memo[5][30001];;

ll countWays(ll type, ll N) {
    if (type > 4 || N < 0) return 0;
    if (N == 0) return 1;
    if (memo[type][N] != -1) return memo[type][N];
    return memo[type][N] = countWays(type,N-coins[type]) + countWays(type+1,N);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    ll N;
    memset(memo,-1,sizeof memo);
    while ( scanf("%lld",&N) != EOF ) {
        ll result = countWays(0,N);
        if (result == 1) printf("There is only %lld way to produce %lld cents change.\n",result,N);
        else printf("There are %lld ways to produce %lld cents change.\n",result,N); 
    }
    return 0;
}
