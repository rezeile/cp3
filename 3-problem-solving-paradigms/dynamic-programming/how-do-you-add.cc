#include <cstdio>
#include <cstring>
using namespace std;

int memo[101][101];

int ways(int N, int K) {
    if (K <= 1) return K;
    if (K == 2) return N + 1;
    if (memo[N][K] != -1) return memo[N][K];
    int sum = 0;
    for(int i = 0; i <= N; i++) {
        if(memo[N-i][K-1] != -1) sum += memo[N-i][K-1];
        else sum += memo[N-i][K-1] = ways(N-i,K-1);
    }
    return memo[N][K] = sum % 1000000;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    int N,K;
    memset(memo,-1,sizeof memo);
    while (scanf("%d %d",&N,&K) != EOF) {
        if (N != 0 && K != 0) {
            printf("%d\n",ways(N,K));
        }
    }
    return 0;
}
