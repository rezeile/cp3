#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
#include <utility>
#include <iostream>
#include <unordered_set>
#include <list>
using namespace std;

using graph = vector<vector<int>>;


void dfs (graph &pgraph,int i,bool *visited, list<int> &sorted_list) {
    vector<int> neighbors = pgraph[i];
    for(int j = 0; j < neighbors.size(); j++) {
        int n = neighbors[j];
        if (!visited[n]) dfs (pgraph,n,visited,sorted_list);
    }
    visited[i] = true;
    sorted_list.push_front(i);
}

void printResult(list<int> &sorted_list) {
    while (!sorted_list.empty()) {
        if (sorted_list.size() == 1) printf("%d\n",sorted_list.front() + 1);
        else printf("%d ",sorted_list.front() + 1);
        sorted_list.pop_front();
    }
}

void topoSort(graph &pgraph) {
    bool visited[pgraph.size()];
    for(int i = 0; i < pgraph.size(); i++)
        visited[i] = false;
    
    list<int> sorted_list;
    for (int i = 0; i < pgraph.size(); i++) {
        if (!visited[i]) dfs (pgraph,i,visited,sorted_list);
    }
    
    printResult(sorted_list);
}

int main (int argc, char *argv[]) {
    //if (argc < 2) { printf("enter an input file.\n"); return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    stringstream ss;
    while (getline(cin,input)) {
        ss.clear(); ss.str(input);
        int n,m;
        ss >> n >> m;
        if (m == 0 && n == 0) break;
        graph precedence(n);
        for (int i = 0; i < m; i++) {
            getline (cin,input);
            ss.clear(); ss.str(input);
            int index; ss >> index;
            int neighbor; ss >> neighbor;
            precedence[index-1].push_back(neighbor-1);
        }
        topoSort(precedence);
    }
    return 0;
}
