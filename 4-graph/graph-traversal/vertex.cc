#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
#include <queue>
using namespace std;

typedef vector<vector<int>> graph;

#define DFS_WHITE -1
#define DFS_GRAY 0
#define DFS_BLACK 1

vector<int> visited;
vector<bool> reachable;

void dfs(int vertex,graph &g) {
    if(g.empty()) return;
    visited[vertex] = DFS_GRAY;
    for(int i = 0; i < g[vertex].size(); i++) {
        int neighbor = g[vertex][i];
        reachable[neighbor] = true;
        if(visited[neighbor] == DFS_WHITE) {
            dfs(neighbor,g);
        }
    }
    visited[vertex] = DFS_BLACK;
}

void printUnreachable() {
    vector<int> items;
    int count  = 0;
    for(int i = 1; i < reachable.size(); i++) {
        if(!reachable[i])  { items.push_back(i); count++; }
    }
    if(count) printf("%d ",count);
    else printf("%d",count);
    for(int i = 0; i < items.size(); i++) {
        if(i != items.size() -1) printf("%d ",items[i]);
        else printf("%d",items[i]);
    }
    printf("\n");
}

void findUnreachable(graph &g, vector<int> &sv) {
    for(auto vertex : sv) {
        visited.assign(g.size(),DFS_WHITE);
        reachable.assign(g.size(),false);
        dfs(vertex,g);
        printUnreachable();
    }
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    int N,vertex;
    string input;
    stringstream ss;
    while(getline(cin,input)) {
        if((N = stoi(input)) == 0) break;        
        graph g(N+1);
        string adj_list;
        while(getline(cin,adj_list)) {
            if(stoi(adj_list) == 0) break;
            stringstream ss;
            ss << adj_list;
            ss >> vertex;
            int neighbor;
            while(ss >> neighbor) {
                if(neighbor == 0) break;
                g[vertex].push_back(neighbor);
            }
        }
        vector<int> sv; // start vertices
        string query;
        getline(cin,query);
        stringstream ss(query);
        int query_length;
        ss >> query_length;
        for(int i = 0; i < query_length; i++) {
            int val;
            ss >> val;
            sv.push_back(val);
        }
        findUnreachable(g,sv);
    }
    return 0;
}
