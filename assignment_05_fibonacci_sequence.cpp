// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 5
// =============================================================================
//
// TASK: Fibonacci Sequence Generator
//
// The Fibonacci sequence is a series of numbers where each number is the sum
// of the two numbers before it:
//
//   0, 1, 1, 2, 3, 5, 8, 13, 21, 34, ...
//
// Write a C++ program with TWO parts, each implemented as a function.
//
// -----------------------------------------------------------------------------
// PART A — Print the First N Terms
// -----------------------------------------------------------------------------
// - Ask the user how many terms (N) to display.
// - Print the first N numbers of the Fibonacci sequence on one line.
//
// Example:
//   How many terms? 7
//   Fibonacci sequence: 0 1 1 2 3 5 8
//
// -----------------------------------------------------------------------------
// PART B — Check if a Number Belongs to the Sequence
// -----------------------------------------------------------------------------
// - Ask the user to enter a number.
// - Determine whether that number is a Fibonacci number.
// - Print an appropriate message.
//
// Example:
//   Enter a number to check: 13
//   13 is a Fibonacci number.
//
//   Enter a number to check: 20
//   20 is NOT a Fibonacci number.
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use a loop (not recursion) to generate the sequence in both parts.
// - N must be a positive integer. If it is not, print an error message.
// - Each part must be implemented in its own function (see scaffold below).
//

//
// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
using namespace std;

void printFibonacci(int n) 
{
    if (n <= 0) 
    {
        cout << "Error: Number of terms must be a positive integer." << endl;
        return;
    }

    int first = 0, second = 1, next;

    cout << "Fibonacci sequence: ";
    for (int i = 0; i < n; ++i) 
    {
        if (i <= 1)
            next = i; // First two terms are 0 and 1
        else 
        {
            next = first + second;
            first = second;
            second = next;
        }
        cout << next << " ";
    }
    cout << endl;
}   
void checkFibonacci(int number) 
{
    if (number < 0) 
    {
        cout << "Error: Number must be a non-negative integer." << endl;
        return;
    }

    int first = 0, second = 1, next = 0;

    while (next < number) 
    {
        next = first + second;
        first = second;
        second = next;
    }

    if (next == number || number == 0) 
    {
        cout << number << " is a Fibonacci number." << endl;
    } 
    else 
    {
        cout << number << " is NOT a Fibonacci number." << endl;
    }
}   
int main() 
{
    int choice;
    cout << "Choose an option:\n";
    cout << "1. Print the first N terms of the Fibonacci sequence\n";
    cout << "2. Check if a number belongs to the Fibonacci sequence\n";
    cout << "Enter your choice (1 or 2): ";
    cin >> choice;

    switch (choice) 
    {
        case 1: 
        {
            int n;
            cout << "How many terms? ";
            cin >> n;
            printFibonacci(n);
        }
        break;
        case 2: 
        {
            int number;
            cout << "Enter a number to check: ";
            cin >> number;
            checkFibonacci(number);
        }
        break;
        default:
            cout << "Invalid choice. Please enter 1 or 2." << endl;
    }

    return 0;
}   