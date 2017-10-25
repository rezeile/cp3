#include <cstdio>
#include <utility>
#include <vector>
#include <unordered_map>
using namespace std;

#define VEC_SIZE 1000001

using AdjList = unordered_map<int,vector<int>>;

int n,m;

void solve(AdjList &list, vector<pair<int,int>> &q) {
  for (pair<int,int> p: q) {
    int k = p.first, v = p.second;
    if (list.find(v) == list.end()) { printf("%d\n",0); continue; }
    vector<int> occur = list.find(v)->second; 
    if (k > occur.size()) printf("%d\n",0);
    else printf("%d\n",occur[k-1]);
  }
}

void insertToList(AdjList &list, int x, int i) {
  auto search = list.find(x);
  if (search == list.end()) {
    list.insert(make_pair(x,vector<int>(1,i)));
  } else {
    search->second.push_back(i);
  }
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    vector<pair<int,int>> q;
    
    while(scanf("%d %d\n",&n,&m) != EOF) {
      AdjList list;
      
      for(int i = 1; i <= n; i++) {
          int x; scanf("%d",&x); 
          insertToList(list,x,i);
      }
      q.resize(m);
      for(int i = 0; i < m; i++) {
        int k, v; scanf("%d %d\n",&k,&v);
        q[i].first = k; q[i].second = v;
      }
      solve(list,q);
    }
    return 0;
}
