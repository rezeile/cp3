#include <cstdio>
using namespace std;

int counter = 0;

int main(int argc, char *argv[]) {
  if(argc < 2) { fprintf(stderr,"enter an input file\n"); return -1; }
  freopen(argv[1],"r",stdin);
  return 0;
}
