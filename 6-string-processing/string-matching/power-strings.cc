#include <cstdio>
#include <string>
#include <iostream>
#include <climits>
#include <vector>
using namespace std;

int gcd(int a,int b) {
  return b == 0 ? a : gcd(b,a%b);
}

void debugPrintFreq(vector<int> &freq) {
  for(int i = 0; i < 26; i++) {
    if (freq[i]) {
      printf("%c --> ",'a'+i);
      cout << freq[i] << endl;
    }
  }
}

int solve(string s) {
  if (s.empty()) return 0;
  int min = INT_MAX;
  vector<int> freq(26);
  for(int i = 0; i < s.size(); i++) {
    int j = s[i]-'a';
    freq[j]++;
  }
  for(char c = 'a'; c <= 'z'; c++) {
    int j = c-'a';
    if (freq[j] && freq[j] < min) min = freq[j];
  }
  for(int i = 0; i < 26; i++) {
    int d = gcd(min,freq[i]);
    if (d < min) min = d;
  }
  
  for(char c = 'a'; c <= 'z'; c++) {
    int j = c - 'a';
    if (freq[j]) {
      if (freq[j] % min != 0) return 1;
    }
  }

  while(min > 1) {
    int i,skip = s.size() / min;
    string last = s.substr(0,skip);
    for(i = skip; i < s.size(); i += skip) {
        string cur = s.substr(i,skip);
        if (last != cur) {
          min /= 2;
          break;
        }
    }
    if (i >= s.size()) return min;
  }
  return min;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    string s;
    while(getline(cin,s)) {
      if (s == ".") break;
      cout << solve(s) << endl;
    }
    return 0;
}
