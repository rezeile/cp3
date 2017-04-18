#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <set>
using namespace std;

/* For a string S of length N, the brute force idea would 
   be to check, for i from 1 to N, if every i length substring
   of S is indeed a palindrome 
   
   For example if we consider the string ADAM, a string of 
   length 4.
   
   length 1 substring: A, D, A, B 
   
   length 2 substring: AD, DA, AM
   
   length 3 substring: ADA, DAM
   
   length 4 substring: ADAM
   
   Now can we do better than examining each i length adjactent 
   letter?

   Let's consider the top-down approach (i.e. going from ADAM,
   the string of length 4, to each of the length 1 substrings).

   We know that a String of length N whose characters are 
   s_1,s_2,...,s_N is a palindrome if and only if s_1 equals
   s_N and the substring s_2,s_3,...,s_N-1 is also a palindrome.
   Furthermore, we know that for the base case that that the 
   empty string or a string with a single character is also a 
   palindrome.

   Now the question is, in the course of determining whether 
   the larger string is a palindrome, can we also perform 
   work that might prevent us from duplicating work?

   For now let's consider the naive approach of getting all 
   the length i substrings of the string and adding them
   to the palindrome list.

   */

/* 
 Now let's consider the approach we will take to determine the 
 indices for the substring.

 As an example consider the string ELIEZER. 

 [0, 1, 2, 3, 4, 5, 6]

  |  |  |  |  |  |  |

  E  L  I  E  Z  E  R

  Length 1 Indices: {0,  1,  2,  3,  4,  5,  6}
  
  Length 2 Indices: {0-1,1-2,2-3,3-4,4-5,5-6}

  Length 3 Indices: {0-2,1-3,2-4,3-5,4-6}

  Length 4 Indices: {0-3,1-4,2-5,3-6}

  Length 5 Indices: {0-4,1-5,2-6}

  Length 6 Indices: {0-5,1-6}

  Length 7 Indices: {0-7}
*/
bool is_palindrome(string &s) {
    if(s.size() <= 1) return true;
    if(s[0] == s[s.size() - 1]) {
        string substring = s.substr(1,s.size() - 2);
        return is_palindrome(substring);
    }
    return false;
}

/* Example with 'boy':

   input.size() = 3
   i = 1 to 3
     j = 0 <= (3 - i) , j++

     First Iteration: {'b','o','y'}

*/
void peskyPalindrome(string &input) {
    set<string> unique_palindromes;
    for(int i = 1; i <= input.size(); i++) {
        for(int j = 0; j <= (input.size() - i); j++) {
            string s = input.substr(j,i);
            if(is_palindrome(s)) unique_palindromes.insert(s);
        }
    }
    printf("The string '%s' contains %lu palindromes.\n",input.c_str(),unique_palindromes.size() );
}

void testPalindrome(string input,bool expected) {
    bool result = is_palindrome(input);
    if(result == expected) printf("CORRECT\n");
    else printf("ERROR\n");
}

void testEasy() {
    testPalindrome(string("a"),true);
    testPalindrome(string("aa"),true);
    testPalindrome(string("ab"),false);
    testPalindrome(string("madam"),true);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { cerr << "enter an input file"; return -1; }
    //freopen(argv[1],"r",stdin);
    string input;
    while(getline(cin,input)) {
       peskyPalindrome(input); 
    }
    return 0;
}
