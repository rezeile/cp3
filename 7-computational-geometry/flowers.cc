#include <cstdio>
#include <iostream>
#include <string>
#include <sstream>
#include <cmath>
using namespace std;

using ldouble = long double;
ldouble PI = (long double) atan(1) * 4;

void flowers(int a,int b,int c) {
  ldouble triangle_semi_perimeter = 0.5 * ((ldouble) a + b + c);
  ldouble tsp = triangle_semi_perimeter;
  ldouble triangle_area = sqrt(tsp*(tsp-a)*(tsp-b)*(tsp-c));
  ldouble small_circle_radius = triangle_area / triangle_semi_perimeter;
  ldouble roses = PI * (small_circle_radius * small_circle_radius);
  ldouble violets = triangle_area - roses;
  ldouble large_circle_radius = (ldouble) a * b * c /(4 * triangle_area);
  ldouble large_circle_area = PI * (large_circle_radius * large_circle_radius);
  ldouble sunflowers = large_circle_area - triangle_area;
  printf("%.4Lf %.4Lf %.4Lf\n",sunflowers,violets,roses);
}

int main(int argc, char *argv[]) {
    //if(argc < 2) { fprintf(stderr,"enter an input file"); return -1; }
    //freopen(argv[1],"r",stdin);
    
    string input;
    while(getline(cin,input)) {
      stringstream ss(input);
      int a,b,c;
      ss >> a; ss >> b; ss >> c;
      flowers(a,b,c);
    }
    return 0;
}
