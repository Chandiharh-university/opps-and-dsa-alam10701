#include <iostream>
using namespace std;

class Account {
protected:
    double balance;
public:
    Account(double bal) : balance(bal) {}
    virtual void deposit(double amount) {
        balance += amount;
    }
    virtual void withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Insufficient funds" << endl;
        }
    }
    virtual void calculateInterest() = 0; // Pure virtual function
    virtual void displayBalance() {
        cout << "Balance: " << balance << endl;
    }
};

class SavingsAccount : public Account {
private:
    double interestRate;
public:
    SavingsAccount(double bal, double rate) : Account(bal), interestRate(rate) {}
    void calculateInterest() override {
        balance += (balance * interestRate);
    }
};

class CheckingAccount : public Account {
public:
    CheckingAccount(double bal) : Account(bal) {}
    void calculateInterest() override {
        // No interest for checking account
    }
};

int main() {
    Account* accounts[2];
    accounts[0] = new SavingsAccount(1000, 0.05);
    accounts[1] = new CheckingAccount(2000);

    for (int i = 0; i < 2; ++i) {
        accounts[i]->deposit(500);
        accounts[i]->calculateInterest();
        accounts[i]->displayBalance();
        delete accounts[i];
    }

    return 0;
}
