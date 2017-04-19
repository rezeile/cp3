#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
#include <cctype>
#include <algorithm>
using namespace std;

int getIndex(char c) {
    if (isupper(c)) {
        return (c - 'A') + 26;
    } else {
        return c - 'a';
    }
}

void fillBates(string s,string input) {
    int arr[52];
    memset(arr,0,sizeof arr);
    int first = 0;
    int second = 0;
    for(int i = 0; i < input.size(); i++) {
        char c = input[i];
        int index = arr[getIndex(c)];
        auto search = find(s.begin() + index,s.end(),c);
        if (search != s.end()) {
            int index = search - s.begin();
            if(i == 0) first = index;
            if(i == input.size() - 1) second = index;
            arr[getIndex(c)] = index + 1;
            if (i < input.size() - 1 && arr[getIndex(input[i+1])] < arr[getIndex(c)])
                arr[getIndex(input[i+1])] = arr[getIndex(c)];
        } else {
            printf("Not matched\n");
            return;
        }
    }
    printf("Matched %d %d\n",first,second);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    string s,input;
    getline(cin,s); 
    int N;
    scanf("%d\n",&N);
    for(int i = 0; i < N; i++) {
        getline(cin,input);
        fillBates(s,input);
    }
    return 0;
}
