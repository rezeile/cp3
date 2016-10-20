#include <iostream>
#include <cstdio>
#include <deque>        // for std::deque
#include <string>
#include <vector>
#include <utility>      // for std::pair
using namespace std;

typedef vector<vector<bool>> vbb;
deque<char> d = {'N','E','S','W'}; // global

char nextRotation(deque<char> &d,char dir) {
    if(dir == 'L') {
        char back = d.back(); d.pop_back();
        d.push_front(back);
    } else {
        char front = d.front(); d.pop_front();
        d.push_back(front);
    }
    return d.front();
}

// -1,-1 indicates invalid 
pair<int,int> nextCoordinates(int x,int y,int N,int M) {
    char dir = d.front();
    pair<int,int> p; p.first = p.second = -1;
    if(dir == 'N') {
        // increase y by 1
        if(x <= N && (y+1) <= M) { p.first = x; p.second = ++y; return p; }
    } else if (dir == 'S') {
        // decreate y by 1
        if(x <= N && (y-1) >= 0) { p.first = x; p.second = --y; return p; }
    } else if (dir == 'E') {
        // increase x by 1
        if((x+1) <= N && y <= M) { p.first = ++x; p.second = y; return p; }
    } else {
        // decrease x by 1
        if((x-1) >= 0 && y <= M) { p.first = --x; p.second = y; return p; }
    }
    return p;
}

void endingPosition(string s,char dir,int sa,int sb,int N,int M,vbb &grid) {
   int cur_a = sa, cur_b = sb;
   pair<int,int> coor; coor.first = -1; coor.second = -1; 
   for(int i = 0; i < s.size(); i++) {
       if(s[i] == 'L' || s[i] == 'R') {
            dir = nextRotation(d,s[i]);
       } else {
            coor = nextCoordinates(cur_a,cur_b,N,M);         
            if(coor.first == -1 && grid[cur_a][cur_b]) continue; // scent smelled
            else if(coor.first == -1) { 
                grid[cur_a][cur_b] = true;
                printf("%d %d %c LOST\n",cur_a,cur_b,d.front()); return;
            } else { // valid coordinates
                cur_a = coor.first;
                cur_b = coor.second;
            }
        }
    }
    printf("%d %d %c\n",cur_a,cur_b,d.front());
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    int start_a,start_b,N,M; 
    char dir;
    string s;
    while(scanf("%d %d",&N,&M) != EOF) {
        vector<vector<bool>> grid(N+1,vector<bool>(M+1));
        while(scanf("%d %d %c",&start_a,&start_b,&dir) != EOF) {
            cin >> s;
            while(nextRotation(d,'L') != dir) {}
            endingPosition(s,dir,start_a,start_b,N,M,grid);
        }
    }
    return 0;
}
