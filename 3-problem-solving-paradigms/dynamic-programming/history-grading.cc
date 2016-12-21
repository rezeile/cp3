#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

void printPartialCredit(vector<int> &answer,vector<int> &response) {
    for(int i = 0; i < response.size(); i++) {
        if(i == response.size() - 1) {
            printf("%d\n",response[i]);
        } else printf("%d ",response[i]);
    }
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    int N;
    getline(cin,input);
    N = stoi(input);
    while(getline(cin,input)) {
        vector<int> v(N);
        stringstream ss(input);
        for(int i = 0; i < N; i++) 
            ss >> v[i];
        while(getline(cin,input)) {
            if(input.size() <= 2) { N = stoi(input); break; }
            vector<int> v2(N);
            stringstream ss2(input);
            for(int i = 0; i < N; i++) {
                ss2 >> v2[i];
            }
            //printPartialCredit(v,v2);
        }
    }
    return 0;
}
