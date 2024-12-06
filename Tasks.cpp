#include "Tasks.h"
#include <iostream>

using namespace std;

//TASK 1

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

//TASK 2

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

//TASK 3

const int MATRIX_SIZE = 4;

void transformMatrix(int matrix[MATRIX_SIZE][MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        for (int j = 0; j < MATRIX_SIZE; ++j) {
            if (matrix[i][j] < 0) {
                matrix[i][j] *= matrix[i][j];
            }
        }
    }
}
//fill an array with the square root values of diagonal elements starting from
//top left until bottom right sides (e.g. [0][0], [1][1], [2][2], [3][3], etc)
void createDiagonalSqrt(const int matrix[MATRIX_SIZE][MATRIX_SIZE], double diagonalSqrt[MATRIX_SIZE]) {
    for (int i = 0; i < MATRIX_SIZE; ++i) {
		diagonalSqrt[i] = sqrt(matrix[i][i]);
    }
}
//fill an array with the square root values of diagonal elements starting from
//top right until bottom left sides (e.g. [0][3], [1][2], [2][1], [3][0], etc)
void createDiagonalSqrtMirrored(const int matrix[MATRIX_SIZE][MATRIX_SIZE], double mirroredDiagonalSqrt[MATRIX_SIZE]) {
    int j = MATRIX_SIZE - 1;
    for (int i = 0; i < MATRIX_SIZE; ++i) {
        mirroredDiagonalSqrt[i] = sqrt(matrix[i][j]);
        --j;
    }
}

int Tasks::task3main() {
    //predefine a matrix
    int matrix[MATRIX_SIZE][MATRIX_SIZE] = {
        { 4, -3, 2, -1},
        { -1, 9, -6, 5},
        { 3, -7, 16, -4},
        { 5, -4, -3, 2}
    };
    //define arrays for the second step to store the square roots of diagonal elements
    double diagonalSqrt[MATRIX_SIZE];
    double mirroredDiagonalSqrt[MATRIX_SIZE];

	//first step - all negative elements must be replaced with a number equal to the power of 2 of themselves
	transformMatrix(matrix);
	//display the transformed matrix
	cout << "Transformed matrix:" << endl;
	for (int i = 0; i < MATRIX_SIZE; ++i) {
		for (int j = 0; j < MATRIX_SIZE; ++j) {
			cout << matrix[i][j] << " ";
		}
		cout << endl;
	}
	//fill the previously defined arrays for diagonal elements with square roots of diagonal elements
	createDiagonalSqrt(matrix, diagonalSqrt);
	createDiagonalSqrtMirrored(matrix, mirroredDiagonalSqrt);
	//display corresponding arrays
	cout << "Square roots of diagonal elements" << endl;
	for (int i = 0; i < MATRIX_SIZE; ++i) {
		cout << diagonalSqrt[i] << " ";
	}
	cout << endl;
	cout << "Square roots of mirrored diagonal elements" << endl;
	for (int i = 0; i < MATRIX_SIZE; ++i) {
		cout << mirroredDiagonalSqrt[i] << " ";
	}
    cout << "\n\n\n";
    return 0;
}
