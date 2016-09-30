#include <vector> // for vector<bool>
#include <iostream>
#include <cstdio>
using namespace std;

typedef unsigned int uint;

class MCFinancials {
    public:
        MCFinancials(): months(12), surplus(0), deficit(0), max_surplus_months(0),
                        max_fivemo_sp(0){}
        vector<bool> months;
        uint surplus;
        uint deficit;
        uint max_surplus_months;
        uint max_fivemo_sp;
};

// forward declaration 
void printResult(MCFinancials &mc); 
void printArray(vector<bool> &v);

bool isSurplusMonth(int index,MCFinancials &mc,uint &surplus_months) {
    uint max_fivemo_sp = 0;
    uint start = (index - 4) < 0 ? 0 : (index - 4);
    uint end = (index + 5) > mc.months.size() ? mc.months.size() : index + 5;
    for(int i = start; i < end; i++) {
        if(mc.months[i]) {
            if(++max_fivemo_sp >= mc.max_fivemo_sp) return false;
        }
    }
    surplus_months++;
    mc.months[index] = 1;
    if(surplus_months > mc.max_surplus_months) 
        mc.max_surplus_months = surplus_months;;
    return true;
}

void backtrack(uint start,uint end,MCFinancials &mc,uint &surplus_months) {
    for(uint i = start; i < end; i++) {
        if(isSurplusMonth(i,mc,surplus_months)) {
            //printArray(mc.months);
            backtrack(i+1,end,mc,surplus_months);
            //surplus_months -= 1;
            //mc.months[i] = 0;
        }
    }
}

void maximizeSurplus(MCFinancials &mc) {
    uint surplus_months = 0;
    for(uint i = 0; i < 8; i++) {
        backtrack(i,i+5,mc,surplus_months); 
    }
    printResult(mc);
}

void printResult(MCFinancials &mc) {
    uint total_surplus = mc.surplus * mc.max_surplus_months;
    uint total_deficit = mc.deficit * (12 - mc.max_surplus_months);
    if(total_surplus > total_deficit) 
        cout << (total_surplus - total_deficit) << endl;
    else 
        cout << "Deficit\n";
}

void printArray(vector<bool> &v) {
    cout << "[";
    for(int i = 0; i < v.size(); i++) 
        if(i != v.size() - 1) cout << v[i] << ",";
        else cout << v[i] << "]\n";
}

void computeMostSurplusInFiveMonthStretch(MCFinancials &mc) {
    // we can have at most 4 surpluses and at a minimum we can have 0 surpluses
    uint max_fivemo_sp = 0;
    if(  mc.surplus < 4*mc.deficit) max_fivemo_sp++;
    if(2*mc.surplus < 3*mc.deficit) max_fivemo_sp++;
    if(3*mc.surplus < 2*mc.deficit) max_fivemo_sp++;
    if(4*mc.surplus <   mc.deficit) max_fivemo_sp++;
    mc.max_fivemo_sp = max_fivemo_sp;
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        cerr << "enter an input file" << endl; return -1;
    }
    uint s,d;
    freopen(argv[1],"r",stdin);
    while(cin >> s) {
        cin >> d;
        MCFinancials mc;
        mc.surplus = s;
        mc.deficit = d;
        computeMostSurplusInFiveMonthStretch(mc);
        maximizeSurplus(mc);
    }
    return 0;
}
