#include <cstdio>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

int dp[1000][1000];

int solveHelper(string &s, int l, int r) {
  if (l > r) return 0;
  if (dp[l][r] > 0) return dp[l][r];
  if (l == r) return (dp[l][r] =  1);
  else if (l+1 == r) return (dp[l][r] = 1 + (s[l] == s[r]));
  else if (s[l] == s[r]) return (dp[l][r] = 2 + solveHelper(s,l+1,r-1));
  else return (dp[l][r] = max(solveHelper(s,l+1,r),solveHelper(s,l,r-1)));
}

void solve(string &s) {
  memset(dp,-1,sizeof dp);
  cout << solveHelper(s,0,(int)s.size()-1) << endl;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    int T; scanf("%d\n",&T);
    string input;
    while(getline(cin,input)) {
      solve(input);
    }
    return 0;
}
