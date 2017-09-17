#include <cstdio>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N,d;
  
    while (scanf("%d\n",&N) != EOF) {
      if (N == 0) break;
      vector<int> vec;
      while (N-- > 0) {
        scanf("%d\n",&d);
        if (d > 0) vec.push_back(d);
      }
      for(int i = 0; i < vec.size(); i++) {
        if (i != vec.size() - 1) printf("%d ",vec[i]);
        else printf("%d\n",vec[i]);
      }
      if (vec.empty()) printf("%d\n",0);
    }
    return 0;
}
