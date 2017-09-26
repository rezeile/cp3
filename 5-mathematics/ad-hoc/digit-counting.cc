#include <cstdio>
#include <string>
#include <cstring>
using namespace std;

int arr[10];

void solution(int num) {
  string s = "";
  for(int i = 1; i <= num; i++) {
    s += to_string(i);
  }

  memset(arr,0,sizeof arr);
  for(auto &c: s) 
    arr[c - '0']++;

  printf("%d",arr[0]);
  for(int i = 1; i < 10; i++)
    printf(" %d",arr[i]);
  printf("\n");
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    int TC; scanf("%d",&TC);
    for(int i = 0; i < TC; i++) {
      int num; scanf("%d",&num);
      solution(num);
    }
    return 0;
}
