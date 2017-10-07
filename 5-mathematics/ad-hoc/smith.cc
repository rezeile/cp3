#include <cstdio>
#include <bitset>
#include <vector>
#include <iostream>
#include <cmath>
#include <string>
using namespace std;

using ll = long long;
using vi = vector<int>;

bitset<10000000> bs;
vi primes;

void printFactors(vi factors) {
  if (factors.empty()) return;
  printf("%d",factors[0]);
  for (int i = 1; i < factors.size(); i++)
    printf(" %d",factors[i]);
}

void sieve(ll max) {
  ll size = max + 1; // primes in range [0..max]
  bs.set();
  bs[0] = 0; bs[1];
  for(ll i = 2; i < size; i++) {
    if (bs[i]) {
      primes.push_back(i);
      for(ll j = i; j * i < size; j++) {
        bs[j*i] = 0;
      }
    }
  }
}

ll digitSum(ll N) {
  string s = to_string(N);
  ll sum = 0;
  for(auto c: s) {
    sum += c - '0';
  }
  return sum;
}

vi primeFactors(int N) {
  vi prime_factors;
  int max = ceil(sqrt(N));
  for(int i = 0; primes[i] <= max; i++) {
    while (N % primes[i] == 0) { 
      prime_factors.push_back(primes[i]);
      N /= primes[i];
    }
  }
  if (N != 1) prime_factors.push_back(N);
  return prime_factors;
}

bool isSmith(int N) {
  vi pf = primeFactors(N);
  if (pf.size() == 1) return false;
  ll nsum = digitSum(N);
  ll psum = 0;
  for(auto i: pf) psum += digitSum(i);
  return psum == nsum;
}

void smith(int N) {
  for(int i = N+1; i < 1e9 + 1000; i++) {
    if (isSmith(i)) { 
      printf("%d\n",i); return; 
    }
  }
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int TC,N; scanf("%d\n",&TC);
    sieve(1e7);
    while(TC-- > 0) {
      scanf("%d\n",&N);
      smith(N);
    }
    return 0;
}
