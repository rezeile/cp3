#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <utility>  // for pair
#include <vector> 
#include <queue>    // for priority_queue
using namespace std;

typedef pair<int,pair<int,int>> ii;
typedef vector<ii> vii;

/* 
   This function returns true if [ii](a) comes earlier than 
   [ii](b). This means that "a" has a smaller period value
   than b. Thus we want to sort in ascending order within 
   the priority queue. So if a < b, we need to make sure
   that b is the one pushed to the right.

   It returns true if a should be pushed to the left, false 
   otherwise.
 */
bool cmp(ii &a, ii &b) {
    int a_id = a.first;
    int b_id = b.first;
    int a_intvl = a.second.second;
    int b_intvl = b.second.second;

    if(a_intvl < b_intvl) return false;
    else if (a_intvl == b_intvl) {
        return b_id <= a_id;
    } else {
        return true;   
    }
};

auto my_comp = cmp;
using pq_t = priority_queue<ii,vector<ii>,decltype(my_comp)>; 

void argus(pq_t &pq,int N) {
   for(int i = 0; i < N; i++) {
        ii earliest = pq.top();
        int id = earliest.first;
        int interval = earliest.second.first;
        earliest.second.second += interval;
        pq.pop();pq.push(earliest);
        printf("%d\n",id);
   }
}

    
int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    pq_t data_stream(my_comp);
    while(getline(cin,input)) {
        if(input == "#") break;
        // Skip Register --> 9 charactesr 
        string s = input.substr(8);
        stringstream ss(s);
        int q; ss >> q;
        int p; ss >> p;
        data_stream.push(make_pair(q,make_pair(p,p)));
    }
    int N;
    cin >> N;
    argus(data_stream,N);
    return 0;
}
