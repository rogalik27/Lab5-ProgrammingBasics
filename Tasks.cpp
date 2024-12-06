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
