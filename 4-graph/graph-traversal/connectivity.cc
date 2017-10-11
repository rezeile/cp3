#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
#include <set>

using namespace std;

using vvi = vector<set<int>>;

void printVector(set<int> &s) {
  vector<int> v(s.begin(),s.end());
  if (!v.empty()) {
    printf("%d",v[0]);
    for(int i = 1; i < v.size(); i++) {
      printf(" %d",v[i]);
    }
  }
  printf("\n");
}

void printAdjList(vvi &adjList) {
  for(int i = 0; i < adjList.size(); i++) {
    printf("%d: ",i); printVector(adjList[i]);
  }
}

void dfs(int node,vvi &adjList, vector<bool> &visited) {
  // mark node as visited 
  visited[node] = 1;
  // visited all adjacent nodes
  set<int> neighbors = adjList[node];
  for(auto i: neighbors) {
    if (!visited[i]) dfs(i,adjList,visited);
  }
}

void solve(vvi &adjList) {
  //printAdjList(adjList);
  vector<bool> visited(adjList.size(),0);
  int numCC = 0;
  for(int i = 0; i < visited.size(); i++) {
    if (!visited[i]) { dfs(i,adjList,visited); numCC++; }
  }
  printf("%d\n",numCC);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    int TC; 
    string input;
    getline(cin,input); 
    stringstream ss(input); ss >> TC;
    getline(cin,input); // first blank line 
    for(int i = 0; i < TC; i++) {
      vvi adjList;
      while(getline(cin,input)) {
        if (input == "") break; // end of input 
        if (input.size() == 1) adjList.resize((input[0] - 'A') + 1);
        else {
          adjList[input[0]-'A'].insert(input[1]-'A');
          adjList[input[1]-'A'].insert(input[0]-'A');
        }
      }
      solve(adjList);
      if (i != TC-1) printf("\n");
    }
    return 0;
}
