#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>

/* Day 5 (12/10/2016) Comments
 * -----------------------------------
 * Elaborated further on the construction of a recursive formula based
 * on the insight from yesterday. This formula is by nature top-down
 * and will be further massaged later today.
 */

/* Day 4 (12/9/2016) Comments
 * -----------------------------------
 * Used the insight from yesterday to try to derive a recursive structure
 * to the problem. New insight is to try to use two different lists: one 
 * that will keep track of the longest sequence "including" the ith 
 * digit and one the longest "without" it.
 */

/* Day 3 (12/8/2016) Comments
 * -----------------------------------
 * The insight from yesterday allowed us to see that we can decompose the 
 * problem into a modified LIS and LDS problem but the resulting problem
 * would need to perform a LIS/LDS for each of the input values increasing
 * the run time to O(n^2lgn), which is not fast enough for our problem. 
 * An alternative approach was discovered with about 5 minutes left which 
 * we will explore tomorrow and that involves an approach similar 
 * to the Longest Common Subsequence problem where a solution was derived
 * from working backwards.
 */

/* Day 2 (12/7/2016) Comments
 * -----------------------------------
 * Not much has been made in the way actually coding up a solution 
 * to this problem. I do feel like some progress has been made
 * in our approach to the problem. The interesting approach has been
 * considered today and that is to think the problem through
 * the perspective of an element at a particular index i, considering,
 * exactly which elements at indices (i+1) through n will "sandwhich"
 * it.More thought will be given to this tomorrow. 
 */

/* Day 1 (12/6/2016) Comments
 * -----------------------------------
 * Played with the problem and understood it but not much progress
 * in the way of discovering an insight that will lead to a 
 * solution.
 */

using namespace std;

int helper(vector<int> &L,vector<int> &trains,int i,int front,int back) {
    if(i >= trains.size()) return 0;
    if(i == (trains.size()-1)) {
        return (trains[i] > front || trains[i] < back) ? 1 : 0;
    }
    int eligible = 0;
    int old_front = front, old_back = back;
    if(trains[i] > front) { front = trains[i]; eligible = 1; }
    else if(trains[i] < back) { back = trains[i]; eligible = 1; }
    return max(eligible + helper(L,trains,i+1,front,back),helper(L,trains,i+1,old_front,old_back)); 
}

void trainSort(vector<int> &trains) {
    // L[i,n] holds the size of the longest train-sorted sequence
    // after processing inputs trains[i,n]
    vector<int> L(trains.size());                     
    cout << helper(L,trains,0,-1,-1) << endl;
}

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int N;
        cin >> N;
        vector<int> trains(N);
        for(int j = 0; j < N; j++) {
            cin >> trains[j];
        }
        trainSort(trains); 
    }
    return 0;
}