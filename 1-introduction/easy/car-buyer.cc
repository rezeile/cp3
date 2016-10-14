#include <iostream>
#include <cstdio>
#include <vector>
using namespace std;

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    int duration,depreciation,month;
    double down_pmt,loan_amt,rate;
    while(cin >> duration) {
        if(duration < 0) break;
        cin >> down_pmt >> loan_amt >> depreciation;
        double car_value = loan_amt + down_pmt;
        double monthly_pmt = loan_amt / duration;
        vector<double> monthly_rate(duration + 1);
        // add monthly rates
        for(int i = 0; i < depreciation; i++) {
            cin >> month >> rate;
            std::fill(monthly_rate.begin() + month,monthly_rate.end(),rate);
        }
        // compute compute depreciation and time to sell
        double money_owed = loan_amt;
        for(int i = 0; i < duration + 1; i++) {
            if(i > 0) money_owed -= monthly_pmt;
            car_value -= (car_value * monthly_rate[i]);
            if(car_value > money_owed) {i == 1 ? printf("%d month\n",i) : printf("%d months\n",i);break;}
        }
    }
    return 0;
}
