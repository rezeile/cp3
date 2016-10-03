#include <vector>
#include <cstdio>
#include <iostream>
#include <cmath>
using namespace std;

typedef vector<vector<int>> Matrix;

int maxSubArraySum(Matrix &m) {
    // the input matrix includes the cumulative sum for each i,j
    // meaning the sum of the matrix from (0,0) to (i,j)
    int maxSum = -127*100*100; // lowest possible value
    int N = m.size();
    for(int i = 0; i < N; i++)
        for(int j = 0; j < N; j++) 
            for(int k = i; k < N; k++) 
                for(int l = j; l < N; l++) {
                    int sum = m[k][l];
                    if(i > 0) sum -= m[i-1][l];
                    if(j > 0) sum -= m[k][j-1];
                    if(i > 0 && j > 0) sum += m[i-1][j-1];
                    maxSum = max(sum,maxSum);
                }
    return maxSum;
}

int main(int argc, char *argv[]) {
    /*if(argc < 2) {
        cerr << "enter an input file." << endl;
        return -1;
    }
    freopen(argv[1],"r",stdin);*/
    int N;
    while(cin >> N) {
        Matrix m(N,vector<int>(N));
        for(int i = 0; i < N; i++) 
            for(int j = 0; j < N; j++) {
                // lets take care of the cumulative sum here
                cin >> m[i][j];
                // fill from top
                if(i > 0) m[i][j] += m[i-1][j];
                if(j > 0) m[i][j] += m[i][j-1];
                if(i > 0 && j > 0) m[i][j] -= m[i-1][j-1]; // avoid double count
            }
        cout << maxSubArraySum(m) << endl;
    }
    return 0;
}
