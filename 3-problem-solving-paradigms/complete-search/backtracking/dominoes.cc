#include <cstdio>
#include <vector>
#include <utility>
#include <cstring>
using namespace std;

using vii = vector<pair<int,int>>;

int N,m,x,y,l1,l2,r1,r2;

int counter = 0;
int visited[20];
int target[20];

vector<int> candidate_list(int target, vii &pieces) {
  vector<int> list;
    for(int i = 0; i < pieces.size(); i++) {
    if (!visited[i]) {
      if (pieces[i].first == target || pieces[i].second == target) {
        list.push_back(i);
      }
    }
  }
  return list;
}

bool solutionHelper(int i, vii &pieces) {
  if (i == N && target[i] == r1) {
      return true;
  }

  vector<int> clist = candidate_list(target[i],pieces);

  if (clist.empty()) return false;
  else {
    for(int j = 0; j < clist.size(); j++) {
      visited[clist[j]] = 1;
      pair<int,int> d = pieces[clist[j]];
      int old_target = target[i+1];
      // opposite of matching adjacent sides
      target[i+1] = d.first == target[i] ? d.second : d.first;
      if (solutionHelper(i+1,pieces)) {
        return true;
      }
      target[i+1] = old_target;
      visited[clist[j]] = 0;
    }
  }
  return false;
}

void solution (vii &pieces) {
  memset(target,0,sizeof target);
  memset(visited,0,sizeof visited);
  target[0] = l2;
  if (solutionHelper(0,pieces)) {
    printf("YES\n");
    return;
  }
  printf("NO\n");
}

void debug(int i) {
  printf("N = %d, m = %d\n",N,m);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    while(scanf("%d",&N)) {
      if (N == 0) break;
      scanf("%d",&m);
      scanf("%d %d",&l1,&l2);
      scanf("%d %d",&r1,&r2);
      vii pieces;
      for(int i = 0; i < m; i++) {
        scanf("%d %d",&x,&y);
        pieces.push_back(make_pair(x,y));
      }
      solution(pieces); 
    }
    return 0;
}
