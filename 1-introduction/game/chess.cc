#include <cstdio>
using namespace std;

void maxPieces(char piece, int m, int n) {

}

int main(int argc, char *argv[]) {
    if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    freopen(argv[1],"r",stdin);
    int N,m,n;
    char piece;
    
    scanf("%d\n",&N);
    for(int k = 0; k < N; k++) {
      scanf("%c %d %d\n",&piece,&m,&n);
      maxPieces(piece,m,n);
    }
    
    return 0;
}
