#include <cstdio>
#include <string>
#include <sstream>
#include <iostream>
#include <vector>

using namespace std;
using ll = long long;
void mergeSort (vector<ll> &v,ll &inv_count) {
    if (v.size() > 1) {
        ll mid = (v.size()) / 2;
        
        vector<ll> left (v.begin(), v.begin() + mid);
        vector<ll> right (v.begin() + mid, v.end());
        
        mergeSort (left,inv_count);
        mergeSort (right,inv_count);
        
        // merge the two sorted vectors 
        ll i = 0, j = 0;
        for (ll k = 0; k < v.size(); k++) {
            if (i < left.size() && j < right.size()) {
                if (left[i] <= right[j]) v[k] = left[i++];
                else {
                    v[k] = right[j++];
                    inv_count += (left.size() - i);
                }
            } 
            else if (i < left.size()) v[k] = left[i++];
            else v[k] = right[j++]; 
        }
    }
}

void flipSortNaive(vector<ll> &v) {
    ll inv_count = 0;
    ll N = v.size();
    for(ll i = 0; i < N; i++) {
        for(ll j = i + 1; j < N; j++) {
            if (v[i] > v[j]) inv_count++;
        }
    }
    printf("Minimum exchange operations : %lld\n",inv_count);
}

void flipSort(vector<ll> &v) {
    ll inv_count = 0;
    mergeSort(v,inv_count);
    printf("Minimum exchange operations : %lld\n",inv_count);
}

int main(int argc, char *argv[]) {
   //if (argc < 2) { printf("enter an input file.\n"); return -1; }
   //freopen(argv[1],"r",stdin);
   int N;
   string input;
   while ( scanf("%d",&N) != EOF)  {
       ll v[N];
       for(ll i = 0; i < N; i++) scanf("%lld",&v[i]);
       vector<ll> vec(v,v + N);
       flipSort(vec);
   }
   return 0;
}
