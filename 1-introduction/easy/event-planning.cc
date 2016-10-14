#include <iostream>
#include <cstdio>
#include <set>
using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    // obtain input 
    int N,B,H,W;
    while(cin >> N && !cin.eof()) {
        cin >> B >> H >> W;
        int price, avail;
        set<int> s; 
        for(int k = 0; k < H; k++) {
            s.clear();
            cin >> price;
            for(int i = 0; i < W; i++) {
                cin >> avail; s.insert(avail);
            }
        }
    }
    return 0;
}
