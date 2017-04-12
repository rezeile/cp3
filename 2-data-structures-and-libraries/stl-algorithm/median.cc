/* for each input print current value of median */

#include <cstdio>
#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
    //if (argc < 2) { printf("enter an input file.\n"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N;
    vector<int> v;
    while (cin >> N) {
        v.push_back(N);
        sort(v.begin(),v.end()); 
        int i = (v.size()-1) / 2;
        if (v.size() % 2 == 0) cout << (v[i] + v[i+1]) / 2 << endl;
        else cout << v[i] << endl;
    }
    return 0;
}
