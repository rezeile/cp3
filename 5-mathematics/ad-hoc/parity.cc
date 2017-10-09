#include <cstdio>
#include <cmath>
#include <deque>
#include <string>
#include <set>
#include <functional>
using namespace std;

string toBitString(int N) {
  set<int,greater<int>> set; 
  while(N > 0) {
    int exp = (int) floor(log2(N)); 
    set.insert(exp);
    N -= pow(2,exp);
  }
  int largest = *(set.begin());
  string s = string();
  for(int i = 0; i <= largest; i++) {
    if (set.find(i) != set.end()) {
      s = '1' + s;
    } else {
      s = '0' + s;
    }
  }
  return s;
}

void parity(int N) {
  int p = __builtin_popcount(N);
  string s = toBitString(N);
  printf("The parity of %s is %d (mod 2).\n",s.c_str(),p);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N; 
    while(scanf("%d\n",&N) != EOF) {
      if (N == 0) break;
      parity(N);
    }
    return 0;
}
