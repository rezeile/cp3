#include <cstdio>
#include <vector>
#include <iostream>
#include <unordered_map>
#include <utility>
#include <iterator>
using namespace std;

using vi = vector<int>;
using uint = unsigned int;
int lineCounter = 0;

uint getIndex(int i,int j,int n) {
  return (uint) i * n + j; 
}

void solve(vi &s1, vi &s2,int n) {
  unordered_map<uint,int> map;
  unordered_map<uint,int>::iterator it;
  int res = 0;
  if (s1.empty() || s2.empty()) 
    res = 0;
  else {
    for(int i = 0; i < s1.size(); i++) {
      for(int j = 0; j < s2.size(); j++) {
        //printf("s1[%d] = %d, s2[%d] = %d\n",i,s1[i],j,s2[j]);
        //printf("index = %u\n",getIndex(i,j,n));
        int val = 0, val2 = 0;
        if (s1[i] != s2[j]) {
          if (i > 0) {
            uint index = getIndex(i-1,j,n);
            it = map.find(index);
            val = it->second;
          }
          if (j > 0) {
            uint index = getIndex(i,j-1,n);
            it = map.find(index);
            val2 = it->second;
          }
          val = max(val,val2);
          uint index = getIndex(i,j,n); 
          map.insert(make_pair(index,val));
        } else {
          if (i > 0 && j > 0) {
            uint index = getIndex(i-1,j-1,n); 
            it = map.find(index);
            val = it->second;
          }
          uint index = getIndex(i,j,n);
          map.insert(make_pair(index,val + 1));
        }
      }
    }
    uint index = getIndex(s1.size()-1,s2.size()-1,n);
    it = map.find(index);
    res = it->second;
  }
  
  cout << "Case " << ++lineCounter << ": " << res << endl;
}

int main(int argc, char *argv[]) {
    if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    freopen(argv[1],"r",stdin);
    int T,n,p,q, c; scanf("%d",&T);
    for(int i = 0; i < T; i++) {
       scanf("%d",&n); scanf("%d",&p); scanf("%d",&q);
       vector<int> v1(p + 1), v2(q + 1);
       for(int i = 0; i <= p; i++) {
        scanf("%d",&c); v1[i] = c;
       }
       for(int i = 0; i <= q; i++) {
        scanf("%d",&c); v2[i] = c;
       }
       solve(v1,v2,n); 
    }
    return 0;
}
