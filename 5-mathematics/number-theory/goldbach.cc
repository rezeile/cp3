#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

bool isPrime(int N) {
    if(N <= 1) return false;
    if(N == 2) return true;
    int n = floor(sqrt(N)); 
    for(int i = 3; i <= n; i++) {
        if(i % 2 != 0 && N % i == 0) return false;
    }
    return true;
}

void testPrime() {
    int N = 21;
    for(int i = 2; i < N; i++) {
    }
}


void goldbach(int N) {
    printf("%d = %d + %d\n",8,3,5);
}

int main(int argc, char *argv[]) {
    /*if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);*/
    string input;
    int N;
    testPrime();
    /*while(cin >> N) {
        if(!N) break;
        goldbach(N);
    }*/
    return 0;
}
