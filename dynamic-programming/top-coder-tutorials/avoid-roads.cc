#include <vector>           // for vector
#include <iostream>         // for cout
#include <set>              // set
#include <string>
using namespace std;

typedef long long ll;

ll numWays(int width,int height,vector<string> &bad) {
    set<string> s(bad.begin(),bad.end());
    ll grid[height + 1][width + 1];
    for(int i = 0; i <= height; i++) {
        for(int j = 0; j <= width; j++) {
            if(i == 0 || j == 0) {
                grid[i][j] = 1;
            } else {
                grid[i][j] = grid[i-1][j] + grid[i][j-1];    
            }
        }
    }
    return grid[height][width];
}

int main() {
    vector<string> v = {"0 0 0 1","6 6 5 6"};
    ll n = numWays(6,6,v); 
    cout << n << endl;
    return 0;
}
