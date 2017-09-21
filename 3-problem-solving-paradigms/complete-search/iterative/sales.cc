#include <cstdio>
using namespace std;

void sales(int n, int *arr) {
  int total = 0;
  for(int i = 1; i < n; i++) {
    for(int j = 0; j < i; j++) {
        if (arr[j] <= arr[i]) total++;
    }
  }
  printf("%d\n",total);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int T,n; scanf("%d",&T);
    for (int i = 0; i < T; i++) {
      scanf("%d",&n);
      int arr[n];
      for(int i = 0; i < n; i++) {
        scanf("%d",&arr[i]);
      }
      sales(n,arr);
    }
    return 0;
}
