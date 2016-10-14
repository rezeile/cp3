#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file;" return -1; }
    freopen(argv[1],"r",stdin);
    
    int duration, dep_record;
    double down_payment, loan_amount;
    cin >> duration >> down_payment >> loan_amount >> dep_record;
    for(int i = 0; i < dep_record; i++) {
               
    }
    return 0;
}
