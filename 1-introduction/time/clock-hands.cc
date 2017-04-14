#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <sstream>
#include <utility>
#include <cmath>
using namespace std;

void getDegrees(string &input) {
    stringstream ss(input);
    string hour,min;
    getline(ss,hour,':');int hour_i = stoi(hour);
    getline(ss,min,':'); int min_i = stoi(min);
}

int main(int argc, char *argv[]) {
    if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    freopen(argv[1],"r",stdin);
    string input; 
    while (getline(cin,input)) {
        if (input == "0:00") break;
        getDegrees(input);
    }
    return 0;
}
