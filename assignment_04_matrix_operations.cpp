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


const int MAX_SIZE = 10;

// Function Prototypes
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const string &name);
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols);
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int output[MAX_SIZE][MAX_SIZE], int rows, int cols);
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols);
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB);

int main() {
    int choice;

    cout << "=== MATRIX OPERATIONS MENU ===" << endl;
    cout << "1. Transpose a Matrix" << endl;
    cout << "2. Add Two Matrices" << endl;
    cout << "3. Multiply Two Matrices" << endl;
    cout << "Enter your choice (1-3): ";
    cin >> choice;

    if (choice == 1) {
        // PART A: Transpose
        int rows, cols;
        int matrix[MAX_SIZE][MAX_SIZE];
        int transposed[MAX_SIZE][MAX_SIZE];

        cout << "\nEnter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(matrix, rows, cols, "Matrix");

        cout << "\nOriginal Matrix:" << endl;
        printMatrix(matrix, rows, cols);

        transposeMatrix(matrix, transposed, rows, cols);

        cout << "\nTransposed Matrix:" << endl;
        printMatrix(transposed, cols, rows); // Notice rows and cols flip!

    } else if (choice == 2) {
        // PART B: Addition
        int rows, cols;
        int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], sum[MAX_SIZE][MAX_SIZE];

        cout << "\nEnter number of rows: ";
        cin >> rows;
        cout << "Enter number of columns: ";
        cin >> cols;

        readMatrix(A, rows, cols, "Matrix A");
        readMatrix(B, rows, cols, "Matrix B");

        addMatrices(A, B, sum, rows, cols);

        cout << "\nResult of Matrix Addition (A + B):" << endl;
        printMatrix(sum, rows, cols);

    } else if (choice == 3) {
        // PART C: Multiplication
        int rowsA, colsA, rowsB, colsB;
        int A[MAX_SIZE][MAX_SIZE], B[MAX_SIZE][MAX_SIZE], product[MAX_SIZE][MAX_SIZE];

        cout << "\nEnter rows for Matrix A: ";
        cin >> rowsA;
        cout << "Enter columns for Matrix A: ";
        cin >> colsA;

        cout << "Enter rows for Matrix B: ";
        cin >> rowsB;
        cout << "Enter columns for Matrix B: ";
        cin >> colsB;

        // Check matrix multiplication dimension rule
        if (colsA != rowsB) {
            cout << "\nError: Columns of Matrix A must equal Rows of Matrix B!" << endl;
            return 0;
        }

        readMatrix(A, rowsA, colsA, "Matrix A");
        readMatrix(B, rowsB, colsB, "Matrix B");

        multiplyMatrices(A, B, product, rowsA, colsA, colsB);

        cout << "\nResult of Matrix Multiplication (A x B):" << endl;
        printMatrix(product, rowsA, colsB);

    } else {
        cout << "Invalid choice program terminating." << endl;
    }

    return 0;
}

// Helper function to read elements into a matrix
void readMatrix(int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols, const string &name) {
    cout << "\nEnter elements for " << name << ":" << endl;
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << "Enter element [" << i << "][" << j << "]: ";
            cin >> matrix[i][j];
        }
    }
}

// Helper function to display matrix neatly using setw
void printMatrix(const int matrix[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            cout << setw(5) << matrix[i][j];
        }
        cout << endl;
    }
}

// PART A: Transpose logic
void transposeMatrix(const int input[MAX_SIZE][MAX_SIZE], int output[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            output[j][i] = input[i][j];
        }
    }
}

// PART B: Addition logic
void addMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rows, int cols) {
    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            result[i][j] = A[i][j] + B[i][j];
        }
    }
}

// PART C: Multiplication logic
void multiplyMatrices(const int A[MAX_SIZE][MAX_SIZE], const int B[MAX_SIZE][MAX_SIZE], int result[MAX_SIZE][MAX_SIZE], int rowsA, int colsA, int colsB) {
    for (int i = 0; i < rowsA; i++) {
        for (int j = 0; j < colsB; j++) {
            result[i][j] = 0; // Reset sum element
            for (int k = 0; k < colsA; k++) {
                result[i][j] += A[i][k] * B[k][j];
            }
        }
    }


