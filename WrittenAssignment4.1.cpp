#include <iostream>
#include <string>
#include <stdexcept>

// Utility function to find the greatest common divisor
int gcd(int a, int b) {
    if (b == 0) {
        return a;
    }
    return gcd(b, a % b);
}

class RationalNumber {
public:
    // Constructor
    RationalNumber(int numerator = 0, int denominator = 1) {
        if (denominator == 0) {
            throw std::invalid_argument("Denominator cannot be zero.");
        }

        int gcdValue = gcd(numerator, denominator);
        this->numerator = numerator / gcdValue;
        this->denominator = denominator / gcdValue;

        if (this->denominator < 0) {
            this->numerator = -this->numerator;
            this->denominator = -this->denominator;
        }
    }

    // Overloaded operators
    RationalNumber operator+(const RationalNumber& other) const {
        return RationalNumber(numerator * other.denominator + other.numerator * denominator, denominator * other.denominator);
    }

    RationalNumber operator-(const RationalNumber& other) const {
        return RationalNumber(numerator * other.denominator - other.numerator * denominator, denominator * other.denominator);
    }

    RationalNumber operator*(const RationalNumber& other) const {
        return RationalNumber(numerator * other.numerator, denominator * other.denominator);
    }

    RationalNumber operator/(const RationalNumber& other) const {
        if (other.numerator == 0) {
            throw std::invalid_argument("Division by zero.");
        }
        return RationalNumber(numerator * other.denominator, denominator * other.numerator);
    }

    // Relational and equality operators
    bool operator==(const RationalNumber& other) const {
        return numerator == other.numerator && denominator == other.denominator;
    }

    bool operator!=(const RationalNumber& other) const {
        return !(*this == other);
    }

    // String representation
    std::string toString() const {
        return std::to_string(numerator) + '/' + std::to_string(denominator);
    }

    // As a double
    double toDouble() const {
        return static_cast<double>(numerator) / denominator;
    }

private:
    int numerator;
    int denominator;
};

int main() {
    RationalNumber r1(2, 4);
    RationalNumber r2(1, 3);

    RationalNumber r3 = r1 + r2;
    RationalNumber r4 = r1 - r2;
    RationalNumber r5 = r1 * r2;
    RationalNumber r6 = r1 / r2;

    std::cout << "Rational numbers: " << r1.toString() << " and " << r2.toString() << std::endl;
    std::cout << "Sum: " << r3.toString() << std::endl;
    std::cout << "Difference: " << r4.toString() << std::endl;
    std::cout << "Product: " << r5.toString() << std::endl;
    std::cout << "Quotient: " << r6.toString() << std::endl;

    return 0;
}