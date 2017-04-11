#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <utility> // for pair
#include <vector>
#include <cmath>
#include <climits>
using namespace std;

void addPairs(int N,vector<pair<int,int>> &vec) {
    for(int i = 0; i < N; i++) {
            int a,b;
            scanf("%d %d\n",&a,&b);
            vec.push_back(make_pair(a,b));
    }
}

typedef vector<pair<int,int>> vii;

void mallMania(vii &m1,vii &m2) {
   int min = INT_MAX;  
   for(auto pi : m1) 
      for(auto pj : m2) {
         int a = abs(pj.first - pi.first);
         int b = abs(pj.second - pi.second);
         if(a + b < min) min = a + b;
      }
   printf("%d\n",min);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    vector<pair<int,int>> m1;
    vector<pair<int,int>> m2;
    int N;
    while(getline(cin,input)) {
        if(input.size() == 1 && stoi(input) == 0) break;
        stringstream s1(input);
        s1 >> N;
        addPairs(N,m1);
        getline(cin,input);
        stringstream s2(input);
        s2 >> N;
        addPairs(N,m2);
        // process m1, m2
        mallMania(m1,m2);
        m1.clear(); m2.clear();
    }
    return 0;
}
