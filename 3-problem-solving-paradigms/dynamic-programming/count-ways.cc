/* 
 * Author: Eliezer Abate
 */
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;
using mtx = vector<vector<long>>;

void printResult(int N,long w) {
    if(w == 1) {
        printf("There is only %ld way to produce %d cents change.\n",w,N);
    } else {
        printf("There are %ld ways to produce %d cents change.\n",w,N);
    }
}

vector<int> denom = {1,5,10,25,50};

/*void printCache(mtx &cache) {
    for(int i = 0; i < 5; i++) {
        for(int j = 0; j < cache[i].size(); j++) {
            if (j != cache[i].size() - 1) printf("%ld ",cache[i][j]);
            else printf("%ld\n",cache[i][j]);
        }
    }
}*/

long countWays(int type,long N,vector<int> &cache) {
    //printf("type = %d, N = %ld\n",type,N);
    if (type > 4 || N < 0) return 0;
    if (N == 0) return 1;
    if (cache[N] > 0) return 1;
    long new_value = N-denom[type];
    cache[N] = countWays(type,new_value,cache) + countWays(type+1,N,cache);
    return cache[N];}


int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    int N;
    while(cin >> N) {
        mtx cache(5,vector<long>(N+1,-1));
        vector<int> memcache(N+1,-1);
        long ways = countWays(0,N,memcache);
        printResult(N,ways);
    }
    return 0;
}
