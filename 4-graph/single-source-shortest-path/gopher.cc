#include <iostream>
#include <cstdio>
#include <vector>
#include <sstream>
#include <string>
using namespace std;

void solve(vector<pair<double,double>> &vec,int v,int m,double xs,double ys,double x_t,double y_t) {
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int v, m;
    double xs, ys,x_t, y_t;
    string input;
    stringstream ss;
    while(getline(cin,input)) {
        ss << input;
        ss >> v >> m;
        if(v == 0 && m == 0) break;
        ss >> xs >> ys;
        ss >> x_t >> y_t;
        double x,y;
        vector<pair<double,double>> vec;
        string s;
        vec.clear();
        while(getline(cin,s)) {
            if(s == "") break;
            vec.clear();
            stringstream ss(s);
            ss >> x >> y;
            auto p = make_pair(x,y);
            vec.push_back(p);
        }
        solve(vec,v,m,xs,ys,x_t,y_t);
    }
    return 0;
}
