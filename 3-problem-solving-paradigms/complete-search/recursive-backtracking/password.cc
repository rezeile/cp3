#include <iostream>
#include <cstdio>
#include <set>          // for std::set
#include <map>          // for std::map
#include <vector>
#include <string>
using namespace std;
typedef set<char> sc;
typedef vector<vector<char>> mtx;
#define COL 5
#define ROW 6

string kthPassword(mtx &m1, map<int,sc> &m2) {
    return "";
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    // obtain input 
    int T,k;
    char c;
    cin >> T >> k;
    mtx m1(6,vector<char>(5));
    map<int,set<char>> m2 = {{1,sc()},{2,sc()},{3,sc()},{4,sc()},{5,sc()}};
    for(int i = 0; i < T; i++) {
        for(int j = 0; j < ROW; j++) {
            for(int k = 0; k < COL; k++) {
                cin >> m1[j][k];
            }
        }
        for(int j = 0; j < ROW; j++) {
            for(int k = 1; k <= COL; k++) {
                cin >> c; 
                m2[k].insert(c);
            }
        }
    }
    return 0;
}
