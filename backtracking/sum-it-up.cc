#include <algorithm>
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
void sumItUpHelper(int index,int total,svi &v,vector<int> &candidate_set,vector<int> input_set) {
    if(index > input_set.size()|| total < 0) return;
    else if(total == 0) {
        vector<int> res(candidate_set);
        sort(res.begin(),res.end(),greater<int>());
        v.insert(res);
    } else {
        int val = input_set[index];
        total -= val;
        candidate_set.push_back(val);
        for(int i = index + 1; i <= input_set.size(); i++) {
            sumItUpHelper(i,total,v,candidate_set,input_set);   
        }
        candidate_set.pop_back();
        total += val;

    }
}


svi sumItUp(int total,vector<int> s) {
    svi v;
    for(int i = 0; i < s.size(); i++) {
        vector<int> sum_set;
        sumItUpHelper(i,total,v,sum_set,s);
    }
    return v;
}

int main(int argc, char *argv[]) {
    int total,N;
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
