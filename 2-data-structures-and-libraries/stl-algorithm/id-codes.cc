#include <cstdio>
#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
using namespace std;

void idCodes(string &s) {
    string base = s;
    sort(base.begin(),base.end());
    next_permutation(s.begin(),s.end());
    if (s != base) printf("%s\n",s.c_str()); 
    else printf("No Successor\n");
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    string input; 
    while (getline(cin,input)) {
        if (input == "#") break;
        idCodes(input);
    }
    return 0;
}
