/*
 * This program prints out all subsets of a 
 * set. Via Cantor's theorem we know that an
 * array of size n has 2^n subsets.
 *
 * Author: Eliezer Abate
 * Last Updated: September 29, 2016
 */
 #include <cstdio>
 #include <vector>
 #include <iostream>
 using namespace std;

 typedef vector<vector<int>> vii;

 vector<vector<int>> subsets(vector<int> v) {
    if(v.size() == 0) {
        vector<int> v;
        vii res;
        res.push_back(v);
        return res;
    }
    int val = v[v.size() - 1];
    vector<int> v_rest(v.begin(),v.end() - 1);
    vii ssets = subsets(v_rest);
    vii result(ssets);
    for(int j = 0; j < ssets.size(); j++) {
        vector<int> vi = ssets[j];
        vector<int> new_vi(vi);
        new_vi.push_back(val);
        result.push_back(new_vi);
    }
    return result;
 }
 
 void printSingleVector(vector<int> &v) {
    printf("[");
    for(int i = 0; i < v.size(); i++) {
        if(i != v.size() - 1) printf("%d,",v[i]);
        else printf("%d",v[i]);
    }
    printf("]");
 }

 void printSetOfVectors(vii &vectors) {
    printf("[ ");
    for(int i = 0; i < vectors.size(); i++) {
        printSingleVector(vectors[i]);
        if(i != vectors.size() - 1) printf(",");
        else printf(" ]\n");
    }
 }
 
 int main() {
    vector<int> v = {1,2,3};
    vii ss = subsets(v);
    printSetOfVectors(ss);
    return 0;
 }
