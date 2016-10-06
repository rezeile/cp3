/* This program will output all possible placements 
 * of 8 queens on an 8x8 chessboard given a starting
 * placement for a single queen.The solution here
 * is based on the observation that each queen must
 * be on a single column and thus we generate 8! 
 * possible combinations of row placements. However, 
 * we will prune the search space so that placements
 * that violate the diagonal constraint are eliminated.
 * 
 * The insight for this solution is adopted from Felix 
 * and Steven Halim's Competitive Programming 3: The 
 * New Lowerbound of Programming Contests.
 *
 * Author: Eliezer Abate
 * Last Updated: September 28, 2016
 */

#include <cstring>
#include <cstdio>
#include <cstdlib>
using namespace std;

int solutionCount; // global variable

bool place(int r,int c,int row[8]) {
    for(int prev = 0; prev < c; prev++) {
        if(row[prev] == r || (abs(row[prev] - r) == abs(prev - c)))
            return false;
    }
    return true;
}

void backtrack(int c,int x,int y, int (&row)[8]) {
  if(c == 8 && row[y] == x) {
        printf("%2d   %d ",++solutionCount,row[0] + 1);
        for(int j = 1; j < 8; j++) {
            printf("%d ",row[j] + 1);
        }
        printf("\n");
   }
   for(int r = 0; r < 8; r++) {
       if(place(r,c,row)) {
            row[c] = r; backtrack(c+1,x,y,row);
       }
   }
}

void backtrack(int c,int x,int y) {
    int row[8];
    memset(row,0,sizeof row);
    backtrack(c,x,y,row);
}

int main() {
    int TC,x,y; // testcase
    scanf("%d ",&TC);
    while(TC--) {
        scanf("%d %d",&x,&y); x--; y--;
        backtrack(0,x,y);
        if(TC) printf("\n");
    }
    return 0;
}
