#include <iostream>
#include <cstdio>
#include <vector>
#include <unordered_set>
using namespace std;

typedef vector<int> graph;

int dfs(int v, graph &g,vector<int> &reachable_friends) {
    unordered_set<int> s;
    int index = g[v];
    vector<bool> visited(g.size() + 1); visited[v] = 1;
    int count = 1;
    while(!visited[index]) {
        visited[index] = 1;
        count++;
        s.insert(index);
        index = g[index];
    }
    if(index == v){
        s.insert(v);
        for(auto i : s) {
            reachable_friends[i] = count;
        }
    }
    return count;
}

int emailMaximizer(graph &g) {
    int vertex  = 1;
    int max = -1;
    vector<int> reachable_friends(g.size() + 1,-1);
    int count;
    for(int v = 1; v < g.size(); v++) {
        count = reachable_friends[v];
        if(count == -1) count = dfs(v,g,reachable_friends);
        if(count > max) { vertex = v; max = count; }
    }
    return vertex;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    int TC,N,u,v;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cin >> N;
        graph g(N + 1);
        for(int j = 0; j < N; j++) {
            scanf("%d %d",&u,&v);
            g[u] = v;
        }
        cout << "Case " << i << ": " << emailMaximizer(g) << endl;
    }
    return 0;
}
