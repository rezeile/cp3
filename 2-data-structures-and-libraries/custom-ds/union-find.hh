#ifndef _UNION_FIND_HH
#define _UNION_FIND_HH

#include <vector>
using namespace std;

using vi = vector<int>;

class UnionFind {
  private:
    int numSets;
    vi rank, p, setSize;

  public:
  UnionFind(int N) {
    numSets = N;
    p.assign(N,0); rank.assign(N,0);
    setSize.assign(N,1);
    for(int i = 0; i < N; i++) p[i] = i;
  }

  int findSet(int i) {
    return p[i] == i ? i : (p[i] = findSet(p[i]));
  }
  
  bool isSameSet(int i, int j) {
    return findSet(i) == findSet(j);  
  }

  void UnionSet(int i, int j) {
    if (!isSameSet(i, j)) {
      numSets--;
      int x = findSet(i);
      int y = findSet(j);
      if (rank[x] > rank[y]) {
        p[y] = x;
        setSize[x] += setSize[y];
      } else {
        p[x] = y;
        setSize[y] += setSize[x];
        if (rank[x] == rank[y]) rank[y]++;
      }
    }
  }

  int numOfDisjointSets() {
    return numSets;
  }

  int sizeOfSize(int i) {
    return setSize[p[i]];
  }
};

#endif
