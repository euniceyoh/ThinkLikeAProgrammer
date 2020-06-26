
/*
 Excercise 3-3: 
 Write a bool function that is passed an array and the number of elements in that array and
 determines whether the data in the array is sorted. This should require only one pass!
 */

#include <iostream>
using std::cin;
using std::cout;
using std::string;

bool isSorted(int array[], int ARRAY_SIZE){
    for(int i = 0; i < ARRAY_SIZE - 1; i++){
        if(array[i] > array[i+1]){
            return false;
        }
    }
    return true;
}

int main(int argc, const char * argv[]) {
    const int ARRAY_SIZE = 10;
    
    int arrayA[ARRAY_SIZE] = {1,2,3,4,5,6,7,8,9,10};
    
    cout << isSorted(arrayA, ARRAY_SIZE) << "\n";
    
    int arrayB[ARRAY_SIZE] = {9,51,11,59,85,27,25,15,37,82};
    
    cout << isSorted(arrayB, ARRAY_SIZE) << "\n";
}
