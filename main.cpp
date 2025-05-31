#include <iostream>
#include <string>
using namespace std;

class BankAccount {
private:
    string name;
    int accountNumber;
    double balance;
    bool isActive;

public:
    static int nextAccountNumber;
    static constexpr double FDR_INTEREST = 0.06; // 6%
    static constexpr double DPS_INTEREST = 0.05; // 5%

    BankAccount() {
        name = "Unnamed";
        accountNumber = ++nextAccountNumber;
        balance = 0;
        isActive = false;
    }

    void createAccount(string accName, double initialDeposit) {
        name = accName;
        balance = initialDeposit;
        isActive = true;
        cout << "Account created for " << name << " with Account No: " << accountNumber << "\n";
    }

    void deposit(double amount) {
        if (!isActive) {
            cout << "Account not active.\n";
            return;
        }
        balance += amount;
        cout << "Deposited $" << amount << ". New Balance: $" << balance << "\n";
    }

    void withdraw(double amount) {
        if (!isActive) {
            cout << "Account not active.\n";
            return;
        }
        if (amount > balance) {
            cout << "Insufficient funds!\n";
            return;
        }
        balance -= amount;
        cout << "Withdrew $" << amount << ". New Balance: $" << balance << "\n";
    }

    void openFDR(double amount, int years) {
        if (amount > balance) {
            cout << "Not enough balance for FDR.\n";
            return;
        }
        double total = amount * (1 + FDR_INTEREST * years);
        balance -= amount;
        cout << "FDR of $" << amount << " opened for " << years << " years.\n";
        cout << "Will return $" << total << " after " << years << " years.\n";
    }

    void openDPS(double monthlyAmount, int months) {
        double total = monthlyAmount * months * (1 + DPS_INTEREST);
        cout << "DPS opened: Monthly = $" << monthlyAmount << " for " << months << " months.\n";
        cout << "Will return approximately $" << total << " after maturity.\n";
    }

    void showInfo() {
        if (!isActive) return;
        cout << "Name: " << name << ", Acc No: " << accountNumber << ", Balance: $" << balance << "\n";
    }
};

int BankAccount::nextAccountNumber = 1000;

int main() {
    BankAccount users[10];

    // Creating 10 user accounts
    for (int i = 0; i < 10; i++) {
        users[i].createAccount("User" + to_string(i + 1), 1000 + (i * 500)); // Initial deposit increases
    }

    cout << "\n--- Sample Transactions ---\n";
    users[0].deposit(500);
    users[1].withdraw(200);
    users[2].openFDR(1000, 2); // FDR for 2 years
    users[3].openDPS(200, 12); // DPS for 12 months

    cout << "\n--- Account Info ---\n";
    for (int i = 0; i < 10; i++) {
        users[i].showInfo();
    }

    return 0;

}
