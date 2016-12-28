/* 
 * Author: Eliezer Abate
 */

#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <vector>
#include <algorithm>
#include <utility>

/* Day 16 (12/27/2016) Comments
 * -----------------------------------
 * I found a solution to this problem not of my own, 
 * but by using the hints given in the CP3 text book.
 * I have determined that to be able to come up with 
 * more insights :
 */

/* Day 15 (12/20/2016) Comments
 * -----------------------------------
 * The folllowing input {2 7 0 4 1 5 8 3 6}
 * should generate an output of 5 but I can't 
 * even visualize it yet. (Udebug resource used.)
 */

/* Day 14 (12/19/2016) Comments
 * -----------------------------------
 * Implemented the suggested solution from yesterdays comments
 * and now its passing all the tests that were previously 
 * failing and atleast those appear to be correct solutions.
 */

/* Day 13 (12/18/2016) Comments
 * -----------------------------------
 * I have refined the algorithm from about five days ago
 * that involved the usage of the following data structure:
 *
 * vector<pair<pair<int,int>,pair<int,int>>> and I will look 
 * into coding it on paper first tomorrow and then implementing
 * the algorithm, and finally testing on special inputs.
 *
 */

/* Day 12 (12/17/2016) Comments
 * -----------------------------------
 * Trying to really pin down where my algorithm breaks.
 *
 */


/* Day 11 (12/16/2016) Comments
 * -----------------------------------
 * Not much progress in the way of coding and finding a solution. Not
 * much progress in even devising a correct algorithmic solution that
 * should work in all instances. Will spend 20 extra minutes working 
 * through examples and then if that doesn't work, I will have to abandon 
 * the vector<pair<int,int>> approach and try something new.
 */

/* Day 10 (12/15/2016) Comments
 * -----------------------------------
 * I have devised a somewhat convoluted algorithm that may or 
 * may not work out. But I'm really having a hard time with 
 * constructing it, and thus I'll need to reexamine it again 
 * tomorrow.
 */

/* Day 9 (12/14/2016) Comments
 * -----------------------------------
 * The algorithm is not quite correct. There are now
 * three simple test cases which result in an incorrect
 * output: {1,2,3}, {3,1,5}, and {5,2,3,4,6}. We will look
 * into these tomorrow.
 */

/* Day 8 (12/13/2016) Comments
 * -----------------------------------
 * Keep a pair of vectors and double for loop
 * keeping track of the longest that can be 
 * placed at front and the longest that can be placed in 
 * the back. Coded up a solution O(n^2). Will need to 
 * rigorously test later on.
 */


/* Day 7 (12/12/2016) Comments
 * -----------------------------------
 * Seem to have a reasonably "correct" but grossly 
 * inefficient solution. Since I know that the type of algorithm
 * I need needs to be probably O(n^2), I am using this insight 
 * along with the nature of the recursive solution to see if I can
 * generate a DP algorithm. 
 *
 * What seems reasonable to me at the moment is a nested for 
 * loop structure of the following type:
 *
 *      for(int i = N; i >= 0; i--)
 *          for(int j = 0; j < i; j++) 
 *
 * More exploration will follow tomorrow. 
 *
 */

/* Day 6 (12/11/2016) Comments
 * -----------------------------------
 * Constructed basic recursive solution to this problem.
 * Code starts at line 61.
 */

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

void printTrains(vector<int> &trains) {
    for(int i = 0; i < trains.size(); i++) {
        printf("%d\n",trains[i]);
    }
}

int helper(vector<int> &L,vector<int> &trains,int i,int front,int back) {
    //printf("i = %d, trains[i] = %d, w_f = %d, w_b = %d\n",i,trains[i],front,back);
    if(i >= trains.size()) return 0;
    if(i == (trains.size()-1)) {
        return (trains[i] > front || trains[i] < back) ? 1 : 0;
    }
    int eligible = 0;
    int old_front = front, old_back = back;
    if(front == -1 && back == -1) { front = back = trains[i]; eligible = 1;}
    else if(trains[i] > front) { front = trains[i]; eligible = 1; }
    else if(trains[i] < back) { back = trains[i]; eligible = 1; }
    return max(eligible + helper(L,trains,i+1,front,back),helper(L,trains,i+1,old_front,old_back)); 
}

void trainSort(vector<int> &trains) {
    vector<int> L(trains.size());                     
    cout << helper(L,trains,0,-1,-1) << endl;
}

void initializePairs(vector<pair<pair<int,int>,pair<int,int>>> &P) {
   for(int i = 0; i < P.size(); i++) {
        P[i].first.first = P[i].second.first = 1;
        P[i].first.second = P[i].second.second = i;
    }
}

void trainSortII(vector<int> &trains) {
    if(trains.size() == 0) {printf("%d\n",0);return;}
    int max = 1;
    vector<pair<pair<int,int>,pair<int,int>>> P(trains.size());
    initializePairs(P);     
    for(int i = 0; i < trains.size(); i++) {
        for(int j = 0; j < i; j++) {
            // case I: trains[i] > trains[j]
            if(trains[i] > trains[j]) {
                int front_new_length = P[j].first.first + 1;
                if(front_new_length > max) max = front_new_length;
                int back = P[j].first.second;

                if(P[i].first.first < front_new_length) {
                    P[i].first.first = front_new_length;
                    P[i].first.second = back;
                }
                if(front_new_length > P[back].second.first) {
                    P[back].second.first = front_new_length;
                    P[back].second.second = i;
                }
            } else { // case II: trains[i] < trains[j]
                int back_new_length = P[j].second.first + 1;
                if(back_new_length > max) max = back_new_length;
                int front = P[j].second.second;

                if(P[i].second.first < back_new_length) {
                    P[i].second.first = back_new_length;
                    P[i].second.second = front;
                }
                if(back_new_length > P[front].first.first) {
                    P[front].first.first = back_new_length;
                    P[front].first.second = i;
                }
            }
        }
    }
    printf("%d\n",max);
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
        trainSortII(trains); 
    }
    return 0;
}
