#include <cstdio>
#include <vector>
#include <utility>
#include <string>
#include <algorithm>
#include <iostream>
#include <numeric>
#include <cmath>
#define INF 2100000000
using namespace std;
using vii = vector<pair<int,int>>;

double distance(vii &v,int i, int j) {
    int dx = abs(v[i].first - v[j].first);
    int dy = abs(v[i].second - v[j].second);
    return sqrt(dx*dx + dy*dy);
}

void printResults(vii &v,vector<double> &tsp_dist,double min_dist,vector<int> &tsp) {
    for(int i = 1; i < tsp.size(); i++) {
        int x1 = v[tsp[i-1]].first, y1 = v[tsp[i-1]].second;
        int x2 = v[tsp[i]].first, y2 = v[tsp[i]].second;
        printf("Cable requirement to connect (%d,%d) to (%d,%d) is %.2f feet.\n",x1,y1,x2,y2,tsp_dist[i-1]);
    }
    printf("Number of feet of cable required is %.2f.\n",min_dist);
}

void shortestCable(vii &v) {
    double min_dist = INF;
    vector<int> p(v.size());
    iota(p.begin(),p.end(),0);
    vector<int> tsp(p.size());
    vector<double> tsp_dist(p.size() - 1);
    do {
        double dist = 0;
        vector<double> dv(tsp_dist.size());
        for(int i = 1; i < p.size(); i++) {
            dv[i-1] = 16 + distance(v,p[i],p[i-1]);
            dist += dv[i-1];
        }
        if(dist < min_dist) { 
            tsp_dist = dv;
            min_dist = dist; 
            tsp = p; 
        }
    } while (next_permutation(p.begin(),p.end())); 
    printResults(v,tsp_dist,min_dist,tsp); 
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N;
    int num = 1;
    while ( scanf("%d",&N) != EOF ) {
        if ( N > 0) {
            printf("**********************************************************\n");
            printf("Network #%d\n",num++);
            vii v(N);
            for(int i = 0; i < N; i++) {
                int a,b;
                scanf("%d %d\n",&a,&b);
                v[i].first = a; v[i].second = b;
            }
            shortestCable(v);
        }
    }
    return 0;
}
