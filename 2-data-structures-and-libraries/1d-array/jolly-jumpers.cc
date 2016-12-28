#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <cstdlib>
#include <algorithm>
#include <bitset>
using namespace std;

void validateJollyness(vector<int> &vec) {
    vector<bool> v(vec.size());
    for(int i = 1; i < vec.size(); i++) {
        v[abs(vec[i] - vec[i-1])] = true;        
    }
    
    v[0] = true;
    for(int i = 0; i < v.size(); i++) {
        if(v[i] != true) {
            printf("i = %d\n",i);
            printf("Not jolly\n");
            return;
        }
    }
    printf("Jolly\n");
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    while(getline(cin,input)) {
        stringstream ss(input);
        int N;
        vector<int> vec;
        while(ss >> N) {
            vec.push_back(N);
        }
        validateJollyness(vec);
    }
    return 0;
}
