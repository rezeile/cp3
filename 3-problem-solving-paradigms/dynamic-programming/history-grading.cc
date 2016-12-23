#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

/*
 * Day 3 Comments: 12/23/2016
 * --------------------------
 * Will be deliberating from Big Bear.
 */

/*
 * Day 2 Comments: 12/22/2016
 * --------------------------
 * I am still trying to understand why 2 of the sample answers
 * are the way they are. This does not seem to be just a straighforward
 * Longest Increasing Subsequence problem.
 */

/*
 * Day 1 Comments: 12/21/2016
 * --------------------------
 * Understood the Problem.
 */

void printVector(vector<int> &vec) {
    for(int i = 0; i < vec.size(); i++) {
        if(i == vec.size() - 1) {
            printf("%d\n",vec[i]);
        } else printf("%d ",vec[i]);
    }
}

void printPartialCredit(vector<int> &answer,vector<int> &response) {
    vector<int> ordering(answer.size() + 1);
    vector<int> pc(response.size(),1);
    int index = 0;
    for(int i = 0; i < answer.size(); i++) {
        ordering[answer[i]] = index++; 
    }
    int max = 1;
    for(int i = 0; i < response.size(); i++) {
        for(int j = 0; j < i; j++) {
            if(ordering[response[i]] > ordering[response[j]]) {
                if(pc[i] < pc[j] + 1) {
                    pc[i] = pc[j] + 1;
                    if(pc[i] > max) max = pc[i];
                }
            }
        }
    }
    //printVector(pc);
    printf("%d\n",max);
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
            if(input.empty()) break;
            if(input.size() <= 2) { N = stoi(input); break; }
            vector<int> v2(N);
            stringstream ss2(input);
            for(int i = 0; i < N; i++) {
                ss2 >> v2[i];
            }
            printPartialCredit(v,v2);
        }
    }
    return 0;
}
