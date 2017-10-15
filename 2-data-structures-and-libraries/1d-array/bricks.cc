#include <cstdio>
#include <iostream>
#include <algorithm>
#include <numeric>
using namespace std;

int setCounter = 0;

void solve(int *arr,int N) {
  sort(arr,arr+N);
  int avg = accumulate(arr,arr+N,0) / N;
  int count = 0;
  for(int i = 0; i < N; i++) {
    if (arr[i] >= avg) break;
    int add = avg - arr[i]; count += add;
  }
  printf("Set #%d\nThe minimum number of moves is %d.\n\n",++setCounter,count);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N; 
    while(scanf("%d\n",&N)) {
        if (N == 0) break;
        int size = N;
        int arr[size];
        while (N-- > 0) {
          scanf("%d",&arr[N]);
        }
        solve(arr,size);
    }
    return 0;
}
