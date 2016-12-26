#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

/* print vector for debugging */
void printVector(vector<int> &vec) {
    for(int i = 0; i < vec.size(); i++) {
        if(i != vec.size() - 1) printf("%d ",vec[i]);
        else printf("%d\n",vec[i]);
    }
}

/* 
 * Day 1: 12/25/2017
 * ---------------------------------------------
 * This problem seems like a simple LDS problem.
 * The Warning to the problem suggests that the solution
 * to the problem might require the O(NlogN) solution 
 * instead of the O(N^2) solution.
 */

void printLDS(int test_no,vector<int> &vec) {
   int max = 1;
   vector<int> L(vec.size(),1);
   for(int i = 0; i < vec.size(); i++) {
       for(int j = 0; j < i; j++) {
           if(vec[i] <= vec[j] && L[i] < (L[j] + 1)) {
               L[i] = L[j] + 1;
               if(L[i] > max) max = L[i];
           }
       }
   }
   //printVector(L);
   printf("Test #%d:\n  maximum possible interceptions: %d\n",test_no,max);
}


int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    vector<int> vec;
    int n;
    cin >> n;
    int test_no = 1;
    while(true) {
        if(n == -1) break;
        vec.push_back(n);
        while(cin >> n) {
            if(n == -1) break;
            vec.push_back(n);
        }
        printLDS(test_no++,vec);
        cin >> n;
        if(n == -1) break;
        printf("\n");
        vec.clear();
    }
    return 0;
}
