#include <iostream>
#include <cstdio>
using namespace std;

int main(int argc, char *argv[]) {
    freopen("../input/magic-square-03","w+",stdout);
    int TC = 60;
    int Length = 10000;
    string s = "";
    for(int i = 0; i < Length; i++)
        s += 'a';
    printf("%d\n",TC);
    for(int i = 0; i < TC; i++) {
        printf("%s\n",s.c_str());
    }
    return 0;
}
