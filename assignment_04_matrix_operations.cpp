// =============================================================================
// PROGRAMMING FUNDAMENTALS — Assignment 4
// =============================================================================
//
// TASK: Matrix Operations
//
// Write a C++ program that performs three operations on matrices (2D arrays),
// each implemented in its own function.
//
// NOTE: Use a fixed maximum size of 10 for array dimensions.
//       Declare arrays as int matrix[10][10].
//
// -----------------------------------------------------------------------------
// PART A — Transpose a Matrix
// -----------------------------------------------------------------------------
// - Read an M x N matrix from the user.
// - Compute and display its transpose (rows become columns, columns become rows).
//
// Example (2 x 3 input):
//
//   Original Matrix:      Transposed Matrix:
//   1  2  3               1  4
//   4  5  6               2  5
//                         3  6
//
// -----------------------------------------------------------------------------
// PART B — Add Two Matrices
// -----------------------------------------------------------------------------
// - Read two matrices of exactly the same size (M x N).
// - Compute their element-wise sum and display the result.
//
// -----------------------------------------------------------------------------
// PART C — Multiply Two Matrices
// -----------------------------------------------------------------------------
// - Read matrix A of size M x N and matrix B of size N x P.
//   (Number of COLUMNS in A must equal number of ROWS in B.)
// - Compute and display the matrix product A x B (result is M x P).
//
// -----------------------------------------------------------------------------
// EXPECTED INPUT FORMAT
// -----------------------------------------------------------------------------
// The user enters each row's values one at a time:
//
//   Enter number of rows: 2
//   Enter number of columns: 3
//   Enter element [0][0]: 1
//   Enter element [0][1]: 2
//   ...
//
// -----------------------------------------------------------------------------
// REQUIREMENTS
// -----------------------------------------------------------------------------
// - Use nested loops for all operations (no external libraries).
// - Each operation must be in its own function (see scaffold below).
// - Display each matrix in a neat, aligned grid using setw().
// - Tip: Complete Part A first, then Parts B and C.
//

// =============================================================================
// YOUR CODE BELOW — remove the // symbols from the scaffold and fill it in
// =============================================================================

#include <iostream>
#include <iomanip>
#include <string>
using namespace std;

const int MAX = 10;

void inputMatrix(int matrix[MAX][MAX], int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}
void displayMatrix(int matrix[MAX][MAX], int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}   
void transposeMatrix(int matrix[MAX][MAX], int transposed[MAX][MAX], int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            transposed[j][i] = matrix[i][j];
        }
    }
}   
void addMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rows, int cols) 
{
    for (int i = 0; i < rows; ++i) 
    {
        for (int j = 0; j < cols; ++j) 
        {
            result[i][j] = matrixA[i][j] + matrixB[i][j];
        }
    }
}
void multiplyMatrices(int matrixA[MAX][MAX], int matrixB[MAX][MAX], int result[MAX][MAX], int rowsA, int colsA, int colsB) 
{
    for (int i = 0; i < rowsA; ++i) 
    {
        for (int j = 0; j < colsB; ++j) 
        {   
            result[i][j] = 0;
            for (int k = 0; k < colsA; ++k) 
            {
                result[i][j] += matrixA[i][k] * matrixB[k][j];
            }
        }
    }
}   
int main() 
{
    int choice;
    
    cout << "Matrix Operations" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;          
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice: ";
    cin >> choice;

    int matrixA[MAX][MAX], matrixB[MAX][MAX], result[MAX][MAX];                         

    switch (choice) 
    {
        case 1: 
        {
                int rows, cols;
                cout << "Enter number of rows: ";
                cin >> rows;
                cout << "Enter number of columns: ";
                cin >> cols;

                if (rows <= 0 || rows > MAX || cols <= 0 || cols > MAX) 
                {
                    cout << "Error: Rows and columns must be between 1 and " << MAX << "." << endl;
                    return 1; // Exit the program with an error code
                }

                inputMatrix(matrixA, rows, cols);
                transposeMatrix(matrixA, result, rows, cols);

                cout << "Original Matrix:" << endl;
                displayMatrix(matrixA, rows, cols);
                cout << "Transposed Matrix:" << endl;
                displayMatrix(result, cols, rows); // Note the swapped dimensions
            }
            break;
        case 2: 
        {
                int rows, cols;
                cout << "Enter number of rows: ";
                cin >> rows;
                cout << "Enter number of columns: ";
                cin >> cols;

                if (rows <= 0 || rows > MAX || cols <= 0 || cols > MAX) 
                {
                    cout << "Error: Rows and columns must be between 1 and " << MAX << "." << endl;
                    return 1; // Exit the program with an error code
                }

                cout << "Matrix A:" << endl;
                inputMatrix(matrixA, rows, cols);
                cout << "Matrix B:" << endl;
                inputMatrix(matrixB, rows, cols);

                addMatrices(matrixA, matrixB, result, rows, cols);

                cout << "Resultant Matrix (A + B):" << endl;
                displayMatrix(result, rows, cols);
            }
            break;
        case 3:
        {
                int rowsA, colsA, rowsB, colsB;   
                cout << "Enter number of rows for Matrix A: ";
                cin >> rowsA;
                cout << "Enter number of columns for Matrix A: ";
                cin >> colsA;   
                
                cout << "Enter number of rows for Matrix B: ";
                cin >> rowsB;           
                cout << "Enter number of columns for Matrix B: ";
                cin >> colsB;

                if (colsA != rowsB) 
                {
                    cout << "Error: Matrix multiplication not possible. Number of columns in A must equal number of rows in B." << endl;
                    return 0;
                }

                if (rowsA <= 0 || rowsA > MAX || colsA <= 0 || colsA > MAX ||
                    rowsB <= 0 || rowsB > MAX || colsB <= 0 || colsB > MAX) 
                {
                    cout << "Error: Rows and columns must be between 1 and " << MAX << "." << endl;
                    return 1;
                }

                cout << "Matrix A:" << endl;
                inputMatrix(matrixA, rowsA, colsA);
                cout << "Matrix B:" << endl;
                inputMatrix(matrixB, rowsB, colsB);

                multiplyMatrices(matrixA, matrixB, result, rowsA, colsA, colsB);

                cout << "Resultant Matrix (A x B):" << endl;
                displayMatrix(result, rowsA, colsB);
            }
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
    }

    return 0;
}  
