import java.util.Scanner;
import java.math.BigInteger;
import java.io.File;

class Main {
    static String EMIRP = "emirp";
    static String NPRIME = "not prime";
    static String PRIME = "prime";

    static boolean isPrime(int N) {
      return BigInteger.valueOf(N).isProbablePrime(1);
    }

    static void genOutput(int N,String type) {
      System.out.println(Integer.toString(N) + " is " + type + ".");
    }

    public static void main(String[] args) {
      Scanner sc = new Scanner(System.in);
      while (sc.hasNext()) {
          int N = sc.nextInt();
          if (!isPrime(N)) {
            genOutput(N,NPRIME);
          } else {
            String s = Integer.toString(N);
            String r = new StringBuilder(s).reverse().toString();
            if (!s.equals(r) && (isPrime(Integer.parseInt(s)) &&
                                 isPrime(Integer.parseInt(r)))) {
              genOutput(N,EMIRP);
            } else {
              genOutput(N,PRIME);
            }
          }
      }
    }
}
