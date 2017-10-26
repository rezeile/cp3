#include <vector>
#include <cstdio>
#include <sstream>
#include <iostream>
#include <string>
#include <unordered_map>
#include <utility>
using namespace std;

using um = unordered_map<string,int>;
using vi = vector<int>;

int friend_index;

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

  int sizeOfSet(int i) {
    return setSize[findSet(i)];
  }
};

typedef struct friends {
  string a;
  string b;
} friends;

friends parseFriends(string s) {
  string delimiter = " ";
  int pos = 0; string token;
  friends fs = friends();
  while((pos = s.find(delimiter)) != string::npos) {
    token = s.substr(0,pos);
    fs.a = token;
    s.erase(0,pos + delimiter.length());
  }
  fs.b = s;;
  return fs;
}

pair<int,int> getIndices(friends &fs, um &map) {
  pair<int,int> p = pair<int,int>();
  p.first = map.find(fs.a)->second;
  p.second = map.find(fs.b)->second;
  return p;
}

void addIndexToMap(string s, um &map) {
  if (map.find(s) == map.end())
      map.insert(make_pair(s,friend_index++));
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    int N,F; scanf("%d\n",&N);
    string input;
    while(N-- > 0) {
      scanf("%d\n",&F);
      vector<friends> v;
      UnionFind UF(F*2);
      um map;
      friend_index = 0;
      while(F-- > 0) {
        getline(cin,input);
        friends fs = parseFriends(input);
        addIndexToMap(fs.a,map);
        addIndexToMap(fs.b,map);;
        pair<int,int> indices = getIndices(fs,map);
        UF.UnionSet(indices.first,indices.second);
        printf("%d\n",UF.sizeOfSet(indices.first));
      }
    }
    return 0;
}
