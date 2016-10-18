#include <iostream>     // for std::cout, std::cerr, std::cin
#include <cstdio>       // for std::freopen
#include <map>          // for std::map
#include <unordered_set>// for std::unordered_set
#include <vector>       // for std::vector
#include <string>       // for std::string
#include <algorithm>    // for std::sort
#include <set>          // for std::set
#include <iterator>
using namespace std;

typedef unordered_set<char> sc;
typedef vector<vector<char>> mtx;

#define COL 5
#define ROW 6

bool goodCandidate(char ch,mtx &m1,map<int,sc> &m2,int col) {
    auto search = m2.find(col);
    if(search != m2.end()) {
        sc char_set = search->second;
        return char_set.find(ch) != char_set.end(); 
    }
    return false;
}

void kthPasswordHelper(mtx &m1,map<int,sc> &m2,set<string> &string_set,int col,string candidate) {
    if(col <= COL) {
        if(candidate.size() == 5) {string_set.insert(candidate);return;}
        for(int r = 0; r < ROW; r++) {
            char ch = m1[r][col];
            if(goodCandidate(ch,m1,m2,col)) {
                candidate += ch;
                ++col;
                kthPasswordHelper(m1,m2,string_set,col,candidate);
                --col;
                candidate = candidate.substr(0,candidate.size() - 1);
            }
        }
    }
}

string kthPassword(mtx &m1,map<int,sc> &m2,size_t k) {
    set<string> string_set;
    string candidate = "";
    kthPasswordHelper(m1,m2,string_set,0,candidate);
    auto i = string_set.begin();
    if(k <= string_set.size()) { advance(i,(k-1)); return *i;}
    else return "NO";
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    
    // obtain input 
    int T,k;
    char c;
    cin >> T;
    for(int i = 0; i < T; i++) {
        cin >> k;
        mtx m1(6,vector<char>(5));
        map<int,unordered_set<char>> m2 = {{1,sc()},{2,sc()},{3,sc()},{4,sc()},{5,sc()}};
        for(int j = 0; j < ROW; j++) {
            for(int k = 0; k < COL; k++) {
                cin >> m1[j][k];
            }
        }
        for(int j = 0; j < ROW; j++) {
            for(int k = 0; k < COL; k++) {
                cin >> c; 
                m2[k].insert(c);
            }
        }
        cout << kthPassword(m1,m2,k) << endl;
    }
    return 0;
}
