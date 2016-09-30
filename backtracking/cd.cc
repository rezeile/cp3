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
void printArray(vector<int> &v);
// global variables
vi overall_best;
int limit, max_sum;

bool addTrack(int index,vi &arr,vi &best,int &sum) {
    int new_sum = sum + arr[index];
    if(index >= arr.size() || new_sum > limit) return false;
    sum += arr[index];
    best.push_back(arr[index]);
    if(sum > max_sum) {
        overall_best = best; 
        max_sum = sum;
    }
    return true;
}

void bestTracksHelper(int index,vi &input_array,vi &best,int &sum) {
    for(int i = index; i < input_array.size(); i++) {
        if(addTrack(i,input_array,best,sum)) {
            bestTracksHelper(i+1,input_array,best,sum);
            best.pop_back();
            sum -= input_array[i];
        }
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

void printArray(vector<int> &v) {
    printf("[");
    for(int i = 0; i < v.size(); i++) {
        if(i != v.size() - 1) printf("%d,",v[i]);
        else printf("%d]\n",v[i]);
    }
}


void printResult() {
    for(int i = 0; i < overall_best.size(); i++) {
        printf("%d ",overall_best[i]);
    }
    printf("sum:%d\n",max_sum);
}

int main(int argc, char *argv[]) {
    int N;
    int T;
    //freopen(argv[1],"r",stdin);
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
