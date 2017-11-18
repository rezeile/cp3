#include <cstdio>
#include <string>
#include <vector>
#include <iostream>
#include <sstream>
#include <utility>
#include <algorithm>
using namespace std;

#define UNVISITED -1
using ll = long long;
using graph = vector<vector<ll>>;

vector<ll> dfs_num;
vector<ll> dfs_low;
vector<ll> parent;
ll dfsCounter;
vector<pair<ll,ll>> bridges;
ll rootChildren;
ll dfsRoot;

void articulationBridges(ll u,graph &g) {
  dfs_num[u] = dfs_low[u] = dfsCounter++;
  for(int i = 0; i < g[u].size(); i++) {
    ll small,large,v = g[u][i];
    if (dfs_num[v] == UNVISITED) {
      parent[v] = u;
      //if (parent[v] == dfsRoot) rootChildren++;
      articulationBridges(v,g);
      if (dfs_low[v] > dfs_num[u]){
        if (u < v) {
          small = u;
          large = v;
        } else {
          small = v;
          large = u; 
        }
        bridges.push_back(make_pair(small,large));
      }
      dfs_low[u] = min(dfs_low[u],dfs_low[v]);
    } else {
      if (parent[u] != v) 
        dfs_low[u] = min(dfs_low[u],dfs_num[v]);
    }
  }
}

void parseConnections(graph &g,ll vertex,string s) {
  vector<ll> v;
  if (!s.empty()) {
    string delimiter = " ";
    size_t pos = 0;
    string token;
    while((pos = s.find(delimiter)) != string::npos) {
      token = s.substr(0,pos);
      v.push_back(stoll(token));
      s.erase(0,pos + delimiter.length());
    }
    v.push_back(stoll(s));
  }
  g[vertex] = v;
}

pair<ll,string> parseVertex(string input) {
  size_t pos = 0;
  string delimiter = " ";
  ll vertex;
  string token;
  for(int i = 0; i < 2; i++) {
    pos = input.find(delimiter);
    token = input.substr(0,pos);
    if (i == 0) vertex = stoll(token);
    input.erase(0,pos + delimiter.length());
  }
  if (input[0] == '(') input = "";
  return make_pair(vertex,input);
}


void solve(graph &g) {
  dfs_num.assign(g.size(),UNVISITED);
  dfs_low.assign(g.size(),0);
  parent.assign(g.size(),0);
  bridges.clear();
  dfsCounter = 0;
  for(int i = 0; i < g.size(); i++) {
    if (dfs_num[i] == UNVISITED) {
      dfsRoot = i; 
      articulationBridges(i,g);
    }
  }
}

struct compare {
  bool operator() (const pair<ll,ll> &lhs, const pair <ll,ll> &rhs) {
    if (lhs.first == rhs.first) return lhs.second < rhs.second;
    return lhs.first < rhs.first;
  }
};

void printOutput(vector<pair<ll,ll>> &bridges) {
  cout << bridges.size() << " critical links" << endl; 
  for(auto &p : bridges) {
    cout << p.first << " - " << p.second << endl;
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    ll N;
    string input;
    while(getline(cin,input)) {
      if (input.empty()) break;
      stringstream ss(input); ss >> N;
      //if (N == 0) break;
      graph g(N);
      for(int i = 0; i < N; i++) {
        getline(cin,input);
        pair<ll,string> p = parseVertex(input);
        parseConnections(g,p.first,p.second);
      }
      solve(g);
      sort(bridges.begin(),bridges.end(),compare());
      printOutput(bridges);
      getline(cin,input); // blank line 
    }
    return 0;
}
