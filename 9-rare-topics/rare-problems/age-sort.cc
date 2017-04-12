/* Counting Sort algorithm */

#include <cstdio>
#include <iostream>
#include <sstream>
#include <vector>
using namespace std;

void printResult(vector<int> &res) {
    int size = res.size();
    for (int i = 1; i < size; i++) {
        if (i != size - 1) printf("%d ",res[i]);
        else printf("%d\n",res[i]);
    }
}

void ageSort(vector<int> &vec) {
    vector<int> count(101,0); // values may range from 1-100
    
    // get count of how many occurences of each value
    for (int i = 0; i < vec.size(); i++) 
        count[vec[i]]++;

    // let each i represent the # of occurences of values less than or equal to i
    for (int i = 1; i < count.size(); i++) 
        count[i] += count[i-1];

    
    // relocate values from vec to appropriate position in new vector result
    vector<int> result(vec.size() + 1);
    for (int i = vec.size() - 1; i >= 0; i--) {
        int value = vec[i];
        result[count[value]] = value;
        count[value] -= 1;
    }

    printResult(result);
}

int main(int argc, char *argv[]) {
    // if (argc < 2) { printf("enter an input file.\n"); return -1; }
    // freopen(argv[1],"r",stdin);
    int N;
    string input;
    stringstream ss;
    while (getline(cin,input)) {
        ss.clear(); ss.str(input); ss >> N;
        if (N == 0) break;
        getline(cin,input);         
        ss.clear(); ss.str(input); 
        vector<int> v(N);
        for (int i = 0; i < N; i++) 
            ss >> v[i];
        ageSort(v);
    }
    return 0;
}
