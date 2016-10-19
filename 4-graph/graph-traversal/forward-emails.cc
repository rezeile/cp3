#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

typedef vector<int> graph;

int emailMaximizer(graph &g) {
    return 0;
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int TC,N,u,v;
    cin >> TC;
    for(int i = 0; i < TC; i++) {
        cin >> N;
        graph g(N + 1);
        for(int j = 0; j < N; j++) {
            scanf("%d %d",&u,&v);
            g[u] = v;
        }
        cout << emailMaximizer(g) << endl;
    }
    return 0;
}
