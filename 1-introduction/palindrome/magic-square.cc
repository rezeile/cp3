#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

void magicSquare(string s) {
    printf("No magic :(\n");
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int TC;
    cin >> TC; // 1 <= TC <= 60
    string s;  // length(s) < 10K
    for(int i = 0; i < TC; i++) {
        getline(cin,s);
        printf("Case #%d:\n",i+1);
        magicSquare(s);
    }
    return 0;
}
