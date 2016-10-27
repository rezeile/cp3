#include <iostream>
#include <cstdio>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<vector<int>> graph;

void findUnreachable(graph &g, vector<int> &sv) {
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int N,vertex;
    string input;
    stringstream ss;
    while(getline(cin,input)) {
        if((N = stoi(input)) == 0) break;        
        graph g(N+1);
        string adj_list;
        while(getline(cin,adj_list)) {
            if(stoi(adj_list) == 0) break;
            stringstream ss;
            ss << adj_list;
            ss >> vertex;
            int neighbor;
            while(ss >> neighbor) {
                if(neighbor == 0) break;
                g[vertex].push_back(neighbor);
            }
        }
        vector<int> sv; // start vertices
        string start;
        getline(cin,start);
        ss << start;
        ss >> N;
        for(int i = 0; i < N; i++) {
            int val;
            ss >> val;
            sv.push_back(val);
        }
       findUnreachable(g,sv);
    }
    return 0;
}
