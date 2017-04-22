#include <cstdio>
#include <map>
#include <utility>
#include <iterator>
#include <string>
#include <iostream>
using namespace std;

void hardwood(map<string,int> &m,int total) {
    map<string,int>::iterator it;
    for(it = m.begin(); it != m.end(); it++) {
        int count = it->second;
        double freq = ((double) count  / total) * 100;
        printf("%s %.4f\n",it->first.c_str(),freq);
    }
}

int main(int argc, char *argv[]) {
    //freopen("input/hardwood","r",stdin);
    //freopen("output/hardwood","w",stdout);
    
    int N;
    scanf("%d\n",&N);
    for(int i = 0; i < N; i++) {
        map<string,int> m;
        int total = 0;
        string tree;
        while(getline(cin,tree)){
            if(tree == "") break;
            total++;
            map<string,int>::iterator search;
            if((search = m.find(tree)) == m.end()) {
                m.insert(make_pair(tree,1));
            }
            else search->second++;
        }
        hardwood(m,total);
        if(i != N-1) printf("\n");
    }
    return 0;
}
