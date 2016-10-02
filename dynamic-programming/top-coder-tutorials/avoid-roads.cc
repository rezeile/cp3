#include <vector>           // for vector
#include <iostream>         // for cout
#include <unordered_map>    // for unordered_multimap
#include <utitlity>         // for pair
using namespace std;

typedef long long ll;
ll numWays(int width,int height,vector<string> &bad) {
    unordered_multimap<int> restricted;
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
    ll n = numWays(3,3);
    cout << n << endl;
    return 0;
}
