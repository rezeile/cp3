#include <cstdio>
#include <iostream>
#include <algorithm>
#include <sstream>
#include <string>
#include <set>
#include <map>
#include <tuple>
#include <utility>
#include <iterator>
#include <vector>
using namespace std;

/**
 * Author: Eliezer Abate
 * Date: September 6 2017
 * Problem: https://uva.onlinejudge.org/external/102/10258.pdf
 * @ 360 @
 */

using score = tuple<int,int,int,char>;

struct compare {
  bool operator() (const score &lhs, const score &rhs) const {
    if (get<0>(lhs) < get<0>(rhs)) return true;
    else if (get<0>(lhs) == get<0>(rhs)) {
      if (get<1>(lhs) < get<1>(rhs)) {
        return true;
      } else if (get<1>(lhs) == get<1>(rhs)) {
        return get<3>(lhs) < get<3>(rhs);
      }
    }
    return false;
  }
};

typedef struct {
  int contestant;
  int prob_number;
  int time;
} result;

struct compare_result {
  bool operator() (const result &l, const result &r) const {
    if (l.prob_number > r.prob_number) return true;
    if (l.prob_number == r.prob_number) {
      if (l.time < r.time) {
        return true;
      } else if (l.time == r.time) {
        return l.contestant < r.contestant;
      }
    }
    return false;
  }
};

void printResult(vector<result> &v) {
  for (int i = 0; i < v.size(); i++) {
    if (v[i].contestant == 0) continue;
    int c = v[i].contestant;
    int p = v[i].prob_number;
    int t = v[i].time;
    printf("%d %d %d\n",c,p,t);
  }
}


bool isEmpty (result &r) {
  return r.contestant != 0;
}

void printScoreboard(vector<score> &scores) {
  vector<result> vec(101,{0,0,0});
  set<pair<int,int>> completed;
  for (auto &s : scores) {
    int i = get<0>(s);
    char L = get<3>(s);
    if (vec[i].contestant == 0) 
      vec[i].contestant = i;
    if (L == 'C') {
      if (completed.find({i,get<1>(s)}) != completed.end()) {
        vec[i].prob_number += 0;
        vec[i].time = get<2>(s);
      } else {
        vec[i].prob_number++;
        vec[i].time += get<2>(s);
        completed.insert(make_pair(i,get<1>(s)));
      }
    } else if (L == 'I' && completed.find({i,get<1>(s)}) != completed.end()) {
      vec[i].time += 20;
    }
  }
  vector<result> cvec;
  copy_if(vec.begin(),vec.end(),back_inserter(cvec),isEmpty);
  sort(cvec.begin(),cvec.end(),compare_result());
  printResult(cvec);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N;
    string input;
    getline(cin,input);
    stringstream ss(input);
    ss >> N;
    getline(cin,input); // first line break
      
    for (int i = 0; i < N; i++) {
      vector<score> scores;
      while (getline(cin,input)) {
        if (input.compare("") == 0) {
          break;
        }
        stringstream ss(input);
        int C, P, T;
        char result;
        ss >> C >> P >> T >> result;
        scores.push_back(make_tuple(C,P,T,result));
      }
      reverse(scores.begin(),scores.end());
      printScoreboard(scores);
      if ( i != N-1) cout << endl;
    }
    return 0;
}
