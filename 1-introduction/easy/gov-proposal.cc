#include <iostream>
#include <cstdio>
#include <unordered_set>
#include <string>
#include <vector>     
#include <queue>     // for std::priority_queue
#include <tuple>
#include <sstream>
using namespace std;
class Compare {
    public: 
        bool operator() (tuple<string,int,double> &a, tuple<string,int,double> &b) {
            if(get<1>(a) < get<1>(b)) return true;
            else if(get<1>(a) == get<1>(b) && get<2>(a) >  get<2>(b)) return true;
            return false;
        }
};

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    int N, P;
    bool first = true;
    int prop_num = 1;
        while(scanf("%d %d\n",&N,&P) == 2) {
        if(N == 0) break;
        string req,prop_name,s;
        double price; int num_req;
        priority_queue<tuple<string,int,double>,std::vector<tuple<string,int,double>>, Compare> pq;
        
        // clear requirements
        for(int i = 0; i < N; i++) {
            getline(cin,req);
        }
        
        for(int i = 0; i < P; i++) {
            // add tuple info
            getline(cin,prop_name);
            stringstream ss; string str;
            getline(cin,str); ss << str;
            ss >> price >> num_req;
            // clear actual proposals
            for(int j = 0; j < num_req; j++) {
                getline(cin,s); 
            }
            tuple<string,int,double> t(prop_name,num_req,price);
            pq.push(t);
        }
        tuple<string,int,double> best = pq.top();
        if(!first) { cout << endl; } else { first = false; }
        printf("RFP #%d\n",prop_num++);
        cout << get<0>(best) << endl;
    }
    return 0;
}
