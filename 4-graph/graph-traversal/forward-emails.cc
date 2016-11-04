/* 
 * Author: Eliezer Abate
 * Date: 11/3/2016
 *
 */

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
    int top = vertex;
    while(!s.empty()) {
        top = s.top();
        visited[top] = true;
        max_source[top] = source;
        max += 1;
        s.pop();
        if(!visited[g[top]]) s.push(g[top]); 
    }
    max_map[vertex] = max;
}

int findSender(graph &g) {
    int tot_max = 0;
    int best = 0;
    for(int i = 1; i < g.size(); i++) {
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
