#include <stdio.h>
#include <string.h>

void openAccount();
void checkbalance();
void deposit();
void withdraw();
int verifyPin();

float balance = 0.0;
int accountCreated = 0;
int pinCode = 0;

int main() {
    int choice;

    // This will allow us to choose what to do.
    do {
        printf("\nATM Menu:\n");
        printf("1. Open Account\n");
        printf("2. Check balance\n");
        printf("3. Deposit\n");
        printf("4. Withdraw\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice); 

        switch(choice) {
            case 1:
                openAccount();
                break;
            case 2:
                checkbalance();
                break;
            case 3:
                deposit();
                break;
            case 4:
                withdraw();
                break;
            case 5:
                printf("Thank you for using the ATM. Goodbye!\n");
                break;
            default:
                printf("Invalid choice. Please try again.\n");
        }
    } while(choice != 5);

    return 0;
}

void openAccount() {
    if (accountCreated) {
        printf("Account already exists. Your balance is: %.2f\n", balance);
    } else {
        char name[50];
        printf("Enter your name: ");
        scanf(" %[^\n]s", name);

        char fathername[50];
        printf("Enter your father's name: ");
        scanf(" %[^\n]s", fathername);

        int age;
        printf("Enter your age: ");
        scanf("%d", &age);

        printf("Set your PIN code (4 digits): ");
        scanf("%d", &pinCode);
        
        float initialDeposit;
        printf("Enter initial deposit amount: ");
        scanf("%f", &initialDeposit);
        if (initialDeposit > 0) {
            balance = initialDeposit;
            accountCreated = 1;
            printf("Thanks for visiting Bank of UPES\n");
            printf("Account holder name: %s\n", name);
            printf("Account holder father's name: %s\n", fathername);
            printf("Age of holder: %d\n", age);
            printf("Initial balance: %.2f\n", balance);
        } else {
            printf("Invalid amount. Please enter a positive amount.\n");
        }
    }
}

// Function to verify the PIN code
int verifyPin() {
    int inputPin;
    printf("Enter your pincode: ");
    scanf("%d", &inputPin);
    if (inputPin == pinCode) {
        return 1;
    } else {
        printf("Incorrect pin code.\n");
        return 0;
    }
}

// For checking the balance of the account.
void checkbalance() {
    if (accountCreated) {
        if (verifyPin()) {
            printf("Your balance is: %.2f\n", balance);
        }
    } else {
        printf("No account exists. Please open an account first.\n");
    }
}

// The below code is written for the process of depositing money.
void deposit() {
    if (accountCreated) {
        if (verifyPin()) {
            float amount;
            printf("Enter the amount to deposit: ");
            scanf("%f", &amount);
            if (amount > 0) {
                balance += amount;
                printf("Successfully deposited %.2f. Your new balance is %.2f\n", amount, balance);
            } else {
                printf("Invalid amount. Please enter a positive amount.\n");
            }
        }
    } else {
        printf("No account exists. Please open an account first.\n");
    }
}

// The below code is written for the process of withdrawing money.
void withdraw() {
    if (accountCreated) {
        if (verifyPin()) {
            float amount;
            printf("Enter the amount to withdraw: ");
            scanf("%f", &amount);
            if (amount > 0 && amount <= balance) {
                balance -= amount;
                printf("Successfully withdrew %.2f. Your new balance is %.2f\n", amount, balance);
            } else if (amount > balance) {
                printf("Insufficient funds. Your balance is %.2f\n", balance);
            } else {
                printf("Invalid amount. Please enter a positive number.\n");
            }
        }
    } else {
        printf("No account exists. Please open an account first.\n");
    }
}
