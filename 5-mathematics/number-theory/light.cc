#include <cstdio>
#include <string>
#include <cmath>
#include <iostream>
using namespace std;
using uint = unsigned int;

void light(uint N) {
    uint c = ceil(sqrt(N)); 
    bool ps = c*c == N;
    string s = ps ? "yes" : "no";
    printf("%s\n",s.c_str());
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    uint N;
    while(scanf("%u",&N) != EOF) {
        if(N != 0) {
            light(N);
        }
    }
    return 0;
}
