#include <cstdio>
#include <cmath>
#include <bitset>
#include <vector>
#include <iostream>
#include <utility>
using namespace std;

using ll = long long;
using vii = vector<pair<ll,ll>>;

bitset<10000000> bs;
ll _sieve_size = (ll) ceil(sqrt(1e9) + 1000) + 1;
vector<ll> primes;

void printPrimes(int N) {
  for(int i = 0; i < N; i++) {
    cout << primes[i] << endl;
  }
}

void sieve() {
  bs.set();
  bs[0] = 0; bs[1] = 0;
  for(int i = 2; i < _sieve_size; i++) {
    if (bs[i]) {
      for (int j = i; i*j < _sieve_size; j++) {
        bs[i*j] = 0;
      }
      primes.push_back(i);
    }
  }
}


ll numOfFactors(int N) {
  ll index = 0;
  ll PF = primes[index];
  vii factors;
  ll total = 1;
  while (PF * PF <= N) {
    ll count = 0;
    while (N % PF == 0) {
      ++count;
      N /= PF;
    }
    PF = primes[++index];
    total *= (count + 1);
  }
  if (N != 1) total *= 2;
  return total;
}

void solve(ll a, ll b) {
  ll max = -1;
  ll index = -1;
  for(ll i = a; i <= b; i++) {
    ll nof = numOfFactors(i);
    if (nof > max){
      max = nof;
      index = i;
    }
  }
  printf("Between %lld and %lld, %lld has a maximum of %lld divisors.\n",a,b,index,max);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N; scanf("%d\n",&N);
    sieve();
    for(int i = 0; i < N; i++) {
      ll a, b;
      scanf("%lld %lld\n",&a,&b);
      solve(a,b);
    }
    return 0;
}
