#include <cstdio>
#include <vector>
#include <utility>
#include <algorithm>
using namespace std;

using ll = long long;
using vi = vector<ll>;
using EdgeList  = vector<pair<ll,pair<ll,ll>>>;

class compare {
  public:
    bool operator() (const pair<ll,pair<ll,ll>> &lhs,const pair<ll,pair<ll,ll>> &rhs) {
      return lhs.first < rhs.first;
    }
};

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

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    ll V,E;
    while (scanf("%lld %lld\n",&V,&E) != EOF) {
      EdgeList elist;
      if (V == 0 && E == 0) break;
      UnionFind UF = UnionFind(V);
      for(int i = 0; i < E; i++) {
        ll u, v, w;
        scanf("%lld %lld %lld\n",&u,&v,&w);
        elist.push_back(make_pair(w,make_pair(u,v)));
      }
      sort(elist.begin(),elist.end(),compare());
      int mst_cost = 0;
      int total = 0;
      for(int i = 0; i < elist.size(); i++) {
        pair<ll,pair<ll,ll>> front = elist[i];
        if (!UF.isSameSet(front.second.first,front.second.second)) {
          mst_cost += front.first;
          UF.UnionSet(front.second.first, front.second.second); 
        }
        total += front.first;
      }
      printf("%d\n",total - mst_cost);
    }
    return 0;
}
