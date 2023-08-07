#include <iostream>
#include <stdexcept>

class BankAccount {
public:
    BankAccount(double initial_balance) {
        if (initial_balance >= 0.0) {
            balance = initial_balance;
        }
        else {
            balance = 0.0;
            std::cerr << "Error: Initial balance was invalid." << std::endl;
        }
    }

    void credit(double amount) {
        balance += amount;
    }

    bool debit(double amount) {
        if (amount <= balance) {
            balance -= amount;
            return true;
        }
        else {
            std::cerr << "The balance is less than the debit amount." << std::endl;
            return false;
        }
    }

    double getBalance() const {
        return balance;
    }

private:
    double balance;
};

class Savings : public BankAccount {
public:
    Savings(double initial_balance, double interest_rate)
        : BankAccount(initial_balance), interest_rate(interest_rate) {}

    double calculateInterest() const {
        return getBalance() * interest_rate;
    }

private:
    double interest_rate;
};

class Checking : public BankAccount {
public:
    Checking(double initial_balance, double transaction_fee)
        : BankAccount(initial_balance), transaction_fee(transaction_fee) {}

    void credit(double amount) {
        BankAccount::credit(amount);
        BankAccount::debit(transaction_fee);
    }

    bool debit(double amount) {
        if (BankAccount::debit(amount)) {
            BankAccount::debit(transaction_fee);
            return true;
        }
        return false;
    }

private:
    double transaction_fee;
};

int main() {
    BankAccount account1(1000);
    Savings account2(2000, 0.03);
    Checking account3(3000, 2.0);

    std::cout << "Initial balances:" << std::endl;
    std::cout << "Account1: " << account1.getBalance() << std::endl;
    std::cout << "Account2: " << account2.getBalance() << std::endl;
    std::cout << "Account3: " << account3.getBalance() << std::endl;

    account1.debit(100);
    account2.debit(100);
    account3.debit(100);

    std::cout << "\nBalances after debiting $100:" << std::endl;
    std::cout << "Account1: " << account1.getBalance() << std::endl;
    std::cout << "Account2: " << account2.getBalance() << std::endl;
    std::cout << "Account3: " << account3.getBalance() << std::endl;

    account1.credit(200);
    account2.credit(200);
    account3.credit(200);

    std::cout << "\nBalances after crediting $200:" << std::endl;
    std::cout << "Account1: " << account1.getBalance() << std::endl;
    std::cout << "Account2: " << account2.getBalance() << std::endl;
    std::cout << "Account3: " << account3.getBalance() << std::endl;

    double interest = account2.calculateInterest();
    account2.credit(interest);

    std::cout << "\nSavings account balance after adding interest: ";
    std::cout << account2.getBalance() << std::endl;

    return 0;
}