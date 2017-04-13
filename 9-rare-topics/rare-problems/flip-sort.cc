#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;

void flipSort(vector<int> &v) {
    int inv_count = 0;
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            if (v[i] > v[j]) inv_count++;
        }
    }
    printf("Minimum exchange operations : %d\n",inv_count);
}

int main(int argc, char *argv[]) {
   //if (argc < 2) { printf("enter an input file.\n"); return -1; }
   //freopen(argv[1],"r",stdin);
   int N;
   string input;
   stringstream ss; 
   while (getline(cin,input)) {
       ss.clear(); ss.str(input);
       ss >> N;
       getline (cin,input);
       ss.clear(); ss.str(input);
       vector<int> v(N);
       for(int i = 0; i < N; i++) ss >> v[i];
       flipSort(v);
   }
   return 0;
}
