#include "Tasks.h"
#include <iostream>

//const int ARRAY_SIZE = 5;
using namespace std;
double findMin(const double array[], int size) {
    double minVal = 9999999;
    for (int i = 0; i < size; ++i) {
        if (array[i] < minVal) {
            minVal = array[i];
        }
    }
    return minVal;
}

double findMax(const double array[], int size) {
    double maxVal = -999999;
    for (int i = 0; i < size; ++i) {
        if (array[i] > maxVal) {
            maxVal = array[i];
        }
    }
    return maxVal;
}
//function to call the task 1 in the main file 
int Tasks::task1main() {
    double array[5] = { 1.5, -3.2, 7.8, 0.4, -1.1 };
    int elementAmount = sizeof(array) / 8;
    double minVal = findMin(array, elementAmount);
    double maxVal = findMax(array, elementAmount);

    cout << "Sum of the minimal and maximal value of the array is " << minVal << " + " << maxVal << " = " << minVal+maxVal<< endl;
    return 0;
}
