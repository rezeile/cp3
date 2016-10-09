#include <vector>
#include <cstdio>
#include <iostream> 
#include <utility> // for pair
#include <unordered_set>
using namespace std;

bool placeOkay(vector<pair<int,int>> &v,unordered_set<int> &candidates,int cur_dom,int candidate) {
    return candidates.count(cur_dom) && v.at(cur_dom).second == v.at(candidate).first;
}

void backtrack(vector<pair<int,int>> &v,int cur_dom,pair<int,int> &finish,unordered_set<int> &candidates) {
    pair<int,int> current = v.at(index);
    if(current.second == finish.first) {cout << "YES\n"; return;}
    for(int i = 1; i <= v.size(); i++) { // v[0] is start
        if(i == cur_dom) continue;
        if(placeOkay(v,candidates,cur_dom,i)) {
            candidates.insert(i);
            backtrack(v,i,finish,candidates);
            candidates.erase(i);
        }
    }
    cout << "NO\n";
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cout << "enter an input file"; return -1;}
    freopen(argv[1],"r",stdin);
    int spaces,m,first,second;
    while(true) {
        cin >> spaces;
        if(spaces == 0) break;
        cin >> m;
        pair<int,int> start;
        pair<int,int> finish;
        cin >> start.first; cin >> start.second;
        cin >> finish.first; cin >> finish.second;
        vector<pair<int,int>> v;
        v.push_back(start);
        for(int i = 0; i < m; i++) {
            cin >> first; cin >> second;
            v.push_back(make_pair(first,second));
        }
        unordered_set<pair<int,int>> candidates;
        backtrack(v,0,finish,candidates);
    }
    return 0;
}
