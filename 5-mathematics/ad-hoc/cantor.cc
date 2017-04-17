#include <cstdio>
#include <cmath>
using namespace std;

void cantor(int N) {
    int num = ceil((-1 + sqrt(1 + 8*N))/2);
    int a = 1, b = 1;
    int count = 1;
    bool increase = false;
    for(int i = 2; i <= num; i++) {
        increase = i % 2 == 0 ? true : false;
        for(int j = 1; j <= i; j++) {
            count++;
            if (j == 1) {
                increase ? b++ : a++;
            } else {
                if(increase) { b--; a++; }
                else { b++; a--; }
            }
            if (count == N) {
                printf("TERM %d IS %d/%d\n",N,a,b);
                return;
            }
        }
    }
    printf("TERM %d IS %d/%d\n",N,a,b);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N;
    while(scanf("%d",&N) != EOF) {
        cantor(N);
    }
    return 0;
}
