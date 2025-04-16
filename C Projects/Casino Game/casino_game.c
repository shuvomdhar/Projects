#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void playGame(int *balance) {
    int betAmount, guessedNumber, winningNumber;
    
    printf("\nEnter your bet amount: ");
    scanf("%d", &betAmount);
    
    if (betAmount > *balance || betAmount <= 0) {
        printf("Invalid bet amount! You have $%d in your balance.\n", *balance);
        return;
    }
    
    printf("Guess a number between 1 and 10: ");
    scanf("%d", &guessedNumber);
    
    if (guessedNumber < 1 || guessedNumber > 10) {
        printf("Invalid number! Please choose between 1 and 10.\n");
        return;
    }
    
    srand(time(0));
    winningNumber = (rand() % 10) + 1;
    
    printf("Winning number is: %d\n", winningNumber);
    
    if (guessedNumber == winningNumber) {
        printf("Congratulations! You won $%d!\n", betAmount * 2);
        *balance += betAmount * 2;
    } else {
        printf("You lost $%d. Better luck next time!\n", betAmount);
        *balance -= betAmount;
    }
}

int main() {
    int balance;
    int choice;
    
    printf("Enter your starting balance: ");
    scanf("%d", &balance);
    
    if (balance <= 0) {
        printf("Invalid balance! You must start with a positive amount.\n");
        return 1;
    }
    
    do {
        printf("\nCasino Game Menu\n");
        printf("1. Play Game\n");
        printf("2. Check Balance\n");
        printf("3. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);
        
        switch (choice) {
            case 1:
                playGame(&balance);
                break;
            case 2:
                printf("Your current balance is: $%d\n", balance);
                break;
            case 3:
                printf("Exiting the casino. You leave with $%d. Goodbye!\n", balance);
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
        
        if (balance <= 0) {
            printf("You have run out of money! Game over.\n");
            break;
        }
    } while (choice != 3);
    
    return 0;
}
