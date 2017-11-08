import java.util.Scanner;
import java.math.BigInteger;
import java.io.File;
import java.util.Arrays;
import java.util.List;
import java.util.Collections;

class Main {
    static void solve(String x, String y) {
      char[] s1 = x.toCharArray();
      char[] s2 = y.toCharArray();
      Arrays.sort(s1); Arrays.sort(s2);
      int i_0 = Character.getNumericValue(s1[s1.length-1]) + 1;
      int j_0 = Character.getNumericValue(s2[s2.length-1]) + 1;
      if (i_0 < 2) i_0 = 2;
      if (j_0 < 2) j_0 = 2;
      for(int i = i_0; i <= 36; i++) {
        for(int j = j_0; j <= 36; j++) {
          BigInteger A = new BigInteger(x,i);
          BigInteger B = new BigInteger(y,j);
          if (A.toString(10).equals(B.toString(10))) {
            printOutput(x,y,i,j);
            return;
          }
        }
      }
      printOutput(x,y,-1,-1);
    }

    static void printOutput(String x,String y,int i, int j) {
        if (i < 0) {
          System.out.println(x + " is not equal to " + y + " in any base 2..36");
        } else {
          System.out.println(x + " (base " + i + ") = " + y + " (base " + j + ")");
        }
    }

    static String numericValue(String s) {
      if (s.length() == 1) {
        s = Integer.toString(Character.getNumericValue(s.charAt(0)));
      }
      return s;
    }
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
          solve(sc.next(),sc.next());
        }
    }
}
