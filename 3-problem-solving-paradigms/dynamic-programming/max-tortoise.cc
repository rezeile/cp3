#include <cstdio>
#include <cstring>
#include <climits>
#include <algorithm>
using namespace std;

int arr[150][150];

void print(int N, int arr[150][150]) {
  for(int i = 0; i < 2*N; i++) {
    printf("%d",arr[i][0]);
    for(int j = 1; j < 2*N; j++) {
      printf(" %d",arr[i][j]);
    }
    printf("\n");
  }
}

int solutionHelper(int i,int j,int arr[150][150],int N) {
  int sum[N][N]; memset(sum,0,sizeof (sum));
  int A,L,O;
  int maximum = -INT_MAX;
  for (int a = i; a < i + N; a++) {
    for(int b = j; b < j + N; b++) {
      A = L = O = 0;
      if (a-1 >= i) {
        A = sum[(a-1) - i][b - j];
      }
      if (b-1 >= j) {
        L = sum[a - i][(b-1) - j];
      }
      if (a-1 >= i && b-1 >= j) {
        O = sum[(a-1) - i][(b-1) -j];
      }
      int new_value = ((A+L) - O) + arr[a][b];
      sum[a-i][b-j] = new_value;
      if (new_value > maximum) maximum = new_value;
    }
  }
  return maximum;
}

void solution(int N, int arr[150][150]) {
  int max_sum = -INT_MAX;
  for(int i = 0; i <= N; i++) {
    for(int j = 0; j <= N; j++) {
        max_sum = max(max_sum,solutionHelper(i,j,arr,N)); 
    }
  }
  printf("%d\n",max_sum);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int T,N; scanf("%d",&T);
    for(int i = 0; i < T; i++) {
      scanf("%d",&N);
      for (int j = 0; j < N; j++) {
        for (int k = 0; k < N; k++) {
          scanf("%d",&arr[j][k]);
          arr[j+N][k] = arr[j][k];
          arr[j][k+N] = arr[j][k];
          arr[j+N][k+N] = arr[j][k];
        }
      }
      solution(N,arr);
    }
    return 0;
}
