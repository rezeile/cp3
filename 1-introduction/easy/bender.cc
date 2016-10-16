#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
using namespace std;

string newDirection(string tip,string bend_dir) {
    if(tip[1] == 'x') {
        return tip[0] == '+' ? bend_dir : (bend_dir[0] == '-' ? "+" : "-")+ string(1,bend_dir[1]); 
    } else if((tip[1] == 'z' && bend_dir[1] == 'y') || (tip[1] == 'y' && bend_dir[1] == 'z')) {
        return tip;
    } else if(tip[1] == bend_dir[1]) {
        return tip[0] == bend_dir[0] ? "-x" : "+x"; 
    } 
    return tip;
}

/* test input */
void printVector(vector<string> &v) {
    cout << "[";
    for(int i = 0; i < v.size(); i++) {
        if(i != v.size() - 1) cout << v[i] << ",";
        else cout << v[i];
    }
    cout << "]\n";
}

void printDirection(vector<string> &v, string tip) {
    for(int i = 0; i < v.size(); i++) {
        if(v[i] == "No") continue;
        tip = newDirection(tip,v[i]); 
    }
    cout << tip << endl;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    int L;
    string s;
    vector<string> v;
    while(cin >> L) {
        if(L == 0) break;
        v.clear();
        for(int i = 0; i < L - 1; i++) {
            cin >> s;
            v.push_back(s);
        }
        printDirection(v,"+x");
    }
    return 0;
}
