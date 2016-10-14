#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file;" return -1; }
    freopen(argv[1],"r",stdin);
    return 0;
}
