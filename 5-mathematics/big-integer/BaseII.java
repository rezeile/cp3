import java.util.Scanner;
import java.math.BigInteger;
import java.io.File;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
          String num = sc.next();
          int from = Integer.parseInt(sc.next());
          int to = Integer.parseInt(sc.next());
          BigInteger s = new BigInteger(num,from);
          String res = s.toString(to).toUpperCase();
          if (res.length() > 7)
            System.out.println(String.format("%7s","ERROR"));
          else {
            int pad = res.length() - 7;
            res = String.format("%7s",res);
            System.out.println(res);
          }
        }
    }
}
