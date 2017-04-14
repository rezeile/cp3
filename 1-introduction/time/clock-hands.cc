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
    
    double hour_d = hour_i * 30 + ((double)min_i/60) * 30;
    int min_to_hour = min_i / 5;
    if (min_to_hour == 0) min_to_hour = 12;
    int min_rem = min_i % 5;
    double min_d = min_to_hour * 30 + (min_rem) * 6;
    double degrees = abs(hour_d - min_d);
    if (degrees > 180.0) degrees = 360.0 - degrees;
    printf("%.3f\n",degrees); 
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    string input; 
    while (getline(cin,input)) {
        if (input == "0:00") break;
        getDegrees(input);
    }
    return 0;
}
