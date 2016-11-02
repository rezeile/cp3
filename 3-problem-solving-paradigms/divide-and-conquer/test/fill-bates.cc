#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    freopen("../input/fill-bates-06","w+",stdout);
    int Q = 3500;
    int MAX = 1000000 / 2;
    string s = "";
    for(int i = 0; i < MAX; i++) {
        s += 'a';
    }
    for(int i = 0; i < MAX; i++)
        s += 'b';
    printf("%s\n",s.c_str());
    printf("%d\n",Q);
    string q = "aabb";
    for(int i = 0; i < Q; i++) {
        printf("%s\n",q.c_str());
    }
    return 0;
}
