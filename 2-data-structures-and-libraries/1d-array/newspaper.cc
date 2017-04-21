#include <cstdio>
#include <iostream>
#include <string>
#include <cstring>
using namespace std;

void printResult(long long total_cents) {
    long long d = total_cents / 100;
    long long c = total_cents % 100;
    printf("%lld.%.2lld$\n",d,c);
}
    
int main(int argc, char *argv[]) {
    //if (argc < 2) { printf("enter an input file.\n"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N;
    scanf("%d\n",&N);
    for(int i = 0; i < N; i++) {
        int M;
        scanf("%d\n",&M);
        int carr[256];
        memset(carr,0,sizeof carr);
        for(int j = 0; j < M; j++) {
            unsigned char a;
            int b;
            scanf("%c %d\n",&a,&b);
            carr[a-0] = b;
        }
        int K;
        scanf("%d\n",&K);
        long long sum = 0;
        for(int j = 0; j < K; j++) {
            unsigned char buf[10000];
            fgets((char*)buf,sizeof buf,stdin);
            int i = 0;
            while(buf[i] != '\n') {
                sum += carr[buf[i++]-0];
            }
        }
        printResult(sum);
    }
    return 0;
}
