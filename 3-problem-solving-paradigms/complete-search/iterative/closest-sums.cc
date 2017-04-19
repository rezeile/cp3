#include <cstdio>
#include <vector>
#include <cmath>
using namespace std;
#define INF 2000000000
void closestSums(vector<int> &v, vector<int> &q) {
    for(int i = 0; i < q.size(); i++) {
        int closest_sum = INF;
        int closest_diff = INF;
        for(int j = 0; j < v.size(); j++) {
            for(int k = j + 1; k < v.size(); k++) {
                int diff = abs((v[j]+v[k]) -(double) q[i]);
                if(diff < closest_diff) { 
                    closest_sum = v[j]+v[k]; 
                    closest_diff = diff;
                }
            }
        }
        printf("Closest sum to %d is %d.\n",q[i],closest_sum);
    }
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N,M;
    vector<int> v,q;
    int cno = 1;
    while (scanf("%d",&N) != EOF) {
        if (N > 0) {
            v.clear();
            for(int i = 0; i < N; i++) {
                int a; scanf("%d",&a); v.push_back(a);
            }
            scanf("%d",&M);
            q.clear();
            for(int i = 0; i < M; i++) {
                int a; scanf("%d",&a); q.push_back(a);
            }
            printf("Case %d:\n",cno++);
            closestSums(v,q); 
        }
    }
    return 0;
}
