#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/* 
 * Consider the following example:
   
   0123
   ||||
 0-ABBA
 1-ABBB
 2-BAAA
 3-BABB

   Our task is to locate the subsquare:
   
   01
   ||
 0-AB
 1-BB

   Within the larger 4x4 grid our task is to locate
   the 2x2 grid. To do this we will consider starting at the top-left
   corner (x=0,y=0) and end horizontally at points (x=2,y=0). Vertically
   the ending points are at (x=0,y=2). We obtain the x value of the 
   horizontal ending point and the y value of the vertical ending 
   point via by subtracting M from N (i.e. N-M).

   Therefore our algorithm will proceed as follows:

   for (int i = 0; i <= (N-M); i++) 
      for(int j = 0; i <= (N-M); j++)
   At each position we need to check rotate0, rotate90, rotate 180,
   and rotate 270.

   For rotate0 we should:

      for (int k = 0; k < M; k++)
        for(int l = 0; l < M; l++)
            compare m1[k][l] vs m2[i+k][j+l] 

   We should probably have a seprate function that terminates as 
   soon as it detects that a subsquare is not possible from a particular
   starting point.
 
   For rotate90 we should:

      Compare the regular left to right smaller matrix by moving
      right to left on the larger matrix.

      for(int i = (N-M); i >= 0; i--) {
        for(int j = 0; j <= (N-M); j++) {
        
        }
      }
      

      Again we are goint to compare of this to the original 

      for(int k = 0; k < M; k++) {
        for(...)
      }
*/

using mtx = vector<vector<char>>;

enum degree { ZERO,NINETY,TWOSEVENTY,ONEEIGHTY}; 

bool testRotate(mtx &large,mtx &small,int i_start,int j_start,degree deg) {
    int M = small.size() - 1;
    // test degree zero
    if(deg == ZERO) {
        for(int i = 0; i <= M; i++) {
            for(int j = 0; j <= M; j++) {
                large[i_start + i][j_start + j];
                if (large[i_start + i][j_start + j] != small[i][j]) return false;
            }
        }
    } // test degree ninety
    else if (deg == NINETY) {
        for(int j = 0; j <= M; j++) {
            for(int i = 0; i <= M; i++) {
                if (large[i_start + i][j_start - j] != small[j][i]) return false;
            }
        }
    } // test degree oneeighty
    else if (deg == ONEEIGHTY) {
        for(int i = M; i >= 0; i--) {
            for(int j = M; j >= 0; j--) {
                if (large[i_start + i][j_start + j] != small[M - i][M - j]) return false;
            }
        }
    } // test degree twoseventy 
    else {
        for(int j = 0; j <= M; j++) {
            for(int i = 0; i <= M; i++) {
                if (large[i_start - i][j_start + j] != small[j][i]) return false;
            }
        }
    }
    return true;
}

int rotate(mtx &large, mtx &small,degree deg) {
    int end = large.size() - small.size();
    int count = 0;
    if (deg == ZERO) {
        for(int i = 0; i <= end; i++) {
            for(int j = 0; j <= end; j++) {
                if(testRotate(large,small,i,j,deg)) count++;
            }
        }
    } else if (deg == NINETY) {
        int start = large.size() - 1;
        for(int j = start; j >= (start-end); j--) {
            for(int i = 0; i <= end; i++) {
                if(testRotate(large,small,i,j,deg)) count++;
            }
        }
    } else if (deg == ONEEIGHTY) {
        for(int i = 0; i <= end; i++) {
            for(int j = 0; j <= end; j++) {
                if(testRotate(large,small,i,j,deg)) count++;
            }
        }
    } else {
        for(int j = 0; j <= end; j++) {
            int start = large.size() - 1;
            for(int i = start; i >= (start-end); i--) {
                if(testRotate(large,small,i,j,deg)) count++;
            }
        }
    }
    return count;
}


void printVector(vector<char> &v) {
    for(int i = 0; i < v.size(); i++) {
        cout << v[i];
    }
    cout << endl;
}

void printMatrix(mtx &m) {
    for(int i = 0; i < m.size(); i++)
        printVector(m[i]);
}

void populateMatrix(mtx &matrix,int N,string &input) {
    for(int i = 0; i < N; i++) {
        getline(cin,input);
        stringstream ss(input);
        vector<char> v(N);
        for(int j = 0; j < N; j++) {
            ss >> v[j];            
        }
        matrix.push_back(v);
    }
}

void rotateSquare(mtx &large,mtx &small) {
    cout << (rotate(large,small,ZERO)) << " ";
    cout << (rotate(large,small,NINETY)) << " ";
    cout << (rotate(large,small,ONEEIGHTY)) << " ";
    cout << (rotate(large,small,TWOSEVENTY)) << endl;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    while(getline(cin,input)) {
        stringstream ss(input);
        int N,M;
        ss >> N >> M;
        if(N == 0 && M == 0) break;
        mtx large;
        mtx small;
        populateMatrix(large,N,input);
        populateMatrix(small,M,input);
        rotateSquare(large,small);
    }
    return 0;
}
