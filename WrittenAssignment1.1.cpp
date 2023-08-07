#include<iostream>
using namespace std;
//allows us access to input and output


// function that will print number in words
void numToWords(int x)
{
    if (x == 1) { 
        cout << "one\n"; 
    }  // checking if x is equal to 1

    else if (x == 2) {
        cout << "two\n"; 
    } // checking if x is equal to 2

    else if (x == 3) {
        cout << "three\n"; 
    }  // checking if x is equal to 3

    else if (x == 4) {
        cout << "four\n"; 
    }  // checking if x is equal to 4

    else if (x == 5)  {
        cout << "five\n"; 
    }  // checking if x is equal to 5
}

//driver code
int main()
{
    int number{ 0 }; //variable of type int to store user input
    
    cout << "Enter a whole number in the range 1-5 : ";//prompt to user to enter a number
    cin >> number;  //takes user input and saves into variable
    numToWords(number); // calling function to determine number to transfer to words


    return 0;
}