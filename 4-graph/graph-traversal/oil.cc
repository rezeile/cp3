#include <cstdio>
#include <string>
#include <iostream>
#include <vector>
#include <cstring>
using namespace std;

using ll = long long;

bool visited[101][101];

bool valid(ll i, ll j, ll n, ll m) {
  return ((i >= 0 && i < n) && (j >= 0 && j < m));
}

void visitNeighbors(vector<string> &grid,ll i, ll j, ll n, ll m) {
  for(int a = -1; a <= 1; a++) {
    for(int b = -1; b <= 1; b++) {
      if (a == 0 && b == 0) continue;
      ll I = i + a, J = j + b;
      if (valid(I,J,n,m)) {
        if (grid[I][J] == '@' && !visited[I][J]) {
          visited[I][J] = 1;
          visitNeighbors(grid,I,J,n,m);
        }
      }
    }
  }
}

void solve(vector<string> &grid,ll n, ll m) {
  memset(visited,0,sizeof visited);
  ll count = 0;
  for(ll i = 0; i < n; i++) {
    for(ll j = 0; j < m; j++) {
      if (grid[i][j] == '@' && !visited[i][j]) {
        count++; visited[i][j] = 1;
        visitNeighbors(grid,i,j,n,m);
      }
    }
  }
  printf("%lld\n",count);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    ll n,m;
    while(scanf("%lld %lld\n",&n,&m)) {
      if (n == 0 && m == 0) break;
      vector<string> grid(n);
      for(int i = 0; i < n; i++) {
        getline(cin,grid[i]);
      }
      solve(grid,n,m);
    }
    return 0;
}
