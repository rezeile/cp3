/* This program solves the zig zag problem from topcoder
 * whose definition can be found here:
 *
 * https://community.topcoder.com/tc?module=ProblemDetail&rd=4493&pm=1259
 *
 *
 * Author: Eliezer Abate
 * Last Updated: October 1, 2016
 */

#include "../../util/testing.h"
#include <vector>
#include <cstdio>
using namespace std;

int longestZigZag(vector<int> sequence) {
    if(sequence.size() == 0) return 0;
    vector<int> ithLongest(sequence.size(),1);
    for(int i = 1; i < sequence.size(); i++) {
        if(i == 1) {
            ithLongest[i] = sequence[i] == sequence[i-1] ? 1 : 2;
        } else {
            if(sequence[i] > sequence[i-1] && sequence[i-1] < sequence[i-2]  ) {
                ithLongest[i] = 1 + ithLongest[i-1];
            } 
            else if(sequence[i] < sequence[i-1] && sequence[i-1] > sequence[i-2]) {
                ithLongest[i] = 1 + ithLongest[i-1];
            }
            else ithLongest[i] = ithLongest[i-1];
        }
    }
    return ithLongest[sequence.size() - 1];
}

void simpleTest() {
    printf("Simple Test\n");
    vector<int> v;
    compareOutput(0,longestZigZag(v));
    vector<int> v2 = {1};
    compareOutput(1,longestZigZag(v2));
    vector<int> v3 = {1,2};
    compareOutput(2,longestZigZag(v3));
    vector<int> v4 = {1,1};
    compareOutput(1,longestZigZag(v4));

}

void mediumTests() {
    printf("Medium Test\n");
    vector<int> v = {1,7,4,9,2,5};
    compareOutput(6,longestZigZag(v));
    vector<int> v2 = {1,17,5,10,13,15,10,5,16,8};
    compareOutput(7,longestZigZag(v2));
}

int main() {
    simpleTest();
    mediumTests();
    return 0;
}

