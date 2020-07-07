/*
 Exercise 3-7:
 Write a program that is given an array of integers and determines the mode, which is the
 number that appears most frequently in the array.
 */

#include <iostream>
using std::cin;
using std::cout;

int maximum(int array[], int ARRAY_SIZE){
    int max = array[0];
    for(int i = 1; i < ARRAY_SIZE; i++){
        if(array[i] > max){
            max = array[i];
        }
    }
    return max;
}

int main(int argc, const char * argv[]) {
    
    int const ARRAY_SIZE = 10;
    
    int array[ARRAY_SIZE] = {7,8,8,2,1,4,1,9,8,9};
    
    cout << "Array Elements: ";
    for(int i = 0; i < ARRAY_SIZE; i++){
        cout << array[i] << " ";
    }
    
    cout << "\n";
    
    int maximumValue = maximum(array, ARRAY_SIZE);
    
    cout << "Maximum Value: " << maximumValue << "\n";
    
    int histogram[maximumValue + 1];
    
    //setting all initial histogram values to 0
    for(int i = 0; i < maximumValue; i++){
        histogram[i] = 0;
    }
    
    //increasing the values of histogram at corresponding index of array value
    for(int i = 0; i < ARRAY_SIZE; i++){
        int value = array[i];
        histogram[value]++;
    }
    
    int mode = 0;
    
    for(int i = 1; i < maximumValue; i++){
        if(histogram[i] > histogram[mode]){
            mode = i;
        }
    }
    
    cout << "Mode of array: " << mode << "\n";
    
}
