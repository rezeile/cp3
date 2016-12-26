#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <string>
using namespace std;

/*
 * Day 6 Comments: 12/26/2017
 * --------------------------
 * I had to look into the solution insight at the following
 * url: https://saicheems.wordpress.com/2013/11/08/uva-111-history-grading/
 * 
 * It seems to me that the order given my both the student responses, 
 * and the respective orderings for each test case represent the 
 * orderings of events [1...N]. Admittedly, it really does not feel
 * good to have had to search for a solution, but I felt that I wasn't 
 * really gaining any new insights in my search for a solution. I still
 * believe this insight will help me discover a solution that will help 
 * me tackle the trainsorting problem.
 *
 * This is a longest common subsequence problem.
 */

/*
 * Day 5 Comments: 12/25/2017
 * --------------------------
 * It's important that I find out how to tackle 
 * a problem better.
 *
 * I need to find out whether the following input will
 * generate an output of 9. 
 *
 * 3 1  2 4 9 5 10 6 8 7
 * 2 10 1 3 8 4 9  5 7 6
 */

/*
 * Day 4 Comments: 12/24/2016
 * --------------------------
 * Haven't been able to find a solution.
 */

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

int LIS(vector<int> &m1,vector<int> &m2) {
    return 5;
}
void printPartialCredit(vector<int> &answer,vector<int> &response) {
    // mapping between answer ordering and digits 1 - N
    vector<int> ordering(answer.size() + 1);
    vector<int> map1(answer.size() + 1);
    for(int i = 0; i < answer.size(); i++) 
        ordering[answer[i]] = i + 1;
    for(int i = 1; i < map1.size(); i++)
        map1[i] = ordering[i];
    
    // student ranking mapping
    vector<int> sranking(response.size() + 1);
    vector<int> map2(response.size() + 1);
    for(int i = 0; i < response.size(); i++)
        sranking[response[i]] = i + 1;
    for(int i = 1; i < map2.size(); i++)
        map2[i] = sranking[i];
    
    // print LIS
    printf("%d\n",LIS(map1,map2));
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
