#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
#include <map>
#include <queue>
#include <utility>
using namespace std;

#define INF 1000000000

typedef map<int,vector<pair<int,int>>> graph;

map<int,bool> visited;

int case_cnt = 1;

void printAList(graph &g) {
    for(auto nodes: g) {
        printf("%d: ",nodes.first);
        for(int j = 0; j < nodes.second.size(); j++) {
            printf("%d ",nodes.second[j].first);
        }
        printf("\n");
    }
}

void mapInsert(graph &g,int key,int value) {
    auto search = g.find(key);
    if(search == g.end()) {
        vector<pair<int,int>> v;
        v.push_back(make_pair(value,INF));
        g.insert(make_pair(key,v));
    } else {
        search->second.push_back(make_pair(value,INF));
    }
}

void insertNetwork(graph &g,int NC) {
    int n1,n2;
    for(int i = 0; i < NC; i++) {
        scanf("%d %d",&n1,&n2);
        mapInsert(g,n1,n2);
        mapInsert(g,n2,n1);
        visited.insert(make_pair(n1,false)); 
    }
}

void insertTTL(vector<pair<int,int>> &v ) {
    int N,TTL;
    while(scanf("%d %d",&N,&TTL) != EOF) {
        if(N == 0 && TTL == 0) break;
        auto p = make_pair(N,TTL);
        v.push_back(p);
    }
}


/*** SOLUTION FUNCTIONS  ***/
void bfs(int node,int TTL,graph &g,int &unreachable) {

}

void testTTLReachability(graph &g,vector<pair<int,int>> &v) {

}

/*** MAIN ***/
int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    int NC;
    while(getline(cin,input)) {
        if(input == "") continue;
        if((NC = stoi(input)) == 0) break;
        graph g;
        visited.clear();
        insertNetwork(g,NC);
        vector<pair<int,int>> v;
        insertTTL(v); 
        printAList(g);
        //testTTLReachability(g,v);
    }
    return 0;
}
