import java.util.Scanner;
import java.math.BigInteger;
import java.io.File;

class Main {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        int N = sc.nextInt();
        for(int i = 0; i < N; i++) {
          String x = new StringBuilder(sc.next()).reverse().toString();
          String y = new StringBuilder(sc.next()).reverse().toString();
          BigInteger X = new BigInteger(x);
          String res = new StringBuilder((X.add(new BigInteger(y))).toString()).reverse().toString();
          BigInteger result = new BigInteger(res);
          System.out.println(result);
        }
    }
}
