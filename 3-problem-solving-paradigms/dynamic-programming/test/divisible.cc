#include <iostream>
#include <cstdio>
#include <cstdlib> // for srand 
using namespace std;

int main(int argc, char *argv[]) {
    freopen("../input/divisible-03","w+",stdout);
    int MAX = 10;
    int MAX_Q = 10;
    int D,M;
    srand(time(NULL));
    for(int i = 0; i < MAX; i++) {
        int N = rand() % 200 + 1;
        // want M <= N and 
        printf("%d %d\n",N,MAX_Q);
        for(int j = 1; j <= N; j++) {
            printf("%d\n",j);
        }
        for(int k = 0; k < MAX_Q; k++) {
            D = rand() % 20 + 1;
            M = rand() % 10 + 1;
            if(M > N) M = N;
            printf("%d %d\n",D,M); 
        }
    }
    printf("%d %d\n",0,0);
    return 0;
}
