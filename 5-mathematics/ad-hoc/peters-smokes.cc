#include <cstdio>
using namespace std;

using ll = long long;

void peter(ll smoked, ll k) {
    ll new_cigs = smoked / k;
    ll extra_butts = smoked % k;
    while (new_cigs > 0) {
        smoked += new_cigs;
        ll total_butts = new_cigs + extra_butts;
        new_cigs = total_butts / k;
        extra_butts = k > total_butts  ? 0 : total_butts % k;
    }
    printf("%lld\n",smoked);
}

int main(int argc , char *argv[]) {
    //if (argc < 2) { printf("enter an input file.\n"); return -1; }
    //freopen(argv[1],"r",stdin);
    ll n, k;
    while (scanf("%lld %lld\n",&n,&k) != EOF ) {
        peter(n,k);
    }
    return 0;
}
