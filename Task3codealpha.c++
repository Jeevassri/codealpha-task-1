#include <iostream>
#include <string>
#include <vector> // For storing multiple accounts (optional, for more complex systems)

class BankAccount {
private:
    std::string accountNumber;
    std::string accountHolderName;
    char accountType; // 'S' for Savings, 'C' for Checking
    double balance;

public:
    // Constructor
    BankAccount(std::string accNum, std::string name, char type, double initialDeposit) {
        accountNumber = accNum;
        accountHolderName = name;
        accountType = type;
        balance = initialDeposit;
        std::cout << "Account created successfully for " << accountHolderName << std::endl;
    }

    // Function to deposit money
    void deposit(double amount) {
        if (amount > 0) {balance += amount;
            std::cout << "Deposit successful. New balance: " << balance << std::endl;
        } else {
            std::cout << "Invalid deposit amount." << std::endl;
        }
    }

    // Function to withdraw money
    void withdraw(double amount) {
        if (amount > 0 && amount <= balance) {
            balance -= amount;
            std::cout << "Withdrawal successful. New balance: " << balance << std::endl;
        } else if (amount > balance) {
            std::cout << "Insufficient balance." << std::endl;
        } else {
            std::cout << "Invalid withdrawal amount." << std::endl;
        }
    }

    // Function to display account details
    void displayAccount() const {
        std::cout << "\n--- Account Details ---" << std::endl;
        std::cout << "Account Number: " << accountNumber << std::endl;
        std::cout << "Account Holder: " << accountHolderName << std::endl;
        std::cout << "Account Type: " << (accountType == 'S' ? "Savings" : "Checking") << std::endl;
        std::cout << "Balance: " << balance << std::endl;
        td::cout << "-----------------------" << std::endl;
    }

    // Getter for account number (useful for searching)
    std::string getAccountNumber() const {
        return accountNumber;
    }
};

int main() {
    // Example usage:
    BankAccount myAccount("123456789", "Alice Smith", 'S', 1000.0);
    myAccount.displayAccount();

    myAccount.deposit(500.0);
    myAccount.withdraw(200.0);
    myAccount.displayAccount();

    BankAccount anotherAccount("987654321", "Bob Johnson", 'C', 5000.0);
    anotherAccount.displayAccount();

    return 0;
}