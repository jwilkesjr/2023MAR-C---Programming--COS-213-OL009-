#include <iostream>
#include <iomanip>

class SavingsAccount {
private:
    double savingsBalance;
    static double annualInterestRate;

public:
    SavingsAccount(double initialBalance) {
        savingsBalance = initialBalance;
    }

    void calculateMonthlyInterest() {
        double monthlyInterest = (savingsBalance * annualInterestRate) / 1200;
        savingsBalance += monthlyInterest;
    }

    static void modifyInterestRate(double newInterestRate) {
        annualInterestRate = newInterestRate;
    }

    double getBalance() const {
        return savingsBalance;
    }
};

double SavingsAccount::annualInterestRate = 0.0;

int main() {
    double balance1, balance2, annualInterest;
    char changeInterest;

    std::cout << "Please enter the savings balance of account 1: ";
    std::cin >> balance1;
    std::cout << "Please enter the savings balance of account 2: ";
    std::cin >> balance2;

    SavingsAccount account1(balance1);
    SavingsAccount account2(balance2);

    do {
        std::cout << "\nPlease enter the annual interest rate: ";
        std::cin >> annualInterest;

        SavingsAccount::modifyInterestRate(annualInterest);

        account1.calculateMonthlyInterest();
        account2.calculateMonthlyInterest();

        std::cout << std::fixed << std::setprecision(2);
        std::cout << "\nThe interest for account 1 would be $" << (account1.getBalance() - balance1)
            << " and the balance after one month would be $" << account1.getBalance() << std::endl;
        std::cout << "The interest for account 2 would be $" << (account2.getBalance() - balance2)
            << " and the balance after one month would be $" << account2.getBalance() << std::endl;

        std::cout << "\nWould you like to change the interest rate? (Y or N): ";
        std::cin >> changeInterest;
        changeInterest = std::toupper(changeInterest);

    } while (changeInterest == 'Y');

    std::cout << "Goodbye!" << std::endl;

    return 0;
}