#include <cstdio>
#include <numeric>
#include <vector>
#include <set>
#include <cmath>
using namespace std;

bool isPrime(int N) {
    int sqr = ceil(sqrt(N));
    for(int i = 2; i <= sqr; i++) {
        if (N % i == 0) return false;
    }
    return true;
}

void printVector(vector<int> &v) {
    for(int i = 0; i < v.size(); i++) {
        if(i != v.size() - 1) printf("%d ",v[i]);
        else printf("%d\n",v[i]);
    }
}

void primeRingHelper(vector<int> v,set<int> s,int N) {
    set<int> inelig(v.begin(),v.end());
    if(v.size() == N && isPrime(v[0] + v[N-1])) printVector(v); 
    else {
        for(auto it = s.begin(); it != s.end();) {
            int val = *it;
            if (inelig.find(val) == inelig.end() && isPrime(v.back() + val)) {
                v.push_back(val); it = s.erase(it);
                primeRingHelper(v,s,N);
                inelig.erase(val); s.insert(val); v.pop_back();
            } else {
                inelig.insert(val);
                it++;
            }
        }
    }
    inelig.erase(v.back()); v.pop_back();
}

void primeRing(int N) {
    vector<int> v(1,1);
    set<int> s;
    for(int i = 2; i <= N; i++) s.insert(i);
    primeRingHelper(v,s,N);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    int N;
    int cn = 1;
    scanf("%d",&N);
    while (true) {
        printf("Case %d:\n",cn++);
        primeRing(N);
        if(scanf("%d",&N) != EOF) printf("\n");
        else break;
    }
    return 0;
}
