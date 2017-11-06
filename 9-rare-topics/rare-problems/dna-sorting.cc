#include <cstdio>
#include <string>
#include <iostream>
#include <set>
#include <sstream>
using namespace std;

typedef struct dna {
  string s;
  int pos;
} dna;

class compare {
  public:
  bool operator() (const dna &lhs, const dna &rhs) {
    int lcount = inversionCount(lhs.s);
    int rcount = inversionCount(rhs.s);
    return (lcount == rcount) ? lhs.pos < rhs.pos: lcount < rcount;
  }

  private:
  int inversionCount(const string &s) {
    int count = 0;
    for(int i = 0; i < s.size(); i++) {
      for(int j = i+1; j < s.size(); j++) {
        if (s[i] > s[j]) count++;
      }
    }
    return count;
  }
};

void solve(set<dna,compare> &mset) {
  for (auto d: mset) 
    cout << d.s << endl;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int M,n,m;
    string input;
    getline(cin,input); 
    stringstream ss(input);
    ss >> M;
    while(M-->0) {
      getline(cin,input); // blank line 
      getline(cin,input);
      stringstream ss(input);
      ss >> n >> m;
      set<dna,compare> mset;
      int pos = 0;
      while(m-- > 0) {
        dna d = dna();
        getline(cin,input);
        d.s = input;
        d.pos = pos++;
        mset.insert(d); 
      }
      solve(mset);
      if (M) printf("\n");
    }
    return 0;
}
