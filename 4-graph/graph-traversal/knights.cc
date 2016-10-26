#include <iostream>
#include <cstdio>
#include <vector>
#include <utility> // for std::pair
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mtx;
typedef vector<pair<int,int>> vii;

void findGridCells(int R,int C,int M,int N,vii &vp) {

}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int TC,R,C,M,N,W,a,b;
    cin >> TC;
    for(int i = 0; i < TC; i++) {
        cin >> R >> C >> M >> N;
        cin >> W;
        vii vp;
        for(int j = 0; j < W; j++) {
            cin >> a >> b;
            auto p = make_pair(a,b);
            vp.push_back(p);
        }
        findGridCells(R,C,M,N,vp);
    }
    return 0;
}
