import java.util.*;

public class RockPaperScissor {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Random rand = new Random();
        long num1 = rand.nextInt(101);
        String c_choice;
        if (num1 >= 0 && num1 < 33) {
            c_choice = "Stone";
        } else if (num1 >= 33 && num1 < 66) {
            c_choice = "Paper";
        } else {
            c_choice = "Scissor";
        }
        System.out.print("Your turn --> ");
        String u_choice = sc.next();
        if (c_choice == "Stone" && u_choice.equalsIgnoreCase("Stone")) {
            System.out.println("Match Draw");
        } else if (c_choice == "Paper" && u_choice.equalsIgnoreCase("Paper")) {
            System.out.println("Match Draw");
        } else if (c_choice == "Scissor" && u_choice.equalsIgnoreCase("Scissor")) {
            System.out.println("Match Draw");
        } else if (c_choice == "Stone" && u_choice.equalsIgnoreCase("Paper")) {
            System.out.println("Computer Won\nYou Lose!!!");
        } else if (c_choice == "Stone" && u_choice.equalsIgnoreCase("Scissor")) {
            System.out.println("Computer Won\nYou Lose!!!");
        } else if (c_choice == "Paper" && u_choice.equalsIgnoreCase("Stone")) {
            System.out.println("You Won\nComputer Lose!!!");
        } else if (c_choice == "Paper" && u_choice.equalsIgnoreCase("Scissor")) {
            System.out.println("You Won\nComputer Lose!!!");
        } else if (c_choice == "Scissor" && u_choice.equalsIgnoreCase("Stone")) {
            System.out.println("You Won\nComputer Lose!!!");
        } else if (c_choice == "Scissor" && u_choice.equalsIgnoreCase("Paper")) {
            System.out.println("Computer Won\nYou Lose!!!");
        }
    }
}