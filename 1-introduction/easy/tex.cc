#include <cstdio>
#include <iostream>
#include <string>
using namespace std;

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    bool first = true;
    while(getline(cin,input)) {
      for(int i = 0; i < input.size(); i++) {
        if (input[i] == '"') {
          char c = first ? '`' : '\'';
          first = !first;
          input.replace(i,1,2,c);
        }
      }
      if (!input.empty())cout << input << endl;
    }
    return 0;
}
