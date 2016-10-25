#include <iostream>
#include <cstdio>
#include <string>
#include <vector>
#include <numeric>
using namespace std;

typedef vector<vector<long long>> table;

long long bC(int N, int M,table &t) {
    if(N == M) return 1;
    if(N == 1 || M == 0) return 1;
    if(t[N][M] == -1) t[N][M] = bC(N-1,M,t) + bC(N-1,M-1,t);
    return t[N][M];
}

void helper(int index,long long D,int M,vector<int> &m_vec,vector<int> &v,int count) {
    if(index > v.size() || m_vec.size() > M) return;
    if(m_vec.size() == M) {
        long long sum = accumulate(m_vec.begin(),m_vec.end(),0);
        printf("sum(%lld) mod D(%lld) = %lld",sum,D,(sum % D));
        cout << (sum % D ? 1 : 0) << endl;
        count += (sum % D ? 1 : 0);
        return;
    } 
    m_vec.push_back(v[index]);
    helper(index+1,D,M,m_vec,v,count);
    m_vec.pop_back();
}

long long DGS(vector<int> &v,long long D,int M) {
    if(v.size() == 0 || M > v.size()) return 0;
    vector<int> m_vec;
    int count = 0;
    for(int i = 0; i < v.size(); i++) {
        m_vec.clear();
        helper(i,D,M,m_vec,v,count);
    }
    return count;
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    int N,Q,M;
    long long D;
    int cnt = 1;
    while(cin >> N) {
        if(N == 0) break;
        cin >> Q;
        vector<int> iv; iv.resize(N);
        for(int i = 0; i < N; i++) cin >> iv[i];
        printf("SET %d:\n",cnt++);
        for(int j = 1; j <= Q; j++) {
           cin >> D >> M;
           printf("QUERY %d: %lld\n",j,DGS(iv,D,M));
        }
    }
    return 0;
}
