#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

int lineCounter = 0;

void brick(vector<int> &v) {
  int mid = v[0] / 2 + 1;
  printf("Case %d: %d\n",++lineCounter,v[mid]);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int TC; scanf("%d\n",&TC);
    string input;
    while(TC-- > 0) {
        getline(cin,input);
        stringstream ss(input);
        vector<int> v; int n;
        while (ss >> n) { v.push_back(n); }
        brick(v);
    }
    return 0;
}
