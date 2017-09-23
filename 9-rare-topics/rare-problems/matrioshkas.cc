#include <cstdio>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <stack>
#include <unordered_map>
#include <utility>
using namespace std;

string good = ":-) Matrioshka!";
string bad = ":-( Try again.";

void solution(vector<int> &v) {
  stack<int> s;
  unordered_map<int,int> m;
  for (int i = 0; i < v.size(); i++) {
    if (v[i] < 0) {
      int val = -v[i];
      auto search = s.empty() ? m.end() : m.find(s.top());
      if (search != m.end()) {
        search->second += val;
        if (search->second >= s.top()) {
          cout << bad << endl;
          return;
        } 
      }
      s.push(val);
      m.insert(make_pair(val,0));
    } else {
      if (s.empty() || s.top() != v[i]) { cout << bad << endl; return; }  
      m.erase(s.top()); s.pop();
    }
  }
  if (!m.empty() || !s.empty()) { cout << bad << endl; }
  else { cout << good << endl; }
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    int n;
    string input;
    while(getline(cin,input)) {
      stringstream ss(input);
      vector<int> v;
      while(ss >> n) { v.push_back(n);}
      solution(v);
    }
    return 0;
}
