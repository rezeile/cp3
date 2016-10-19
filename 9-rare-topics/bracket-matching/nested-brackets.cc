#include <iostream>
#include <cstdio>
#include <unordered_set>
#include <string>
#include <unordered_map>
#include <stack>
using namespace std;

typedef unordered_set<string> uss;
typedef unordered_map<string,string> umss;

void balanced(string s,uss &open, uss &close,umss &map) {
    stack<string> stk;
    for(int i = 0; i < s.size() - 1; i++) {
        string s1 = string(1,s[i]);
        string s2 = s1 + string(1,s[i+1]);
        auto search = map.find(s2) != map.end() ? map.find(s2) : map.find(s1);
        // if close brackets
        if(search != map.end()) {
            if(search->second != stk.top()) {printf("NO %d\n",i); return;}
            else { stk.pop(); };
        } else if(open.find(s1) != open.end()) {
            if(open.find(s2) != open.end()) stk.push(s2);
            else stk.push(s1);
        }
    }
    // check edge case
    string last = string(1,s[s.size() -1]);
    int last_index = s.size() - 1;
    if(open.find(last) != open.end()|| !stk.empty()) printf("NO %d\n",last_index);
    else printf("YES\n");
}


int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    unordered_set<string> open = {"(","[","{","<","(*"};
    unordered_set<string> close = {")","]","}",">","*)"};
    unordered_map<string,string> map = {{")","("},{"]","["},{"}","{"},{">","<"},{"*)","(*"}};
    string s;
    while(getline(cin,s)) {
        if(s.size() == 0) {printf("YES\n"); continue;}
        balanced(s,open,close,map);        
    }
    return 0;
}
