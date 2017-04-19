#include <cstdio>
#include <vector>
#include <cmath>
#include <algorithm>
#include <utility>
#include <iostream>
using namespace std;
#define INF 2000000000 

vector<int> books;
int a,b;
int max_diff = INF;

void exactSum2(vector<int> v,int M) {
    a = b = 0;
    max_diff = INF;
    sort(v.begin(),v.end());
    vector<int>::iterator low,it2;
    low = lower_bound(v.begin(),v.end(),M);
    for(auto it = v.begin(); it != low; it++) {
        int p1 = *it;
        if ((it2 = find(it+1,low,M-p1)) != low) {
            int p2 = *it2;
            int diff = abs(p1-(double)p2);
            if( diff < max_diff) {
                max_diff  = diff;
                a = p1;
                b = p2;
            }
        }
    }
    int tmp = a;
    if(a > b) { a = b; b = tmp; }
    printf("Peter should buy books whose prices are %d and %d.\n",a,b);
}

void exactSum1(vector<int> &v,int M) {
    int md = INF;
    int a,b;
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            int diff = abs(v[i]-(double)v[j]);
            if ( v[i] + v[j] == M && diff < md) {
                a = v[i];
                b = v[j];
            }
        }
    }
    int tmp = a;
    if(a > b) { a = b; b = tmp; }
    printf("Peter should buy books whose prices are %d and %d.\n",a,b);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N;
    while (scanf("%d",&N) != EOF) {
        vector<int> v(N);
        for(int i = 0; i < N; i++) {
           int n;
           scanf("%d",&n); v[i] = n;
        }
        int M;
        scanf("%d",&M);
        exactSum2(v,M);
        printf("\n");
    }
    return 0;
}
