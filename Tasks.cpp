#include "Tasks.h"
#include <iostream>

using namespace std;
double findMin(const double array[], int size) {
    //a very big initiate number to compare the numbers in the received array and that way output the smallest found
    //wont work if number is beyond minVal (would be smart to use a minimal possible double variable size)
    double minVal = 9999999;
    //loop to cycle through all array elements and save the smallest one gradually
    for (int i = 0; i < size; ++i) {
        if (array[i] < minVal) {
            minVal = array[i];
        }
    }
    return minVal;
}

double findMax(const double array[], int size) {
    //a very small initiate number to compare the numbers in the received array and that way output the biggest found
    double maxVal = -999999;
    //loop to cycle through all array elements and save the smallest one gradually
    for (int i = 0; i < size; ++i) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }
    return maxVal;
}
//function to call the task 1 in the main file 
int Tasks::task1main() {
    //initialise an array and assign elements
    double array[5] = { 1.5, -3.2, 7.8, 0.4, -1.1 };
    //get the amount of elements in the array (in case user input is implemented and size isnt constant)
    int elementAmount = sizeof(array) / 8;
    //get the minimal values using previously defined functions
    double minVal = findMin(array, elementAmount);
    double maxVal = findMax(array, elementAmount);
    //display the values
    cout << "Sum of the minimal and maximal value of the array is " << minVal << " + " << maxVal << " = " << minVal + maxVal << endl;
    return 0;
}

//create row and column variables for possible future expansion
const int ROWS = 3;
const int COLS = 3;

//function to fill a two dimensional array (matrix) with pseudorandom numbers
void fillMatrix(int matrix[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            //put a "random" value into the array element at array[i][j]
            matrix[i][j] = rand() % 10;
        }
    }
}
//function to multiply individual matrix elements and write the product into the corresponding position
void multiplyMatrices(const int A[ROWS][COLS], const int B[ROWS][COLS], int C[ROWS][COLS], int rows, int cols) {
    for (int i = 0; i < rows; ++i) {
        for (int j = 0; j < cols; ++j) {
            C[i][j] = 0;
            for (int k = 0; k < cols; ++k) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
}

int Tasks::task2main() {
//initiate 3 matrices
    int A[ROWS][COLS];
    int B[ROWS][COLS];
    int C[ROWS][COLS];
//fill matrices A and B to multiply them and write the product into C further
    fillMatrix(A, ROWS, COLS);
    fillMatrix(B, ROWS, COLS);
//multiply the corresponding elements
    multiplyMatrices(A, B, C, ROWS, COLS);
//display multiplicand (matrix A)
    cout << "Matrix A: " << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << A[i][j] << " ";
        }
        cout << endl;
    }
//display multiplier (matrix B)
    cout << "Matrix B: " << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << B[i][j] << " ";
        }
        cout << endl;
    }
//display product (matrix C)
    cout << "Multiplication result: " << endl;
    for (int i = 0; i < ROWS; ++i) {
        for (int j = 0; j < COLS; ++j) {
            cout << C[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

