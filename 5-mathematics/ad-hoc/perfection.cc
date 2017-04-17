#include <cstdio>

using namespace std;

void perfection(int N) {
    int sum = 0;
    for(int i = 1; i <= N/2; i++) {
        if (N % i == 0) sum += i;
    }
    if (N == sum) printf("%5d %s\n",N," PERFECT");
    else if (N < sum) printf("%5d %s\n",N," ABUNDANT");
    else  printf("%5d %s\n",N," DEFICIENT");
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N;
    printf("PERFECTION OUTPUT\n");
    while (scanf("%d",&N) != EOF) {
        if (N != 0) {
            perfection(N);
        }
    }
    printf("END OF OUTPUT\n");
    return 0;
}
