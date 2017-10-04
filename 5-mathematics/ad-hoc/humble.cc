#include <cstdio>
#include <string>
using namespace std;

int primes[1000];

string getSuffix(int N) {
  switch (N) {
    case 1:
      return "st";
    case 2:
      return "nd";
    case 3:
      return "rd";
    default:
      return "th";
  }
}

bool isHumble(int N) {

}

void humble(int N) {
  int count = 0;
  printf("%d\n",N);
}

int main(int argc, char *argv[]) {
    if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    freopen(argv[1],"r",stdin);
    
    int N; 
    int count = 0;
    while(true) {

    }
    
    while(scanf("%d\n",&N) != EOF) {
      if (N == 0) break;
      humble(N);
    }
    return 0;
}
