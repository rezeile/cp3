#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
using namespace std;

int babylon(vector<int> &v) {
    /*for(int i = 0; i < v.size(); i++) {
        if(i != v.size() - 1) printf("%d ",v[i]);
        else printf("%d\n",v[i]);
    }*/
    return 8;
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    int TC;
    int CN = 1;
    while(getline(cin,input)) {
        stringstream ss(input);
        ss >> TC;
        if(TC == 0) break;
        int max = 0;
        vector<int> v(3);
        for(int i = 0; i < TC; i++) {
            string input;
            getline(cin,input);
            stringstream ss(input);
            ss >> v[0] >> v[1] >> v[2];
            int nmax = babylon(v);
            if(nmax > max) max = nmax;
        }
        printf("Case %d: maximum height = %d\n",CN++,max);
    }
    return 0;
}
