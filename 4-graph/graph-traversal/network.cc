#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <set>
using namespace std;

#define UNVISITED -1
using graph = vector<vector<int>>;

set<int> cpoints;
void printCriticalPoints() {
  for(int i: cpoints) {
    printf("%d ",i);
  }
  printf("\n");
}

void printVector(vector<int> &v) {
  if (!v.empty()) {
    printf("%d",v[0]);
    for(int i = 1; i < v.size(); i++) {
      printf(" %d",v[i]);
    }
    printf("\n");
  }
}

void printGraph(graph &g) {
  for(int i = 0; i < g.size(); i++) {
    printf("%d: ",i);
    printVector(g[i]);
  }
  printf("\n");
}

vector<int> dfs_num;
vector<int> dfs_low;
vector<int> parent;

int dfsCounter = 0;
int dfsRoot;
int rootChildren = 0;

void criticalPoints(int u,graph &g, int N) {
  dfs_num[u] = dfs_low[u] = dfsCounter++;
  for(int i = 0; i < g[u].size(); i++) {
    int v = g[u][i];
    if (dfs_num[v] == UNVISITED) {
      parent[v] = u;
      if (parent[v] == dfsRoot) rootChildren++;
      criticalPoints(v,g,N);
      if (dfs_low[v] >= dfs_num[u]){
        if (u != dfsRoot) cpoints.insert(u);
      }
      dfs_low[u] = min(dfs_low[u],dfs_low[v]);
    } else {
      if (parent[u] != v) 
        dfs_low[u] = min(dfs_low[u],dfs_num[v]);
    }
  }
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    int N,v;
    string input;
    getline(cin,input); 
    stringstream ss(input); ss >> N;
  
    while(N != 0) {
      graph g(N);
      while(getline(cin,input)) {
        if (input[0] == '0') break;
        stringstream ss(input);;
        int v,e; ss >> v;
        while(ss >> e) {
          g[v-1].push_back(e-1);
          g[e-1].push_back(v-1);
        }
      }
      /* Initialize Data Structures */
      dfs_num.assign(N,UNVISITED);
      dfs_low.assign(N,0);
      parent.assign(N,0);
      dfsCounter = 0;
      cpoints.clear();
      for(int i = 0; i < N; i++) {
        if (dfs_num[i] == UNVISITED) {
          dfsRoot = i; rootChildren = 0;
          criticalPoints(i,g,N);
          if (rootChildren > 1)
            cpoints.insert(dfsRoot);
        }
      }
      printf("%ld\n",cpoints.size());
      getline(cin,input);
      stringstream ss(input); ss >> N;
    }
    return 0;
}
