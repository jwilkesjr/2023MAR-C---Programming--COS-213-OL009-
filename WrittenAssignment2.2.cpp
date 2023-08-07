#include <iostream>

void getScore(int& score) {
    std::cout << "Enter the numerical score (0-100): ";
    std::cin >> score;
    std::cout << "Numerical score: " << score << std::endl;
}

void printGrade(int score) {
    std::cout << "Letter grade: ";
    switch (score / 10) {
    case 10:
    case 9:
        std::cout << "Grade A";
        break;
    case 8:
        std::cout << "Grade B";
        break;
    case 7:
        std::cout << "Grade C";
        break;
    case 6:
        std::cout << "Grade D";
        break;
    default:
        std::cout << "Grade F";
        break;
    }
    std::cout << std::endl;
}

int main() {
    int score;
    getScore(score);
    printGrade(score);
    return 0;
}