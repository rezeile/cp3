#include <cmath>
#include <cstdio>
#include <string>
#include <algorithm>
#include <vector>
using namespace std;

double num = log(2000000000);

vector<int> humble_primes;

string getSuffix(int N) {
  N %= 100; 
  if (N/10 == 1) return "th";
  N %= 10; 
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

int exponent(int N) {
   double den = log(N);
   return (int) floor(num/den);
}

void humble(int N) {
  printf("The %d%s humble number is %d.\n",N,getSuffix(N).c_str(),humble_primes[N-1]);
}

using ll = long long;
int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    int N; 
    // generate all humble numbers
    int i = exponent(2);
    int j = exponent(3);
    int k = exponent(5);
    int l = exponent(7);
    for(int a = 0; a <= i; a++) {
      for(int b = 0; b <= j; b++) {
        for(int c = 0; c <= k; c++) {
          for(int d = 0; d <= l; d++) {
            int n = (int) (pow(2,a) * pow(3,b) * pow(5,c) * pow(7,d));
            if (n > 0) humble_primes.push_back(n);}
        }
      }
    }
    
    sort(humble_primes.begin(),humble_primes.end());
    while(scanf("%d\n",&N) != EOF) {
      if (N == 0) break;
      humble(N);
    }
    return 0;
}
