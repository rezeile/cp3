#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cstring>
#include <cctype>
using namespace std;

void initDelimiters(char *delim) {
    int index = 0;
    for(int i = 32; i < 127; i++) {
        char c = (char) i;
        if (!isalpha((char)i)) delim[index++] = c;
    }
    delim[index] = '\0';
}

void wordCount(string s,char *delim) {
    char *str = strdup(s.c_str());
    //char delim[] = " ,~`!@#$%^&*()-_+=|:;\"<,>.?/";
    int count = 0;
    char *next = strtok(str,delim);
    while (next != NULL) {
        count++;
        next = strtok(NULL,delim);
    }
    printf("%d\n",count);
    free (str);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    char delim[256];
    initDelimiters(delim);
    while(getline(cin,input)) {
        wordCount(input,delim);       
    }
    return 0;
}
