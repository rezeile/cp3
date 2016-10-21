#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen("input/prince-05.txt","w+",stdout);
    int T = 10,p,q,n;
    n = 250;
    p = q = (250 * 250) - 1;
    int first = 1;
    int last = p + 1;
    // test case
    cout << T << endl;
    for(int i = 0; i < T; i++) {
        // n,p,q
        printf("%d %d %d\n",n,p,q);
        for(int k = 0; k < 2; k++) {
            for(int j = first; j <= last; j++) {
                if(j == last) printf("%d\n",j);
                else printf("%d ",j);
            }
        }
    }
    return 0;
}
