#include <iostream>

class DivByZero {
public:
    static int quotient(int numerator, int denominator) {
        if (denominator == 0) {
            throw DivByZero();
        }
        return numerator / denominator;
    }
};

int main() {
    int numerator, denominator;
    std::cout << "Enter the numerator: ";
    std::cin >> numerator;
    std::cout << "Enter the denominator: ";
    std::cin >> denominator;
    
    try {
        int result = DivByZero::quotient(numerator, denominator);
        std::cout << "Result: " << result << '\n';
    } catch (const DivByZero&) {
        std::cerr << "Error: Attempted to divide by zero\n";
    }
    
    return 0;
}
