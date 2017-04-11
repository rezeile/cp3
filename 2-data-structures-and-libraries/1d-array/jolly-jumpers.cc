/* 
 * Author: Eliezer Abate
 */
#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <cmath>
using namespace std;

void JollyJumpers(vector<int> &vec) {
    int N = vec.size() - 1;
    vector<bool> set(N,false);
    for(int i = 1; i <= N; i++) {
        int diff = abs(vec[i] - vec[i-1]);
        set[diff] = true;
    }
    for(int i = 1; i < N; i++)
        if(!set[i]) { printf("Not jolly\n"); return; }
    printf("Jolly\n");
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    while(getline(cin,input)) {
        stringstream ss(input);
        int N;
        vector<int> vec;
        while(ss >> N) {
            vec.push_back(N);
        }
        JollyJumpers(vec);
    }
    return 0;
}
