#include <cstdio>
#include <cstring>
#include <string>
#include <iostream>
#include <vector>
#include <cmath>
using namespace std;

char getChar(string s) {
  string d2 = s.substr(0,3);
  string d1 = s.substr(3,1) + s.substr(5,s.size());
  

  int h1 = 0, h2 = 0;
  for(int i = 0; i < d2.size(); i++) {
    if (d2[i] == 'o') {
      h2 += (int) pow(2,(d2.size() - 1)-i);
    }
  }
  
  for(int i = 0; i < d1.size(); i++) {
    if (d1[i] == 'o') {
      h1 += (int) pow(2,(d1.size()-1)-i);
    }
  }
  
  int dec_value = h2*16 + h1;
  return (char) dec_value;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
   
    string input;
    while (getline(cin,input)) {
      if (input != "___________") {
        string s = input.substr(2,input.size()-3);
        printf("%c",getChar(s));
      }
    }
    return 0;
}
