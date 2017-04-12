#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <deque>
using namespace std;

void triangleWave(int amp, int freq) {
    deque<string> d;
    string output;
    for(int i = 1; i <= amp; i++) {
        vector<char> v(i,to_string(i)[0]);
        string str(v.begin(),v.end());
        d.push_back(str);
        output +=  str + "\n";
    }
    d.pop_back();
    for(auto it = d.crbegin(); it != d.crend(); ++it)
        output +=  *it + "\n";
    
    while (freq-- != 0) {
        cout << output;
        if (freq != 0) cout << endl;
    }
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    int N;
    getline(cin,input);
    stringstream ss(input); ss >> N;
    for(int i = 0; i < N; i++) {
        getline(cin,input); // blank line
        int A, F;
        getline(cin,input); 
        ss.clear(); ss.str(input); ss >> A;
        getline(cin,input);
        ss.clear(); ss.str(input); ss >> F;
        triangleWave(A,F);
        if(i != N - 1) printf("\n");
    }
    return 0;
}
