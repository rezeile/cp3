#include <vector>
#include <cstdio>
#include <iostream>
//#include "../../util/testing.h" 
using namespace std;

int searchForCandidate(string s,int start, int end, char c) {
    if(start <= end) {
        int mid = (start + end) / 2;
        int leftResult = searchForCandidate(s,start,mid-1,c);
        if(leftResult != -1) return leftResult;
        if(s[mid] == c) return mid;
        return searchForCandidate(s,mid+1,end,c);
    }
    return -1;
}

void fillBates(string query, string candidate_list) {
    int start_index = 0;
    int first_cand, last_cand = -1;
    int max_size = candidate_list.size();
    for(int i = 0; i < query.size(); i++) {
        int res = searchForCandidate(candidate_list,start_index,max_size,query[i]);
        if(res == -1) { cout << "Not matched\n"; return; };
        if(i == 0) first_cand = res;
        if(i == query.size() - 1) last_cand = res;
        start_index = res + 1;
    }
    if(first_cand != -1 && last_cand != -1) cout << "Matched " << first_cand << " " << last_cand << "\n";
}

int main(int argc, char *argv[]) {
    /*if(argc < 2) {
        cerr << "enter an input file.";
        return -1;
    }
    freopen(argv[1],"r",stdin);*/
    string candidates;
    getline(cin,candidates);
    int Q;
    cin >> Q;
    vector<string> queries;
    string query;
    for(int i = 0; i < Q; i++) {
        cin >> query;
        fillBates(query,candidates); 
    }
    //printArray(queries);
    return 0;
}
