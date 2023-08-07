#include <iostream>

using namespace std;
//allows us to use input and output features

double larger(double x, double y);
//identifier that allows us to use the "larger" function

int main() {
    double n1{ 0 };
    double n2{ 0 };
    //setting up double variables for "larger" function

    cout << "Enter 15 numbers\n";
    //asking for input from user
    cin >> n1 >> n2;
    //takes in the input and saves into our variables

    double max = larger(n1, n2);
    //creates a variable to be the max number by using the "larger" function

    for (int i = 0; i < 13; ++i) {//for loop
        cin >> n1;
        max = larger(n1, max);
    }
    cout << "The largest number is " << max;
    return 0;
}

double larger(double x, double y) {
    if (x > y)
        return x;
    else
        return y;
}


