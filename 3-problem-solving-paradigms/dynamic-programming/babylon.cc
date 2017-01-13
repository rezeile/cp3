#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <set>
#include <utility> // for pair
using namespace std;

enum relation {
    IS_SMALLER,
    IS_LARGER,
    NO_RELATION
};

class Compare {
    public:
    bool operator() (const tuple<int,int,int> &t1,const tuple<int,int,int> &t2) const {
         return get<0>(t1) < get<0>(t2) && get<1>(t1) < get<1>(t2);
    }
};
// custom comparator 
enum relation cmp(tuple<int,int,int> &t1,tuple<int,int,int> &t2) {
    //printf("t1[0] = %d < t2[0] = %d && t1[1] = %d < t2[1] = %d\n",get<0>(t1),get<0>(t2),get<1>(t1), get<1>(t2));
    if(get<0>(t1) > get<0>(t2) && get<1>(t1) > get<1>(t2)) return IS_LARGER;
    else if (get<0>(t1) > get<0>(t2) && get<1>(t1) > get<1>(t2)) return IS_SMALLER;
    return NO_RELATION;
}

// test final state of L
void printL(vector<pair<int,int>> &L) {
    for(int i = 0; i < L.size(); i++) {
        if(i != L.size() - 1) printf("(%d,%d) ",L[i].first,L[i].second);
        else printf("(%d,%d)\n",L[i].first,L[i].second);
    }
}

// tests

/* test set */

void babylonSetTest(set<tuple<int,int,int>> &s) {
   vector<tuple<int,int,int>> v(s.begin(),s.end());
   for(int i = 0; i < v.size(); i++) {
        if(i != v.size() - 1) printf("(%d,%d,%d), ",get<0>(v[i]),get<1>(v[i]),get<2>(v[i]));
        else printf("(%d,%d,%d)\n",get<0>(v[i]),get<1>(v[i]),get<2>(v[i]));
   }
}

int babylon(set<tuple<int,int,int>> &s) {
    vector<tuple<int,int,int>> v(s.begin(),s.end());
    vector<pair<int,int>> L(v.size(),make_pair(1,0)); 
    int maxHeight = 0;
    for(int i  = 0; i < v.size(); i++) {
        tuple<int,int,int> ti = v[i];
        L[i].second = get<2>(ti); // get height 
        for(int j = 0; j < i; j++) {
            tuple<int,int,int> tj = v[j];
            if(cmp(ti,tj) == IS_SMALLER) {
                L[i].first += L[j].first;
                L[i].second += L[j].second;
                if(L[i].second > maxHeight) maxHeight = L[i].second;
            } else if(cmp(ti,tj) == IS_LARGER) {
                L[j].first += L[i].first;
                L[j].second += L[j].second;
                if(L[i].second > maxHeight) maxHeight = L[j].second;
            }
        }
    }
    //printL(L);
    return maxHeight;
}

void addToSet(int x,int y,int z,set<tuple<int,int,int>> &s) {
    tuple<int,int,int> t1(x,y,z); s.insert(t1);
    tuple<int,int,int> t2(z,x,y); s.insert(t2);
    tuple<int,int,int> t3(y,z,x); s.insert(t3);
}


int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    int TC;
    int CN = 1;
    while(getline(cin,input)) {
        stringstream ss(input);
        ss >> TC;
        if(TC == 0) break;
        int max = 0;
        vector<int> v(3);
        set<tuple<int,int,int>> s;
        s.clear();
        for(int i = 0; i < TC; i++) {
            string input;
            getline(cin,input);
            stringstream ss(input);
            int x,y,z;
            ss >> x >> y >> z;
            addToSet(x,y,z,s);
        }
        //babylonSetTest(s);
        max = babylon(s);
        printf("Case %d: maximum height = %d\n",CN++,max);
    }
    return 0;
}
