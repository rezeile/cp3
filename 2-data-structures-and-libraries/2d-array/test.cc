#include <iostream>
#include <cstdio>
#include <cstdlib> // for srand 
using namespace std;

int main(int argc, char *argv[]) {
    freopen("input/spiral03","w+",stdout);
    int SZ = 100000;
    int P = 1;
    int MAX = 100000;
    for(int i = 0; i < MAX; i++) {
        printf("%d %d\n",SZ,P);
    }
    printf("%d %d\n",0,0);
    return 0;
}
