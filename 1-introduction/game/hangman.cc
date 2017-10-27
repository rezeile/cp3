#include <cstdio>
#include <string>
#include <iostream>
#include <set>
using namespace std;

#define WIN "You win."
#define LOSE "You lose."
#define CHICKEN "You chickened out."

string solve(int N,string word, string guess) {
  set<char> s(word.begin(),word.end()); 
  set<char> correct;
  set<char> wrong;
  for(int i = 0; i < guess.size(); i++) {
    if (correct.count(guess[i]) || wrong.count(guess[i])) continue;
    if (s.count(guess[i])) {
      correct.insert(guess[i]); 
    } else {
      wrong.insert(guess[i]);
    }
    if (correct.size() == s.size()) return WIN;
    if (wrong.size() == 7) return LOSE;
  }
  return CHICKEN;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N; string word, guess;
    while(scanf("%d\n",&N) != EOF) {
      if (N == -1) break;
      getline(cin,word);
      getline(cin,guess);
      printf("Round %d\n",N);
      cout << solve(N,word,guess) << endl;
    }
    return 0;
}
