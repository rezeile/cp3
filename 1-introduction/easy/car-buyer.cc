#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int duration,depreciation,month;
    double down_pmt,loan_amt,rate;
    while(cin >> duration) {
        if(duration < 0) break;
        cin >> down_pmt >> loan_amt >> depreciation;
        for(int i = 0; i < depreciation; i++) {
            cin >> month >> rate;
        }
    }
    return 0;
}
