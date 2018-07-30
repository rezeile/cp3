#include <cstdio>
#include <vector>
#include <iostream>
using namespace std;

void solve(vector<double> &v) {
  for(int i = 0; i < v.size(); i++) {
    cout << v[i] << endl;
  }
}

int main(int argc, char *argv[]) {
  if(argc < 2) { fprintf(stderr,"enter an input file\n"); return -1; }
  freopen(argv[1],"r",stdin);
 
  int N;
  while (cin >> N) {
    if (N == 0) break;
    vector<double> v(N);
    for(int i = 0; i < N; i++) {
      double price;
      scanf("%lf\n", &price);
      v.push_back(price);
      solve(v);
    }
  }
  return 0;
}
