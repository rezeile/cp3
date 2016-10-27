#include <iostream>
#include <cstdio>
#include <deque>
#include <cassert>
using namespace std;

deque<int> dA;
deque<int> dB;
deque<int> dC;
int count = 0;

void printPeg(deque<int> &peg,char c) {
    printf("%c=>   ",c);
    for(int i = 0; i < peg.size(); i++) {
        if(i != peg.size() - 1) printf("%d ",peg[i]);
        else printf("%d\n",peg[i]);
    }
    if(peg.empty()) printf("\n");
}

deque<int> &get_peg(int n) {
	assert(n >= 1 && n <= 3);
	if(n == 1) return dA;
	else if (n == 2) return dB;
	else  return dC;
}

void printPegs() {
    printPeg(dA,'A');printPeg(dB,'B');printPeg(dC,'C');
    printf("\n");
}

void hanoi(int src,int dst,int tmp,int size,int m) {
    printPegs();
    if(size <= 1) {
        if(!(get_peg(src)).empty()) {
            (get_peg(dst)).push_back((get_peg(src)).back());(get_peg(src)).pop_back();
        }
        return;
    }
    // move top [1...size-1] elemnents from src to tmp
    hanoi(src,tmp,dst,size-1,m);
    
    // move bottom most element to dst (i.e. if src.size() == 1) 
    if(!(get_peg(src)).empty()) {
        (get_peg(dst)).push_back((get_peg(dst)).back());(get_peg(src)).pop_back();
    }
    // move elements [1...size-1] from tmp to dst
    hanoi(tmp,dst,src,size-1,m);
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int a,b;
    int prob_num = 1;
    while(cin >> a) {
        if(a == 0) break;
        cin >> b;
        dA.clear(); dB.clear(); dC.clear();
        for(int i = 0; i < a; i++) {
            dA.push_front(i+1);    
        }
        printf("Problem #%d\n\n",prob_num++);
        hanoi(1,3,2,a,b); printf("\n");
    }
    return 0;
}
