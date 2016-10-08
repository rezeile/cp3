#include <string>
#include <algorithm>
#include <iostream>
#include <cstdio>
#include <vector>
#include "../../../util/testing.h"
#include <cctype>
using namespace std;

void printAnagramPairs(vector<string> &v) {
    for(int i = 0; i < v.size(); i++) {
        for(int j = i + 1; j < v.size(); j++) {
            string s1 = v[i];
            string s2 = v[j];
            s1.erase(remove_if(s1.begin(), s1.end(), ::isspace), s1.end());
            s2.erase(remove_if(s2.begin(), s2.end(), ::isspace), s2.end());
            sort(s1.begin(),s1.end());
            sort(s2.begin(),s2.end());
            if(s1 == s2) {
                if(s1 < s2) cout << v[j] << " = " << v[i] << endl;
                else        cout << v[i] << " = " << v[j] << endl;
            }
        }
    }
    cout << endl;
}

int main(int argc, char *argv[]) {
   /*if(argc < 2) {
        cerr << "enter an input file";
        return -1;
   }
   freopen(argv[1],"r",stdin);*/
   int T;
   cin >> T;
   string line;
   for(int i = 0; i < T; i++) {
        vector<string> v;
        if(i == 0) getline(cin,line);
        while(getline(cin,line) && line != "") {
            v.push_back(line);
        }
        printAnagramPairs(v);
  }
}
