import java.util.Scanner;
import java.math.BigInteger;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        while (sc.hasNext()) {
          String s = sc.next();
          if (s.equals("0")) break;
          BigInteger i = new BigInteger(s);
          if (i.compareTo(BigInteger.valueOf(10)) == -1)
            System.out.println("0");
          else {
            BigInteger q = i.divide(BigInteger.valueOf(10));
            BigInteger r = i.mod(BigInteger.valueOf(10));
            BigInteger fac = r.multiply(BigInteger.valueOf(5));
            BigInteger nvalue = q.subtract(fac);
            BigInteger m = nvalue.mod(BigInteger.valueOf(17));
            if (m.equals(BigInteger.ZERO)) {
              System.out.println("1");
            } else {
              System.out.println("0");
            }
          }
        }
    }
}
