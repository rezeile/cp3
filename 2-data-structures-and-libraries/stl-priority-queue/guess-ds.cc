#include <stack> // for std:: stack
#include <queue> // for std::queue, std::priority_queue
#include <cstdio>
#include <iostream>

int main(int argc, char *argv[]) {
    //if(argc < 2) {std::cout << "enter an input file"; return 0;}
    //std::freopen(argv[1],"r",stdin);
    int N, type, value;
    bool is_queue, is_pqueue, is_stack;
    while(scanf("%d",&N) != EOF) {
        std::stack<int> s;
        std::queue<int> q;
        std::priority_queue<int> pq;
        is_queue = is_pqueue = is_stack = true;
        for(int i = 0; i < N; i++) {
            std::cin >> type >> value; 
            if(type == 1) { s.push(value); q.push(value); pq.push(value);}
            else {
                if((!s.empty() && !q.empty()) && !pq.empty()) {
                    if(s.top() != value) is_stack = false;
                    s.pop();   
                    if(q.front() != value) is_queue = false;
                    q.pop();
                    if(pq.top() != value) is_pqueue = false;
                    pq.pop();
                } else {
                    is_stack = is_pqueue = is_queue = false;
                }
            }
        }
        if((is_stack && is_queue) || (is_stack && is_pqueue)) std::cout << "not sure\n";
        else if(is_queue && is_pqueue) std::cout << "not sure\n";
        else if (is_stack) std::cout << "stack\n";
        else if (is_queue) std::cout << "queue\n";
        else if (is_pqueue) std::cout << "priority queue\n";
        else std::cout << "impossible\n";
    }
    return 0;
}
