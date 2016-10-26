#include <iostream>
#include <cstdio>
#include <vector>
#include <utility> // for std::pair
#include <cmath>
#include <set>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> mtx;
typedef vector<pair<int,int>> vii;
typedef set<pair<int,int>> sii;

#define UNVISITED -1
#define EVEN 0
#define ODD 1 
#define DFS_YES 1
#define DFS_NO -1
#define not_water_cell(x,y) wc.find(make_pair(x,y)) == wc.end()
vii validNextJumps(int cx,int cy,int R,int C,int M,int N,sii &wc) {
    // Right Up
    vii next_jumps;
    if(((cx+N) < C && (cy-M) >= 0) && not_water_cell(cx+N,cy-M)) 
        next_jumps.push_back(make_pair(cx+N,cy-M));
    // Right Down
    if(((cx+N) < C && (cy+M) < R) && not_water_cell(cx+N,cy+M))
        next_jumps.push_back(make_pair(cx+N,cy+M)); 
    // Left Up
    if(((cx-N) >= 0 && (cy-M) >= 0) && not_water_cell(cx-N,cy-M))
        next_jumps.push_back(make_pair(cx-N,cy-M));
    // Left Down
    if(((cx-N) >= 0 && (cy+M) < R) && not_water_cell(cx-N,cy+M))
        next_jumps.push_back(make_pair(cx-N,cy+M));
    return next_jumps;
}

void dfsHelper(int i,int j,int M,int N,mtx &dfs_start,mtx &tracker,sii &wc) {
    dfs_start[i][j] = DFS_YES;
    for(auto vj: validNextJumps(i,j,dfs_start.size(),dfs_start[0].size(),M,N,wc)) {
        // if UNVISITED mark as odd 
        int x = vj.first;
        int y = vj.second;
        if(tracker[x][y] == UNVISITED)
            tracker[x][y] = ODD;
        else if(tracker[x][y] == ODD)
            tracker[x][y] = EVEN;
        else 
            tracker[x][y] = ODD;
        if(dfs_start[x][y] != DFS_YES) {
            dfsHelper(x,y,M,N,dfs_start,tracker,wc);
        }
   }
}

void printResults(mtx &tracker) {
    int even = 0, odd = 0;
    for(int i = 0; i < tracker.size(); i++) {
        for(int j = 0; j < tracker[0].size(); j++) {
            if(tracker[i][j] == EVEN) even++;
            if(tracker[i][j] == ODD) odd++;
        }
    }
    printf("%d %d\n",even,odd);
}

void findGridCells(int R,int C,int M,int N,sii &wc) { // wc -> water cells
   vii next_jumps = validNextJumps(0,0,R,C,M,N,wc);
   mtx dfs_start(R,vi(C,DFS_NO));
   mtx tracker(R,vi(C,UNVISITED));
   for(int i = 0; i < R; i++) {
       for(int j = 0; j < C; j++) {
            if(dfs_start[i][j] == DFS_NO && not_water_cell(i,j)) {
                dfsHelper(i,j,M,N,dfs_start,tracker,wc);
            }
       }
   }
   printResults(tracker);
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int TC,R,C,M,N,W,a,b;
    cin >> TC;
    for(int i = 0; i < TC; i++) {
        cin >> R >> C >> M >> N;
        cin >> W;
        sii sp;
        for(int j = 0; j < W; j++) {
            cin >> a >> b;
            auto p = make_pair(a,b);
            sp.insert(p);
        }
        printf("Case %d: ",i+1);
        findGridCells(R,C,M,N,sp);
    }
    return 0;
}
