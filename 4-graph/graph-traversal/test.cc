#include <iostream>
#include <cstdio>
#include <cstdlib> // srand,rand
#include <ctime>   // time
#include <unordered_set>
using namespace std;

void mutant() {
    freopen("input/mutant-03.txt","w+",stdout);
    srand(time(NULL));
    // largest dimensions
    int N = 50, M = 50;
    printf("%d %d\n",N,M);
    for(int i = 0; i < 20; i++) {
        // random starting position
        int x = rand() % 50 + 1;
        int y = rand() % 50 + 1;
        int c = rand() % 4 + 1;
        char dir;
        if(c == 1) dir = 'N'; if(c == 2) dir = 'E'; 
        if(c == 3) dir = 'S'; if(c == 4) dir = 'W';
        printf("%d %d %c\n",x,y,dir);

        // random string
        string s = "";
        for(int i = 0; i < 100; i++) {
            int num = rand() % 3 + 1;
            if(num == 1) s += 'L';
            if(num == 2) s += 'R';
            if(num == 3) s += 'F';
        }

        printf("%s\n",s.c_str());
    }
}

void random(int N) {
    freopen("input/forward-05.txt","w+",stdout);
    int TC = 20,u,v;
    printf("%d\n%d\n",TC,N);
    unordered_set<int> s;
    srand(time(NULL));
    while(s.size() <= N) {
        u  = rand() % N + 1;
        v  = rand() % N + 1;
        if(s.find(u) != s.end()) continue;
        if(u == v) v--;
        printf("%d %d\n",u,v);
    }
}

void large(int N) {
    freopen("input/forward-04.txt","w+",stdout);
    int TC = 20,u,v;
    printf("%d\n",TC);
    for(int i = 0; i < TC; i++) {
        printf("%d\n",N);
        for(int i = 1; i <= N; i++) {
            if(i != N) { u = i; v = i + 1;}
            else {u = i; v = 1; }
            printf("%d %d\n",u,v);
        }
    }
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input integer." << endl; return 0; }
    //int N = atoi(argv[1]);
    //large(N);
    mutant();
    return 0;
}
