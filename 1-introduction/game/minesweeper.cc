#include <cstdio>
#include <vector>
#include <iostream>
#include <sstream>
using namespace std;

void addAdjacentMines(int i, int j, vector<vector<char>> &mine) {
    int top_y = i - 1 >= 0 ? i - 1: i;
    int bot_y = i + 1 < mine.size() ? i + 1 : i;
    int left_x = j - 1 >= 0 ? j - 1 : j;
    int right_x = j + 1 < mine[0].size() ?  j + 1 : j;
    mine[i][j] = '0';
    
    // check top 
    for (int x = left_x; x <= right_x; x++) 
        if (top_y != i && mine[top_y][x] == '*') mine[i][j]++; 

    // check bottom 
    for (int x = left_x; x <= right_x; x++) 
        if (bot_y != i && mine[bot_y][x] == '*') mine[i][j]++; 
    
    // check left and right 
    if (left_x != j && mine[i][left_x] == '*') mine[i][j]++;
    if (right_x != j && mine[i][right_x] == '*') mine[i][j]++;
}

void print(int field,vector<vector<char>> &mine) {
    printf("Field #%d:\n",field);
    int n = mine.size();
    int m = mine[0].size();
    for(int i = 0; i < n; i++) {
        for (int j = 0; j < m; j++) {
            if ( mine[i][j] == '.' ) {
                addAdjacentMines(i,j,mine);
            }
            if ( j != m-1) printf("%c",mine[i][j]);
            else printf("%c\n",mine[i][j]);
        }
    }
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    int n,m;
    int field = 0;
    scanf("%d %d\n",&n,&m);
    while (n != 0 && m != 0) {
        vector<vector<char>> mine(n,vector<char>(m));
        for (int i = 0; i < n; i++) {
            for(int j = 0; j < m; j++) {
                char c; (j == m-1) ? scanf("%c\n",&c) : scanf("%c",&c);
                mine[i][j] = c;
            }
        }
        scanf("%d %d\n",&n,&m);
        print(++field,mine);
        if (n != 0 && m != 0) printf("\n");
    }
    return 0;
}
