#include <iostream>
using namespace std;

int main() {
    // Declare variables
    double num1, num2, result;
    char operation;

    // Greet the user
    cout << "=== Simple Calculator ===" << endl;
    cout << "This program can do +, -, *, / operations." << endl;

    // Ask the user for two numbers
    cout << "Enter the first number: ";
    cin >> num1;

    cout << "Enter the second number: ";
    cin >> num2;

    // Ask for the operation
    cout << "Choose an operation (+, -, *, /): ";
    cin >> operation;

    // Perform the operation based on the user's choice
    switch (operation) {
        case '+':
            result = num1 + num2;
            cout << "Result: " << num1 << " + " << num2 << " = " << result << endl;
            break;
        case '-':
            result = num1 - num2;
            cout << "Result: " << num1 << " - " << num2 << " = " << result << endl;
            break;
        case '*':
            result = num1 * num2;
            cout << "Result: " << num1 << " * " << num2 << " = " << result << endl;
            break;
        case '/':
            if (num2 != 0) {
                result = num1 / num2;
                cout << "Result: " << num1 << " / " << num2 << " = " << result << endl;
            } else {
                cout << "Error: Division by zero is not allowed!" << endl;
            }
            break;
        default:
            cout << "Invalid operation! Please run the program again." << endl;
    }

    cout << "Thanks for using the calculator! :)" << endl;
    return 0;
}