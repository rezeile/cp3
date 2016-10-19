#include <iostream>
#include <cstdio>
#include <cstdlib>
using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input integer." << endl; return 0; }
    freopen("input/forward-03.txt","w+",stdout);
    int TC = 1,u,v;
    int N = atoi(argv[1]);
    printf("%d\n%d\n",TC,N);
    for(int i = 1; i <= N; i++) {
        if(i != N) { u = i; v = i + 1;}
        else {u = i; v = 1; }
        printf("%d %d\n",u,v);
    }
    return 0;
}
