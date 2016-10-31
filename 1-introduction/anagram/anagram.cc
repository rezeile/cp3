#include <iostream>
#include <cstdio>
#include <set> // for std::set
#include <string>
#include <algorithm> // for lexicographical_compare
#include <cctype>
#include <vector>
#include <map>
#include <utility>
using namespace std;

class Compare { 
    public:
        bool operator() (char c1,char c2) {
            // same case, same letters
            if(c1 == c2) return false; 
            // diff case, same letters
            else if(tolower(c1) == tolower(c2)) return  c1 < c2;    
            // same case, diff letters
            else if((isupper(c1) && isupper(c2)) || (islower(c1) && islower(c2))) return c1 < c2;
            // diff case, diff letters
            return tolower(c1) < tolower(c2);
        }
}mycmp;

void printAllAnagrams(string s) {
    // reset to lexicographically first permutation
    while(next_permutation(s.begin(),s.end(),mycmp)) {}
    cout << s << endl;
    while(next_permutation(s.begin(),s.end(),mycmp)) printf("%s\n",s.c_str());
}
int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    int N;
    cin >> N;
    string s;
    for(int i = 0; i < N; i++) {
       cin >> s;
       printAllAnagrams(s);
    }
    return 0;
}
