#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

typedef vector<vector<int>> vii;

void printVector(vector<int> &v) {
    printf("[");
    for(int i = 0; i < v.size(); i++) {
        if(i != v.size() - 1) printf("%d, ",v[i]);
        else printf("%d",v[i]);
    }
    printf("]\n");
}

void printBoard(vii &board) {
    for(int i = 0; i < 5; i++) {
        printVector(board[i]);    
    }
}

void populateBoard(vii &board,int index,string &input) {
    for(int i = 0; i < 5; i++) {
        if(input[i] != ' ') board[index][i] = input[i] - '0';
        else board[index][i] = -1;
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    getline(cin,input);
    int N = stoi(input);
    for(int i = 0 ; i < N; i++) {
        vii board(5,vector<int>(5));    
        for(int i = 0; i < 5; i++) {
            getline(cin,input);
            populateBoard(board,i,input);
        }
    }
    return 0;
}
