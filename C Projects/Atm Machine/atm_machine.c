#include <stdio.h>

float balance = 1000.0; // Initial balance

void checkBalance() {
    printf("\nYour current balance is: $%.2f\n", balance);
}

void deposit() {
    float amount;
    printf("\nEnter amount to deposit: ");
    scanf("%f", &amount);
    if (amount > 0) {
        balance += amount;
        printf("$%.2f deposited successfully!\n", amount);
    } else {
        printf("Invalid deposit amount!\n");
    }
}

void withdraw() {
    float amount;
    printf("\nEnter amount to withdraw: ");
    scanf("%f", &amount);
    if (amount > 0 && amount <= balance) {
        balance -= amount;
        printf("$%.2f withdrawn successfully!\n", amount);
    } else if (amount > balance) {
        printf("Insufficient balance!\n");
    } else {
        printf("Invalid withdrawal amount!\n");
    }
}

int main() {
    int choice;
    do {
        printf("\nATM Machine\n");
        printf("1. Check Balance\n");
        printf("2. Deposit Money\n");
        printf("3. Withdraw Money\n");
        printf("4. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                checkBalance();
                break;
            case 2:
                deposit();
                break;
            case 3:
                withdraw();
                break;
            case 4:
                printf("Exiting ATM. Thank you!\n");
                break;
            default:
                printf("Invalid choice! Please try again.\n");
        }
    } while (choice != 4);
    
    return 0;
}
