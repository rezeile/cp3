#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

typedef vector<vector<long long>> table;

void helper(int index,int D,int M,vector<int> &v,int elems,long long &count,int sum) {
   if(index > v.size() || elems > M) return;
   if(elems == M) {count += sum % D ? 0 : 1; return;}
   // take it
   helper(index+1,D,M,v,elems+1,count,sum + v[index]);
   // leave it
   helper(index+1,D,M,v,elems,count,sum);
}

long long DGS(vector<int> &v,int D,int M) {
    long long count = 0;
    int sum = 0;
    int elems = 0;
    helper(0,D,M,v,elems,count,sum);
    return count;
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int N,Q,M;
    long long D;
    int cnt = 1;
    while(cin >> N) {
        if(N == 0) break;
        cin >> Q;
        vector<int> iv; iv.resize(N);
        for(int i = 0; i < N; i++) cin >> iv[i];
        printf("SET %d:\n",cnt++);
        for(int j = 1; j <= Q; j++) {
           cin >> D >> M;
           printf("QUERY %d: %lld\n",j,DGS(iv,D,M));
        }
    }
    return 0;
}
