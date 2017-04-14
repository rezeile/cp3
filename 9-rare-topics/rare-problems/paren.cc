#include <cstdio>
#include <string>
#include <iostream>
#include <unordered_map>
#include <stack>
using namespace std;
using ll = long long;

unordered_map<char,char> map = {{']','['},{')','('}};

void balancedParen(string input) {
    ll size = input.size();
    stack<char> s;
    for(int i = 0; i < size; i++) {
        if (map.find(input[i]) == map.end()) s.push(input[i]);
        else {
            if (s.empty() || map[input[i]] != s.top()) { printf("No\n"); return; }
            else s.pop();
        }
    }
    if (s.empty()) printf("Yes\n");
    else printf("No\n");
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    ll N;
    scanf("%lld\n",&N);
    string input;
    for(int i = 0; i < N; i++) { 
        getline(cin,input);
        balancedParen(input);
    }
    return 0;
}
