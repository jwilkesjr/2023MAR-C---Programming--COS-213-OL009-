#include <iostream>
#include <stdexcept>
#include <vector>
#include <memory>

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

    virtual void credit(double amount) {
        balance += amount;
    }

    virtual bool debit(double amount) {
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

    virtual ~BankAccount() {}  // Virtual destructor

protected:
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

    void credit(double amount) override {
        BankAccount::credit(amount);
        BankAccount::debit(transaction_fee);
    }

    bool debit(double amount) override {
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
    std::vector<std::shared_ptr<BankAccount>> accounts;

    accounts.push_back(std::make_shared<BankAccount>(1000));
    accounts.push_back(std::make_shared<Savings>(2000, 0.03));
    accounts.push_back(std::make_shared<Checking>(3000, 2.0));

    for (auto& account : accounts) {
        double debit_amount, credit_amount;
        std::cout << "\nCurrent balance: " << account->getBalance() << std::endl;

        std::cout << "Enter amount to debit: ";
        std::cin >> debit_amount;
        account->debit(debit_amount);

        std::cout << "Enter amount to credit: ";
        std::cin >> credit_amount;
        account->credit(credit_amount);

        auto savingsAccount = dynamic_cast<Savings*>(account.get());
        if (savingsAccount) {
            double interest = savingsAccount->calculateInterest();
            savingsAccount->credit(interest);
            std::cout << "Interest added to Savings Account." << std::endl;
        }

        std::cout << "Updated balance: " << account->getBalance() << std::endl;
    }

    return 0;
}