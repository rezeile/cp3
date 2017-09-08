/* @ 300 @ */

#include <cstdio>
#include <stack>
#include <string>
#include <iostream>
#include <sstream>
#include <vector>
#include <numeric>
#include <iterator>
using namespace std;

void rails(vector<int> &v) {
  stack<int> source;
  for (int i = v.size(); i >= 1; i--) 
    source.push(i);
  
  stack<int> station;
  
  for(int i = 0; i < v.size(); i++) {
    if (station.empty()) {
      // push the v[i]th item to the station if possible
      int sub = v.size() - v[i];
      int push_total = source.size() - sub;
      if (push_total <= 0) { 
        cout << "No" << endl;
        return;
      }
      for (int i = 0; i < push_total; i++) {
        int top = source.top(); source.pop();
        station.push(top);
      }
  
      if (station.top() == v[i]) 
        station.pop();
      else {
        cout << "No" << endl;
        return;
      }
    } else {
      if (station.top() == v[i]) 
        station.pop();
      else {
        int push_total = source.size() - (v.size() - v[i]);
        
        if (push_total <= 0) { 
          cout << "No" << endl;
          return;
        }

        for (int i = 0; i < push_total; i++) {
          station.push(source.top()); source.pop();
        }

        if (station.top() == v[i])
          station.pop();
        else {
          cout << "No" << endl;
          return;
        }
      }
    }
  }
  cout << "Yes" << endl;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N;
    string input;
    getline(cin,input);
    stringstream ss(input);
    ss >> N;
    
    while (N != 0) {
      while(getline(cin,input)) {
        if (input[0] == '0') break;
        vector<int> v;
        stringstream ss(input);
        int n;
        while(ss >> n) {
          v.push_back(n);
        }
        rails(v);
      }
      getline(cin,input);
      stringstream ss(input);
      ss >> N;
      cout << endl;
    }
    return 0;
}
