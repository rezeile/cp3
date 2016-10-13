#include <iostream>      // for cerr, cout, cin
#include <cstdio>        // for freopen
#include <set> // for unordered_set
#include <algorithm>
using namespace std;

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file."; return -1;};
    //freopen(argv[1],"r",stdin); 
    int TC;
    cin >> TC;
    int a1,a2,a3;
    set<int> s;
    for(int i = 1; i <= TC; i++) {
        cin >> a1 >> a2 >> a3;
        s.insert(a1); s.insert(a2); s.insert(a3);
        int min = *(min_element(s.begin(),s.end()));
        auto it = s.upper_bound(min);
        if(it == s.end()) it = s.lower_bound(min);
        cout << "Case " << i << ": " << *it << endl;
        s.clear();
    }
    return 0;
}
