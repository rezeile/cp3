#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int TC,R,C,M,N,W,a,b;
    cin >> TC;
    for(int i = 0; i < TC; i++) {
        cin >> R >> C >> M >> N;
        cin >> W;
        for(int j = 0; j < W; j++) {
            cin >> a >> b;
            printf("%d %d\n",a,b);
        }
    }
    return 0;
}
