#include <queue> // for std::priority_queue
#include <cstdio>
#include <iostream>   // for std::cin,std::cout
#include <functional> // for std::lesser

void addAll(std::priority_queue<int,std::vector<int>,std::greater_equal<int>> &pq) {
    if(pq.empty()) return;
    int sum = 0, cost = 0;
    while(pq.size() > 1) {
        sum = pq.top(); pq.pop();
        sum += pq.top(); pq.pop();
        cost += sum;
        pq.push(sum);
    }
    pq.pop();
    std::cout << cost << std::endl;
}

int main(int argc, char *argv[]) {
    //if(argc < 2) {std::cout << "enter an input file"; return 0;}
    //std::freopen(argv[1],"r",stdin);
    int T = 0,val = 0;
    std::priority_queue<int,std::vector<int>,std::greater_equal<int>> pq;
    while(true) {
        std::cin >> T;
        if(T == 0) break;
        for(int i = 0; i < T; i++) {
            std::cin >> val;
            pq.push(val);
        } 
        addAll(pq);
    }
    return 0;
}
