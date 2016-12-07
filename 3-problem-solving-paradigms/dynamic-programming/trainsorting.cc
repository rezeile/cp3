#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>

/* Day 1 (12/6/2016) Comments
 * -----------------------------------
 * Played with the problem and understood it but not much progress
 * in the way of discovering an insight that will lead to a 
 * solution.
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

using namespace std;

int main(int argc, char *argv[]) {
    if(argc < 2) { cerr << "enter an input file"; return -1; }
    freopen(argv[1],"r",stdin);
    string input;
    int T;
    cin >> T;
    for(int i = 0; i < T; i++) {
        int N;
        cin >> N;
        // obtain weight values for the train
    }
    return 0;
}
