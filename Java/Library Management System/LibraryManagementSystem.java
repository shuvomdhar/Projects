import java.util.*;

class Library {
    Scanner sc = new Scanner(System.in);
    ArrayList<String> book = new ArrayList<>();
    ArrayList<String> iBook = new ArrayList<>();

    Library() {
        book.add("Journey To The Center of The Earth");
        book.add("To Kill a Mockingbird");
        book.add("Alice in Wonderland");
        book.add("Wings of Fire");
        book.add("French Revolution");
    }

    void addBook() {
        System.out.print("Enter the book name you want to donate to the library: ");
        String dbook = sc.nextLine();
        book.add(dbook);
    }

    void issueBook() {
        System.out.print("Enter the book name you want to issue from the library: ");
        String isbook = sc.nextLine();
        boolean ans = false;
        for (String i : book) {
            if (i.equalsIgnoreCase(isbook)) {
                ans = true;
            }
        }
        if (ans) {
            System.out.print("Enter your name: ");
            String name = sc.nextLine();
            System.out.println(isbook + " is issued to " + name);
            book.remove(isbook);
        } else {
            System.out.println(isbook + " not found");
        }
    }

    void returnBook() {
        System.out.print("Enter the book name you want to return to the library: ");
        String rtbook = sc.nextLine();
        System.out.print("Enter your name: ");
        String name = sc.nextLine();
        book.add(rtbook);
        System.out.println(name + " returned the book " + rtbook);
    }

    void showAvailableBooks() {
        System.out.println("The available books in the library are:-");
        for (String str : book) {
            System.out.println(str);
        }
    }
}

public class LibraryManagementSystem {
    public static void main(String[] args) {
        Scanner sc = new Scanner(System.in);
        Library l = new Library();
        l.showAvailableBooks();
        System.out.println(
                "What you want to do?\nType '1' for donating book(s) in the library\nType '2' for issue a book\nType '3' to return the book");
        System.out.print("Enter your choice: ");
        int choice = sc.nextInt();
        switch (choice) {
            case 1:
                l.addBook();
                l.showAvailableBooks();
                break;

            case 2:
                l.issueBook();
                l.showAvailableBooks();
                break;

            case 3:
                l.returnBook();
                l.showAvailableBooks();
                break;

            default:
                break;
        }
    }
}