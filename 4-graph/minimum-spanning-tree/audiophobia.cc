#include <algorithm>
#include <stack>
#include <cstdio>
#include <vector>
#include <utility>
#include <iostream>
#include <queue>
#include <climits>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using graph = vector<vector<pair<int,int>>>;

class UnionFind {
  private:
    ll numSets;
    vi rank, p, setSize;
  public:
  UnionFind(ll N) {
    numSets = N;
    p.assign(N,0); rank.assign(N,0);
    setSize.assign(N,1);
    for(int i = 0; i < N; i++) p[i] = i;
  }

  ll findSet(ll i) {
    return p[i] == i ? i : (p[i] = findSet(p[i]));
  }
  
  bool isSameSet(ll i, ll j) {
    return findSet(i) == findSet(j);  
  }

  void UnionSet(ll i, ll j) {
    if (!isSameSet(i, j)) {
      numSets--;
      int x = findSet(i);
      int y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
        setSize[x] += setSize[y];
      } else {
        p[x] = y;
        setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }
};

using EdgeList = vector<pair<ll,pair<ll,ll>>>;

int target;
vector<bool> visited;
vector<int> path;

void dfs(int start,graph &mst) {
  visited[start] = true;
  vector<pair<int,int>> neighbors = mst[start];
  path.push_back(start);
  for (auto p: neighbors) {
    if (!visited[p.first]) {
      dfs(p.first,mst);
      if (path.back() != target) path.pop_back();
    }
  }
}

void solve(int C,graph mst,vector<pair<int,int>> queries) {
  for (auto p: queries) {
    visited.assign(C,false);
    path.clear();
    cout << "Path from " << p.first << " -- " << p.second << endl;
    target = p.second;
    dfs(p.first,mst); 
  }
}

int main(int argc, char *argv[]) {
    if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    freopen(argv[1],"r",stdin);
    int C,S,Q,u,v,w,x,y;
    while(scanf("%d %d %d\n",&C,&S,&Q) != EOF) {
      if (C == 0 && (S == 0 && Q == 0)) break;
      UnionFind UF = UnionFind(C);
      EdgeList edges;
      while(S-- > 0) {
        scanf("%d %d %d\n",&u,&v,&w);
        u -= 1; v -= 1;
        edges.push_back(make_pair(w,make_pair(u,v)));
      }
      sort(edges.begin(),edges.end());
      graph mst(C);
      for(int i = 0; i < edges.size(); i++) {
        pair<ll,pair<ll,ll>> front = edges[i];
        ll a = front.second.first;
        ll b = front.second.second;
        if (!UF.isSameSet(a,b)) {
          mst[a].push_back(make_pair(b,front.first));
          mst[b].push_back(make_pair(a,front.first));
          UF.UnionSet(a,b); 
        }
      }
      vector<pair<int,int>> queries;
      while(Q-- > 0) {
        scanf("%d %d\n",&x,&y);
        x -= 1; y -= 1;
        queries.push_back(make_pair(x,y));
      }
      solve(C,mst,queries);
    }
    return 0;
}
