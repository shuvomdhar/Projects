import java.util.*;

public class NumberGuess {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();
        int num = rand.nextInt(101);
        int count = 0;
        while (true) {
            System.out.print("Enter the value within 1 and 100: ");
            int n = sc.nextInt();
            if (n < num) {
                System.out.println("Enter upper value");
                count++;
            } else if (n > num) {
                System.out.println("Enter lower value");
                count++;
            } else if (n == num) {
                count++;
                System.out.println("You hit the number " + count + "th times");
                break;
            }
        }
    }
}