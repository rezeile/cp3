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

int case_cnt = 1;

map<int,bool> visited;

void clearVisited() {
    for(auto p: visited)
        p.second = false;
}

void bfs(int node,int TTL,graph &g,int &reachable) {
   // regular bfs
   queue<pair<int,int>> q;
   q.push(make_pair(node,TTL));
   auto search = visited.find(node);
   search->second = true;
   while(!q.empty()) {
       auto front = q.front();
       int ttl = front.second;
       front.second = INF;
       q.pop();
       vector<pair<int,int>> neighbors = (g.find(front.first))->second;
       for(auto n : neighbors) {
           search = visited.find(n.first);
           if(!search->second) {
               search->second = true;
               n.second = ttl - 1;
               if(n.second < 0) reachable--;
               q.push(n);    
           }
       }
   }
}

void testTTLReachability(graph &g,vector<pair<int,int>> &v) {
    for(auto p : v) {
        int reachable = g.size();
        clearVisited();
        bfs(p.first,p.second,g,reachable);
        int unreachable = g.size() - reachable;
        printf("Case %d: %d nodes not reachable from node %d with TTL = %d.\n",case_cnt++,unreachable,p.first,p.second);
    }
}

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
        int n1,n2;
        for(int i = 0; i < NC; i++) {
            scanf("%d %d",&n1,&n2);
            mapInsert(g,n1,n2);
            mapInsert(g,n2,n1);
            visited.insert(make_pair(n1,false)); 
        }
        int N, TTL;
        vector<pair<int,int>> v;
        while(scanf("%d %d",&N,&TTL) != EOF) {
            if(N == 0 && TTL == 0) break;
            auto p = make_pair(N,TTL);
            v.push_back(p);
        }
        //printAList(g);
        testTTLReachability(g,v);
    }
    return 0;
}
