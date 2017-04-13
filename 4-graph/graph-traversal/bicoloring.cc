#include <cstdio>
#include <vector>
#include <utility>
#include <queue>
using namespace std;
using graph = vector<vector<pair<int,int>>>;

void bipartiteCheck(graph &g,int source) {
    queue<pair<int,int>> q;
    q.push(make_pair(source,0));

    while (!q.empty()) {
        pair<int,int> node = q.front(); q.pop();
        int next_color = node.second == 0 ? 1 : 0;
        
        for (int i = 0; i < g[node.first].size(); i++) {
            if (g[node.first][i].second == -1) { 
                g[node.first][i].second = next_color;
                q.push(g[node.first][i]);
            }
            if (g[node.first][i].second != next_color) { printf("NOT BICOLORABLE.\n"); return; }
        }
    }
    printf("BICOLORABLE.\n");
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    int N,L;
    while ( scanf("%d\n",&N) != EOF) {
        if (N == 0) break;
        scanf("%d\n",&L);
        int s,d;
        graph g(N);
        int source = 0;
        for(int i = 0; i < L; i++) {
            scanf("%d %d\n",&s,&d);
            if (source == 0) source = s;
            g[s].push_back(make_pair(d,-1));
            g[d].push_back(make_pair(s,-1));
        }
        bipartiteCheck(g,source); 
    }
    return 0;
}
