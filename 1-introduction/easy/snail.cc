#include <iostream>
#include <cstdio>
using namespace std;

void climb(double H,double U,double D, double F) {
   double ff = (F / 100.0) * U;
   double height = 0.0;
   int day = 1;
   while(height >= 0.0) {
        if(U > 0.0) height += U;
        if(height > H) {printf("success on day %d\n",day); return; };
        height -= D;
        if(height < 0) {printf("failure on day %d\n",day); return; };
        U -= ff;
        day++;; 
   }
   printf("failure on day %d\n",day);
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    
    double H,U,F,D; 
    while(cin >> H) {
        if(H == 0) break;
        cin >> U >> F >> D;
        climb(H,U,F,D);
    }
    return 0;
}
