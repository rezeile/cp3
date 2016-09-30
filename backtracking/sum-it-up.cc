#include <set>
#include <vector>
#include <iostream>            // for cout,cin
#include <cstdio>              // for freopen
#include <iterator>
using namespace std;
typedef set<vector<int>> svi;

void printResult(svi &result) {
    if(result.size() == 0) {
        cout << "NONE\n"; return;
    }
    set<vector<int>>::reverse_iterator i;
    for(i = result.rbegin(); i != result.rend(); i++) {
        vector<int> v = *i;
        for(int j = 0; j < v.size(); j++) {
            if(j != v.size() - 1) cout << v[j] << "+";
            else cout << v[j] << "\n";
        }
    }
}
void sumItUpHelper(int total,svi &v,vector<int> &candidate_set,vector<int> input_set) {
    if(total < 0 || input_set.size() <= 0) return;
    else if(total == 0) {
        vector<int> res(candidate_set);
        v.insert(res);
    } else {
       for(int i = 0; i < input_set.size(); i++) {
            vector<int> input_sset(input_set);
            int val = input_sset[i];
            input_sset.erase(input_sset.begin() + i);
            candidate_set.push_back(val);
            sumItUpHelper(total - val,v,candidate_set,input_sset);
            candidate_set.pop_back();
            input_sset.insert(input_sset.begin() + i,val);
       }
    }
}

svi sumItUp(int total,vector<int> s) {
    svi v;
    vector<int>::iterator i;
    for(i = s.begin(); i != s.end(); i++) {
        vector<int> sum_set;
        sumItUpHelper(*i,v,sum_set,s);
    }
    return v;
}

int main(int argc, char *argv[]) {
    int total,N;
    if(argc < 2) {
        cerr << "enter an input file" << endl; return -1;
    }
    freopen(argv[1],"r",stdin);
    while(cin >> total) {
        if(!total) break; // done 
        cin >> N;
        vector<int> s;
        int val;
        printf("Sums of %d:\n",total);
        for(int i = 0; i < N; i++) {
            cin >> val;
            s.push_back(val);
        }
        svi result = sumItUp(total,s);
        printResult(result);
    }
    return 0;
}
