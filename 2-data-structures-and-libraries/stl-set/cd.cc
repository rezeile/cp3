#include <cstdio>
#include <set>
using namespace std;

void cd(set<int> &jack,set<int> &jill) {
    int sell = 0;
    for(auto cd : jack) {
        if(jill.find(cd) != jill.end()) sell++;
    }
    printf("%d\n",sell);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N,M;
    while (scanf("%d %d\n",&N,&M) != EOF) {
        if(N == 0 && M == 0) break;
        set<int> jack,jill;
        for(int i = 0; i < N; i++) {
            int num;
            scanf("%d\n",&num); jack.insert(num);
            
        }
        for(int i = 0; i < M; i++) {
            int num;
            scanf("%d\n",&num); jill.insert(num);
        }
        cd(jack,jill);
    }
    return 0;
}
