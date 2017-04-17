#include <cstdio>
#include <iostream>
#include <string>
#include <cmath>
using namespace std;

void skewBinary(string &s) {
    int sum = 0;
    for(int i = 1; i <= s.size(); i++) {
        int n = s[s.size() - i] - '0';
        if (n > 0) sum += n * (pow(2,i) - 1);
    }
    printf("%d\n",sum);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    while(getline(cin,input)) {
        if (input != "0") {
            skewBinary(input); 
        }
    }
    return 0;
}
