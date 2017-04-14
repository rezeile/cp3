#include <cstdio>
#include <iostream>
#include <deque>
#include <sstream>
using namespace std;

void pancakeSort(deque<int> &q) {
   deque<int> stack = q; 
   deque<int> queue;
   
   int N = q.size();
   string output = "";
   while (N > 1) {
       int expected_location = q.size() - N;
       if (stack[expected_location] == N) { N--; continue; }
       // get element to the top if not there already  
       while (stack.back() != N) {
            queue.push_back(stack.back()); stack.pop_back();
       }
       queue.push_back(stack.back()); stack.pop_back();
       // push element N into the queue and re-add queue elements to stack
       while (!queue.empty()) {
            stack.push_back(queue.front()); queue.pop_front();
       }
        
       // reverse elements 
       int top = q.size() - 1;
       for (int i = 0; i < N; i++) {
            int tmp = stack[expected_location + i];
            stack[expected_location + i] = stack[top - i];
            stack[top - i] = tmp;
       }
       output += to_string(expected_location + 1) + " ";
       N -= 1;
   }
   output += to_string(0);
   cout << output << endl;
}

int main(int argc, char *argv[]) {
    if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    freopen(argv[1],"r",stdin);
    
    string input;
    while(getline(cin,input)) {
        stringstream ss(input);
        deque<int> q;
        int N;
        while ( ss >> N) {
            q.push_front(N);
        }
        cout << input << endl;
        pancakeSort(q);    
    }
    return 0;
}
