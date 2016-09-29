#include <vector>
#include <cassert>
#include <cstdio>
#include <iostream>
using namespace std;

typedef vector<int> vi;

// forward declaration
void bestTracks(vi &input_array);
void bestTracksHelper(int index,vi &input_array,vi &best, int &sum);
bool addTrack(int index,vi &arr,vi &best,int &sum);
void printResult();

// global variables
vi overall_best;
int limit, max_sum;

bool addTrack(int index,vi &arr,vi &best,int &sum) {
    //assert(index < arr.size());
    int new_sum = sum + arr[index];
    if(index >= arr.size() || new_sum > limit) return false;
    return true;
}

void bestTracksHelper(int index,vi &input_array,vi &best,int &sum) {
    if(addTrack(index,input_array,best,sum)) {
        sum += input_array[index];
        best.push_back(input_array[index]);
        if(sum > max_sum) {
            overall_best = best; 
            max_sum = sum;
        }
        bestTracksHelper(index + 1,input_array,best,sum);
    } else {
        
    }
}

void bestTracks(vi &input_array) {
    for(int i = 0; i < input_array.size(); i++) {
        vi cur_best;
        int sum = 0;
        bestTracksHelper(i,input_array,cur_best,sum);
    }
    printResult();
}

void printResult() {
    for(int i = 0; i < overall_best.size(); i++) {
        printf("%d ",overall_best[i]);
    }
    printf("sum:%d\n",max_sum);
}

int main(int argc, char *argv[]) {
    if(argc < 2) {
        fprintf(stderr,"enter an input file");
        return -1;
    }
    int N;
    int T;
    freopen(argv[1],"r",stdin);
    while(true) {
        if(!(cin >> N)) break;
        if(!(cin >> T)) break;
        limit = N;
        max_sum = 0;
        vi track_list;
        overall_best.clear();
        int track;
        for(int i = 0; i < T; i++) {
            cin >> track;
            track_list.push_back(track);
        }
        bestTracks(track_list);
    }
    return 0;
}
