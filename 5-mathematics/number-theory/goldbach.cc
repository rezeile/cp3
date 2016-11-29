#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

bool isPrime(int N) {
    if(N <= 1 || N % 2 == 0) return false;
    if(N == 2) return true;
    int n = floor(sqrt(N)); 
    for(int i = 3; i <= n; i++) {
        if(i % 2 != 0 && N % i == 0) return false;
    }
    return true;
}

void goldbach(int N) {
    for(int i = 3; i <= (N/2); i++) {
        if(isPrime(i) && isPrime(N-i)) {
            printf("%d = %d + %d\n",N,i,N-i);
            break;
        }
    }
}

int main(int argc, char *argv[]) {
    /*if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);*/
    string input;
    int N;
    while(cin >> N) {
        if(!N) break;
        goldbach(N);
    }
    return 0;
}
