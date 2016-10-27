#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
    freopen("../input/vertex-03","w+",stdout);
    // number of vertices
    int N = 100;
    printf("%d\n",N);
    for(int i = 1; i < 100; i++) {
        printf("%d %d %d\n",i,i+1 ,0);
    }
    printf("%d %d %d\n",100,100,0);
    printf("0\n");
    printf("%d %d %d\n%d\n",2,1,100,0);
    return 0;
}
