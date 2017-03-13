#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

void spiralTap(int x,int y) {
    /* Get ceiling of square root of y */
    int c = ceil(sqrt(y));
    /* Translate to appropriate ring */
    int r = c/2 + 1;
    /* Get dimension of ring */
    int d = 2*(r-1) + 1;
    /* Get 4 corners */
    int top_right = d * d;
    int bot_right = top_right - (d-1);
    int bot_left = bot_right- (d-1);
    int top_left = bot_left - (d-1);
    int col, line;
    /* Identify coordinates of y in d dimention */
    if(y >= (top_left - (d - 2)) && y <= top_left) {
        line = d;
        col = top_left - y + 1;
    } else if (y > top_left && y <= bot_left) {
        line = bot_left - y + 1;
        col = 1 ;
    } else if (y > bot_left && y <= bot_right) {
        line = 1;
        col = d - (bot_right - y);
    } else {
        line = d - (top_right - y);
        col = d;
    }
    /* Adjust coordinates to larger x dimension if necessary */
    int x_ring = x/2 + 1;
    int dx = x_ring - r;
    printf("Line = %d, column = %d.\n",line + dx,col + dx);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    int x,y;
    while(getline(cin,input)) {
        stringstream ss(input);
        ss >> x >> y;
        if(x == 0 && y == 0) break;
        spiralTap(x,y); 
    }
    return 0;
}
