#include <vector>
#include <cassert>
using namespace std;

typedef vector<int> vi;

// forward declaration
void bestTracks(vi &input_array);
void bestTracksHelper(int index,vi &input_array,vi &best, int &sum);
bool addTrack(int index,vi &arr,vi &best,int &sum);

// global variables
vi overall_best;
int limit, max_sum = 0;

bool addTrack(int index,vi &arr,vi &best,int &sum) {
    //assert(index < arr.size());
    int new_sum = sum + arr[index];
    if(index >= arr.size() || sum > limit) return false;
    sum = new_sum;
    best.push_back(arr[index]);
    if(sum > max_sum) overall_best = best; 
    return true;
}


void bestTracksHelper(int index,vi &input_array,vi &best,int &sum) {
    for(int i = index; i < input_array.size(); i++) {
        if(addTrack(i,input_array,best,sum)) 
            bestTracksHelper(i + 1,input_array,best,sum);
        else i++;
    }
}

void bestTracks(vi &input_array) {
    for(int i = 0; i < input_array.size(); i++) {
        vi cur_best;
        int sum = 0;
        bestTracksHelper(i,input_array,cur_best,sum);
    }
}

int main() {
    return 0;
}
