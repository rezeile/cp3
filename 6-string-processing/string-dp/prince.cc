#include <algorithm>
#include <cstdio>
#include <vector>
#include <iostream>
#include <vector>
#include <utility>
#include <unordered_map>
#include <set>
#include <iterator>
#include <deque>
using namespace std;


using vi = vector<int>;
using uint = unsigned int;
int lineCounter = 0;

void printVector(vi &v) {
  if (v.empty()) cout << "[]" << endl;
  else {
    printf("%d",v[0]);
    for(int i = 1; i < v.size(); i++) {
      printf(" %d",v[i]);
    }
    printf("\n");
  }
}

void solve(vi &v1, vi &v2,int n) {
  // find common set 
  set<int> ref;
  vector<int> target;
  if (v1.size() < v2.size()) {
    ref = set<int>(v1.begin(),v1.end());
    target = v2;
  } else {
    ref = set<int>(v2.begin(),v2.end());
    target = v1;
  }

  set<int> common;
  for(auto &i: target) {
    if (ref.find(i) != ref.end()) common.insert(i);
  }
  // trim vectors 
  vector<int> nv1, nv2;
  for(int i = 0; i < v1.size(); i++) {
    if (common.find(v1[i]) != common.end()) nv1.push_back(v1[i]);
  }
  
  unordered_map<int,int> map;
  for(int i = 0; i < v2.size(); i++) {
    if (common.find(v2[i]) != common.end()) {
      nv2.push_back(v2[i]);
      map.insert(make_pair(v2[i],nv2.size()-1)); 
    }
  }

  // run LIS on index vector
  vector<int> index_vector;
  for(int i = 0; i <  nv1.size(); i++) {
    index_vector.push_back(map.find(nv1[i])->second);
  }
  
  vector<int> lis;
  for(int i = 0; i < index_vector.size(); i++) {
    int index = lower_bound(lis.begin(),lis.end(),index_vector[i]) - lis.begin();
    if (index <= 0 && lis.empty()) lis.push_back(index_vector[i]);
    else if  (index >= lis.size()) lis.push_back(index_vector[i]);
    else if (lis[index] > index_vector[i]) lis[index] = index_vector[i];
  }
 
  printf("Case %d: %d\n",++lineCounter,(int) lis.size());
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
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
