#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <utility> // for pair
using namespace std;

// custom comparator 
bool cmp(tuple<int,int,int> &t1,tuple<int,int,int> &t2) {
    return get<0>(t1) < get<0>(t2) && get<1>(t2) < get<1>(t2);
}

int babylon(set<tuple<int,int,int>> &s) {
    vector<tuple<int,int,int>> v(s.begin(),s.end());
    vector<pair<int,int>> L(v.size()); 
    int maxHeight = 0;
    for(int i  = 0; i < v.size(); i++) {
        L[i].second = get<2>(v[i]); // get height 
        for(int j = 0; j < i; j++) {
            tuple<int,int,int> ti = v[i];
            tuple<int,int,int> tj = v[j];
            if(cmp(ti,tj)) {
                L[i].first += 1;
                L[i].second += L[j].second;
                if(L[i].second > maxHeight) maxHeight = L[i].second;
            }
        }
    }
    return maxHeight;
}

void addToSet(int x,int y,int z,set<tuple<int,int,int>> &s) {
    tuple<int,int,int> t1(x,y,z); s.insert(t1);
    tuple<int,int,int> t2(z,x,y); s.insert(t2);
    tuple<int,int,int> t3(y,z,x); s.insert(t3);
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    int TC;
    int CN = 1;
    while(getline(cin,input)) {
        stringstream ss(input);
        ss >> TC;
        if(TC == 0) break;
        int max = 0;
        vector<int> v(3);
        set<tuple<int,int,int>> s;
        s.clear();
        for(int i = 0; i < TC; i++) {
            string input;
            getline(cin,input);
            stringstream ss(input);
            int x,y,z;
            ss >> x >> y >> z;
        }
        max = babylon(s);
        printf("Case %d: maximum height = %d\n",CN++,max);
    }
    return 0;
}
