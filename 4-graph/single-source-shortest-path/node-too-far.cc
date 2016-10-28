#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

typedef vector<vector<int>> graph;

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    int NC;
    while(getline(cin,input)) {
        if(input == "") continue;
        if((NC = stoi(input)) == 0) break;
        graph g;
        g.clear();
        int n1,n2;
        g.assign(NC+1,vector<int>());
        for(int i = 0; i < NC; i++) {
            scanf("%d %d",&n1,&n2);
            if(n1 == 0 && n2 == 0) 
            g[n1].push_back(n2); 
        }
        int N, TTL;
        vector<pair<int,int>> v;
        while(scanf("%d %d",&N,&TTL) != EOF) {
            if(N == 0 && TTL == 0) break;
            auto p = make_pair(N,TTL);
            v.push_back(p);
        }
    }
    return 0;
}
