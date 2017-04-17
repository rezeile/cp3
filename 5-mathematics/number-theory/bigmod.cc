#include <cstdio>
#include <iostream>
#include <vector>
#include <climits>
using namespace std;
using ll = unsigned long long;
using us = unsigned short;

ll bigMod(ll B,ll P,ll M) {
    if (P == 0) return 1 % M;
    if (P == 1) return B % M;
    ll a = bigMod(B,P/2,M);
    ll b = (P % 2 == 0) ? a : bigMod(B,(P/2)+1,M); 
    return (a*b) % M;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
   
    int B,P,M;
    while(scanf("%d %d %d",&B,&P,&M) != EOF) {
        cout << bigMod(B,P,M) << endl;;
    }
    return 0;
}
