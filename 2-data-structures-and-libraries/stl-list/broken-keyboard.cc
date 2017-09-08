#include <cstdio>
#include <string>
#include <iostream>
#include <list>

/* Author: Eliezer Abate
 * Date: September 7 2017
 * @ 46 @
 */
using namespace std;

void addToText(string s, list<string> &text, bool front) {
  
  if (front) 
    text.push_front(s);
  else 
    text.push_back(s);
}

void beijuText(string input) {
  list<string> text;
  string current = "";
  bool front = false;
  for (int i = 0; i < input.size(); i++) {
    if (input[i] == '[') {
      if (!current.empty())
        addToText(current,text,front);
      front = true;
      current = "";
    } else if (input[i] == ']') {
      if (!current.empty()) 
        addToText(current,text,front);
      front = false;
      current = "";
    } else if (i == input.size() - 1) {
      current += input[i];
      addToText(current,text,front);
    } else {
      current += input[i];
    }
  }

  for (auto s: text) {
    cout << s;
  }
  cout << endl;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    string input;
    while(getline(cin,input)) {
      beijuText(input);
    }
    return 0;
}
