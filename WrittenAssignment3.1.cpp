#include <iostream>
#include <string>
#include <sstream>

// Complex class for arithmetic with complex numbers
class Complex {
private:
    // Private data members for real and imaginary parts
    double realPart;
    double imaginaryPart;

public:
    // Constructor with default values for real and imaginary parts
    Complex(double real = 1, double imaginary = 1) : realPart(real), imaginaryPart(imaginary) {}

    // Function to add two Complex numbers
    Complex add(const Complex& other) const {
        return Complex(realPart + other.realPart, imaginaryPart + other.imaginaryPart);
    }

    // Function to subtract two Complex numbers
    Complex subtract(const Complex& other) const {
        return Complex(realPart - other.realPart, imaginaryPart - other.imaginaryPart);
    }

    // Function to return a string representation of a Complex number
    std::string toString() const {
        std::stringstream ss;
        ss << "(" << realPart << "," << imaginaryPart << ")";
        return ss.str();
    }
};

// Helper function to parse a Complex number from user input
Complex parseComplex(const std::string& input) {
    double real, imaginary;
    char comma;
    std::stringstream ss(input);
    if (ss >> real >> comma >> imaginary) {
        return Complex(real, imaginary);
    }
    else {
        return Complex(); // Default value
    }
}

int main() {
    std::string input1, input2;

    // Prompt user to enter two Complex numbers
    std::cout << "Enter a Complex number with the real and imaginary parts separated by a comma: ";
    std::getline(std::cin, input1);
    std::cout << "Enter a Complex number with the real and imaginary parts separated by a comma: ";
    std::getline(std::cin, input2);

    // Parse the Complex numbers from user input
    Complex num1 = parseComplex(input1);
    Complex num2 = parseComplex(input2);

    // Calculate the sum and difference of the Complex numbers
    Complex sum = num1.add(num2);
    Complex difference = num1.subtract(num2);

    // Print the sum and difference
    std::cout << "The sum of the two Complex numbers is " << sum.toString() << " and the difference is " << difference.toString() << "." << std::endl;

    return 0;
}