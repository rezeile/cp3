#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
using namespace std;

void printResult(stack<string> &s, int N) {
    printf("%lu\n",s.size());
    while(!s.empty()) {
       printf("%d/%d = ",1,N);
       printf("%s",s.top().c_str()); s.pop();
    }
}

void fractions(int N) {
    stack<string> s;
    int x = 2*N, y = 2*N;
    for(int i = y; i > N; i--) {
        x = N*i/(i-N);
        if(N*i % (i - N) == 0 && x >= i) {
            char buf[50];
            sprintf(buf,"%d/%d + %d/%d\n",1,x,1,i);
            s.push(string(buf));
        }
    }
    printResult(s,N);
}

int main(int argc, char *argv[]) {
    if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    freopen(argv[1],"r",stdin);
    int N;
    while (scanf("%d",&N) != EOF ) {
        fractions(N);
    }
    return 0;
}
