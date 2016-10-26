#include <iostream>
#include <cstdio>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

void playLotto(vector<int> &v) {
    for(int i = 1; i < v.size(); i++) 
        for(int j = i + 1; j < v.size(); j++) 
            for(int k = j + 1; k < v.size(); k++)
                for(int l = k + 1; l < v.size(); l++)
                    for(int m = l + 1; m < v.size(); m++)
                        for(int n = m + 1; n < v.size(); n++) 
                            printf("%d %d %d %d %d %d\n",v[i],v[j],v[k],v[l],v[m],v[n]);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string s;
    string next;
    getline(cin,s);
    bool trailing = false;
    while(true) {
        getline(cin,next); 
        if(s.size() == 1 && stoi(s) == 0) break;
        stringstream ss(s);
        vector<int> v;
        int val;
        while(ss >> val) {
            v.push_back(val);
        }
        playLotto(v);
        if(next.size() == 1 && stoi(next) == 0) trailing = true;
        s = next;
        if(!trailing) printf("\n");;
    }
    return 0;
}
