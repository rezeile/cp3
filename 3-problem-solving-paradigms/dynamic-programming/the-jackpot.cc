/* UVa 10684: The jackpot
 * 
 * Author: Eliezer Abate
 * Last Updated: Jan 1 2017
 */

#include <vector>
#include <cmath>
#include <iostream>
#include <cstdio>
#include <string>
using namespace std;

int maxWinningStreak(vector<int> &arr) {
    int running_sum = 0, mws = 0;
    for(int i = 0; i < arr.size(); i++) {
        if(running_sum + arr[i] >= 0) {
            running_sum += arr[i];
            mws = max(mws,running_sum);
        } else running_sum = 0;
    }
    return mws;
}

void printArray(vector<int> v) {
    for(int i = 0; i < v.size(); i++) {
        if(i != v.size() - 1) cout << v[i] << ",";
        else cout << v[i] << endl;
    }
}

int main(int argc, char *argv[]) {
    /*if(argc < 2) {
        cerr << "enter an input file." << endl; return -1;
    }*/
    // obtain input
    //freopen(argv[1],"r",stdin);
    int N;
    while(true) {
        cin >> N;
        if(N == 0) break;
        vector<int> arr;
        int val;
        for(int i = 0; i < N; i++) {
            cin >> val;
            arr.push_back(val);
        }
        //printArray(arr);
        int mws = maxWinningStreak(arr);
        string s = mws > 0 ? "The maximum winning streak is " + to_string(mws) + "." : "Losing streak.";
        cout << s << endl; 
    }
    return 0;
}
