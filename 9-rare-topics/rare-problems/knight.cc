#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <queue>
#include <vector>
#include <utility>
#include <cstring>
#define INF 2000000000

using namespace std;

int moves;
string target;
int visited[8][8];

bool validLocation(string l) {
    int i = l[0] - 'a', j = l[1] - '1';
    if ( (i >= 0 && i < 8) && (j >= 0 && j < 8)) return true;
    return false;
}

bool okayToAdd(string s1,int level) {
    bool first_time = (visited[s1[0] - 'a'][s1[1] - '1'] == -1);
    bool  shorter = visited[s1[0] - 'a'][s1[1] - '1'] > level;
    return validLocation(s1) && (first_time || shorter);
}
vector<pair<string,int>> getNeighbors(string s,int level) {
    vector<pair<string,int>> q;
    for(int i = 0; i <= 1; i++) {
        int a = 1 + i, b = 2 - i;
        char w = s[0] - a, x = s[1] - b;
        char y = s[0] + a, z = s[1] + b;
        
        string s1; s1+= w; s1+= x;
        if (okayToAdd(s1,level)) {
            q.push_back(make_pair(s1,level));
        }
        s1.clear(); s1 += w; s1 += z;
        if (okayToAdd(s1,level)) {
            q.push_back(make_pair(s1,level));
        }
        s1.clear(); s1 += y; s1 += x;
        if (okayToAdd(s1,level)) {
            q.push_back(make_pair(s1,level));
        }
        s1.clear(); s1 += y; s1 += z;
        if (okayToAdd(s1,level)) {
            q.push_back(make_pair(s1,level));
        }
    }
    return q;
}

void knightMoves(string s) {
    queue<pair<string,int>> q;
    q.push(make_pair(s,0));

    while (!q.empty()) {
        pair<string,int> p = q.front(); q.pop();
        visited[p.first[0]-'a'][p.first[1]-'1'] = p.second;
        if (p.first == target && p.second < moves) moves = p.second;
        vector<pair<string,int>> N = getNeighbors(p.first,p.second + 1);
        for(int i = 0; i < N.size(); i++) {
            q.push(N[i]);
        }
    }

}   

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    string input,a,b;
    while (getline(cin,input)) {
        stringstream ss(input);
        ss >> a >> b;
        moves = INF;
        target = b;
        memset(visited,-1,sizeof visited);
        if (validLocation(a)) knightMoves(a);
        printf("To get from %s to %s takes %d knight moves.\n",a.c_str(),b.c_str(),moves);
    }
    return 0;
}
