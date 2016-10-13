/* 
 * Division of Nlogonia: UVa 11498
 *
 * Author: Eliezer Abate
 * Last Updated: September 13, 2016
 */

#include <utility>  // for pair<int,int>
#include <vector>   // for vector
#include <cstdio>   // for freopen
#include <iostream> // for cerr, cin, cout
using namespace std;

/* print vector */
void printCoordinates(vector<pair<int,int>> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << "(" << v[i].first << "," << v[i].second << ")\n";
    }
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file."; return -1; }
    //freopen(argv[1],"r",stdin);
    size_t K;
    int N,M,a,b;
    while(cin >> K) {
        if(K == 0) break;
        cin >> N >> M;
        for(size_t i = 0; i < K; i++) {
           cin >> a >> b;
           if(a == N || b == M) cout << "divisa\n";
           else if(a < N && b < M) cout << "SO\n";
           else if(a < N) cout << "NO\n";
           else if(b > M) cout << "NE\n";
           else cout << "SE\n";
        }
    }
    return 0;
}
