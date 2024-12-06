#include "Tasks.h"
#include <iostream>

const int ARRAY_SIZE = 5;

double findMin(const double array[], int size) {
    double minVal = std::numeric_limits<double>::max();
    for (int i = 0; i < size; ++i) {
        if (array[i] < minVal) {
            minVal = array[i];
        }
    }
    return minVal;
}

double findMax(const double array[], int size) {
    double maxVal = std::numeric_limits<double>::lowest();
    for (int i = 0; i < size; ++i) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }
    return maxVal;
}
//function to call the task 1 in the main file 
int Tasks::task1main() {
    double array[ARRAY_SIZE] = { 1.5, -3.2, 7.8, 0.4, -1.1 };
    double minVal = findMin(array, ARRAY_SIZE);
    double maxVal = findMax(array, ARRAY_SIZE);

    std::cout << "Sum of the   " << (minVal + maxVal) << std::endl;
    return 0;
}
