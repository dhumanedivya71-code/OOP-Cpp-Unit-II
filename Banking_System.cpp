#include <iostream>
#include <string>
#include <vector>
#include <memory>
using namespace std;

// Base Class
class Account {
protected:
    int accountNumber;
    string holderName;
    double balance;

public:
    Account(int accNo, string name, double bal)
        : accountNumber(accNo), holderName(name), balance(bal) {}

    // Deposit money
    void deposit(double amount) {
        if (amount > 0) {
            balance += amount;
            cout << "Rs. " << amount << " deposited successfully."
                 << endl;
        } else {
            cout << "Invalid deposit amount." << endl;
        }
    }

    // Withdraw money
    virtual void withdraw(double amount) {
        if (amount <= 0) {
            cout << "Invalid withdrawal amount." << endl;
        }
        else if (amount > balance) {
            cout << "Insufficient balance." << endl;
        }
        else {
            balance -= amount;
            cout << "Rs. " << amount
                 << " withdrawn successfully." << endl;
        }
    }

    // Pure virtual function
    virtual double calculateInterest() const = 0;

    // Display account details
    virtual void display() const {
        cout << "Account Number: " << accountNumber << endl;
        cout << "Holder Name: " << holderName << endl;
        cout << "Balance: Rs. " << balance << endl;
    }

    virtual ~Account() = default;
};


// Derived Class 1: Savings Account
class SavingsAccount : public Account {
private:
    double interestRate;

public:
    SavingsAccount(int accNo, string name, double bal,
                   double rate)
        : Account(accNo, name, bal),
          interestRate(rate) {}

    double calculateInterest() const override {
        return balance * interestRate / 100;
    }

    void display() const override {
        cout << "\n--- Savings Account ---" << endl;
        Account::display();

        cout << "Interest Rate: "
             << interestRate << "%" << endl;

        cout << "Calculated Interest: Rs. "
             << calculateInterest() << endl;
    }
};


// Derived Class 2: Current Account
class CurrentAccount : public Account {
private:
    double interestRate;

public:
    CurrentAccount(int accNo, string name, double bal,
                   double rate)
        : Account(accNo, name, bal),
          interestRate(rate) {}

    double calculateInterest() const override {
        return balance * interestRate / 100;
    }

    void display() const override {
        cout << "\n--- Current Account ---" << endl;
        Account::display();

        cout << "Interest Rate: "
             << interestRate << "%" << endl;

        cout << "Calculated Interest: Rs. "
             << calculateInterest() << endl;
    }
};


// Derived Class 3: Fixed Deposit Account
class FixedDepositAccount : public Account {
private:
    double interestRate;
    int duration;

public:
    FixedDepositAccount(int accNo, string name, double bal,
                        double rate, int years)
        : Account(accNo, name, bal),
          interestRate(rate),
          duration(years) {}

    double calculateInterest() const override {
        return balance * interestRate * duration / 100;
    }

    void withdraw(double amount) override {
        cout << "Withdrawal from Fixed Deposit Account "
             << "is not allowed before maturity." << endl;
    }

    void display() const override {
        cout << "\n--- Fixed Deposit Account ---" << endl;
        Account::display();

        cout << "Interest Rate: "
             << interestRate << "%" << endl;

        cout << "Duration: "
             << duration << " years" << endl;

        cout << "Calculated Interest: Rs. "
             << calculateInterest() << endl;
    }
};


// Main Function
int main() {

    vector<unique_ptr<Account>> accounts;

    accounts.push_back(
        make_unique<SavingsAccount>(
            1001,
            "Rahul",
            50000,
            4.0
        )
    );

    accounts.push_back(
        make_unique<CurrentAccount>(
            1002,
            "Priya",
            75000,
            2.0
        )
    );

    accounts.push_back(
        make_unique<FixedDepositAccount>(
            1003,
            "Amit",
            100000,
            7.0,
            3
        )
    );

    cout << "====================================" << endl;
    cout << "      BANKING SYSTEM" << endl;
    cout << "====================================" << endl;


    for (const auto& account : accounts) {
        account->display();
    }


    cout << "\n=== Deposit Operation ===" << endl;
    accounts[0]->deposit(5000);
    cout << "\n=== Withdrawal Operation ===" << endl;
    accounts[1]->withdraw(10000);


    cout << "\n=== Fixed Deposit Withdrawal ===" << endl;
    accounts[2]->withdraw(5000);

    cout << "\n=== Updated Account Details ===" << endl;

    for (const auto& account : accounts) {
        account->display();
    }

    return 0;
}
