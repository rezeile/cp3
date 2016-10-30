#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <unordered_map>
#include <stack>
using namespace std;

typedef vector<int> graph;

vector<bool> visited;
vector<int> max_source;
unordered_map<int,int> max_map;

void dfs(int vertex,graph &g,int &max,int source) {
    visited[vertex] = true;
    max += 1;
    max_source[vertex] = source;
    if(!visited[g[vertex]]) dfs(g[vertex],g,max,source);
}

void dfsIterative(int vertex,graph &g,int &max, int source) {
    stack<int> s;
    s.push(vertex);
    visited[vertex] = true;
    max += 1;
    max_source[vertex] = source;
    while(!s.empty()) {
        int top = s.top();
        s.pop();
        if(!visited[g[top]]){
           visited[g[top]] = true;
           max += 1;
           max_source[g[top]] = source;
           s.push(g[top]); 
        }
    }
}

int findSender(graph &g) {
    int tot_max = 0;
    int best = 0;
    for(int i = 1; i < g.size(); i++) {
        int max = 0;
        int ms = max_source[g[i]];
        if(!visited[i]){
            if(ms != -1) {
                max = max_map[ms] + 1; 
                visited[i] = true; 
                max_source[i] = i;
            }
            else dfsIterative(i,g,max,i);
            if(max > tot_max) {
                tot_max = max; best = i; 
                max_map.insert(make_pair(i,max));
            } 
        }
    }
    return best;
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    
    int TC,N,a,b;
    cin >> TC;
    for(int i = 1; i <= TC; i++) {
        cin >> N;
        graph g(N+1);
        visited.assign(N+1,false);
        max_source.assign(N+1,-1);
        max_map.clear();
        for(int j = 0; j < N; j++) {
            scanf("%d %d",&a,&b);
            g[a] = b;
        }
        printf("Case %d: %d\n",i,findSender(g));
    }
    return 0;
}
