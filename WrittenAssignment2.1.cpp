#include <iostream>

const int ARRAY_SIZE = 20;

void add_arrays(const int arr1[], const int arr2[], int arr3[], int size) {
    for (int i = 0; i < size; i++) {
        arr3[i] = arr1[i] + arr2[i];
    }
}

int main() {
    int first_array[ARRAY_SIZE] = { 5, 10, 3, 8, 2, 7, 1, 4, 6, 9, 5, 3, 6, 8, 9, 1, 2, 4, 7, 1 };
    int second_array[ARRAY_SIZE] = { 3, 4, 6, 1, 9, 2, 8, 5, 7, 0, 3, 9, 4, 2, 1, 8, 6, 3, 5, 2 };
    int third_array[ARRAY_SIZE];

    add_arrays(first_array, second_array, third_array, ARRAY_SIZE);

    for (int i = 0; i < ARRAY_SIZE; i++) {
        std::cout << first_array[i];
        std::cout << "+";
        std::cout << second_array[i];
        std::cout << "=";
        std::cout << third_array[i];
        std::cout << std::endl;
    }

    return 0;
}