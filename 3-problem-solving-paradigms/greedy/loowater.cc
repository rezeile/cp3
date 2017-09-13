#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

void loowater(vector<int> &dragons, vector<int> &knights) {
  sort(dragons.begin(),dragons.end());
  sort(knights.begin(),knights.end());

  int gold = 0, d = 0, k = 0;
  
  while (d < dragons.size() && k < knights.size()) {
    while (dragons[d] > knights[k] && k < knights.size()) k++;
    if (k == knights.size()) break;
    gold += knights[k];
    d++; k++;
  }

  if (d == dragons.size()) 
    printf("%d\n",gold);
  else 
    printf("Loowater is doomed!\n");
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    int n, m, d ,k;
    while (scanf("%d %d\n",&n,&m) != EOF) {
      if (n == 0 && m == 0) break;
      vector<int> dragons;
      while (n-- > 0) {
        scanf("%d\n",&d);
        dragons.push_back(d);
      }
      vector<int> knights;
      while (m-- >  0) {
        scanf("%d\n",&k);
        knights.push_back(k);
      }
      loowater(dragons,knights);
    }
    return 0;
}
