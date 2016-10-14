#include <iostream>
#include <cstdio>
#include <set>
#include <string>
using namespace std;

#define INF 1000000000

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    // obtain input 
    int N,B,H,W;
    while(cin >> N && !cin.eof()) {
        cin >> B >> H >> W;
        int price, avail;
        int min_price = INF; 
        for(int k = 0; k < H; k++) {
            cin >> price;
            for(int i = 0; i < W; i++) {
                cin >> avail; 
                if(avail >= N && min_price > price) {
                    min_price = price;
                }
            }
        }
        if(min_price == INF) cout << "stay home\n";
        else if(min_price * N <= B) cout << to_string(min_price *N) << endl;
        else cout << "stay home\n";
    }
    return 0;
}
