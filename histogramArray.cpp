/*
 Chapter 3 Problem: Finding the Mode
 Code directly from the book
 */

#include <iostream>
using std::cin;
using std::cout;

int main(int argc, const char * argv[]) {
    
    const int ARRAY_SIZE = 12;
    int surveryData[ARRAY_SIZE] = {4, 7, 3, 8, 9, 7, 3, 9, 9, 3, 3, 10};
    
    const int MAX_RESPONSE = 10;
    int histogram[MAX_RESPONSE];
    
    for(int i = 0; i < MAX_RESPONSE; i++){
        histogram[i] = 0;
    }
    
    for(int i = 0; i < ARRAY_SIZE; i++){
        histogram[surveryData[i] - 1]++;
    }
    
    int mostFrequent = 0;
    for(int i = 1; i <MAX_RESPONSE; i++){
        if(histogram[i] > histogram[mostFrequent]){
            mostFrequent = i;
        }
    }
    mostFrequent++;
    
    cout << mostFrequent << "\n";
    
    return 0;
}
    

