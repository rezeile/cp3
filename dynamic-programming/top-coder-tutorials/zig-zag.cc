/* This program solves the zig zag problem from topcoder
 * whose definition can be found here:
 *
 * https://community.topcoder.com/tc?module=ProblemDetail&rd=4493&pm=1259
 *
 *
 * Author: Eliezer Abate
 * Last Updated: October 1, 2016
 */

#include <vector>
using namespace std;

int longestZigZag(vector<int> sequence) {
    if(sequence.size() == 0) return 0;
    vector<int> ithLongest(sequence.size(),1);
    for(int i = 1; i < sequence.size(); i++) {
        if(i == 1) {
            ithLongest[i] = sequence[i] == sequence[i-1] ? 1 : 2;
        } else {
            if(sequence[i] > sequence[i-1] && sequence[i-1] < sequence[i-1]  ) {
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

int main() {
    
    return 0;
}

