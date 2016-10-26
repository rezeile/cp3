#include <iostream>
#include <cstdio>
#include <string>
#include <algorithm>
#include <sstream>
#include <vector>
#include <cmath>
#include <unordered_set>
using namespace std;

unordered_set<char> punc = {'?','(',')','!','.',',',' '};

void replaceExtraChars(string &s) {
    string ns = "";
    for(int i = 0; i < s.size(); i++) {
        if(punc.find(s[i]) == punc.end()) ns += s[i];
    }
    s = ns;
}

void printMagicSquare(vector<vector<char>> &mtx,int D) {
    for(int i = 0; i < D; i++)
        for(int j = 0; j < D; j++) {
            if(j != D-1) printf("%c ",mtx[i][j]);
            else printf("%c\n",mtx[i][j]); }
}

bool isMagicSquare(vector<vector<char>> &mtx,int D) {
    if(D < 0 || D > mtx.size()) return false;
    if(D <= 1) return true;
    int start = (mtx.size() - D) / 2;
    // check opposite corners 
    if(mtx[start][start] != mtx[start + (D-1)][start + (D-1)]) return false;
    if(mtx[start+(D-1)][start] != mtx[start][start+(D-1)]) return false;
    // recur
    return isMagicSquare(mtx,D-2);
}

void magicSquare(string &s) {
    replaceExtraChars(s);
    double sq_root = sqrt(s.size());
    if(fmod(s.size(),sq_root) != 0.0) { printf("No magic :(\n"); return;}
    int D = (int) sq_root;
    int s_length = 0;
    vector<vector<char>> mtx(D,vector<char>(D));
    for(int i = 0; i < D; i++)
        for(int j = 0; j < D; j++)
            mtx[i][j] = s[s_length++];
    //printMagicSquare(mtx,D);
    if(isMagicSquare(mtx,(int) sq_root)) printf("%d\n",(int) sq_root);
    else printf("No magic :(\n");
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string T;
    getline(cin,T);
    stringstream ss(T);
    int TC;
    ss >> TC; // 1 <= TC <= 60
    string s;  // length(s) < 10K
    for(int i = 0; i < TC; i++) {
        getline(cin,s);
        printf("Case #%d:\n",i+1);
        magicSquare(s);
    }
    return 0;
}
