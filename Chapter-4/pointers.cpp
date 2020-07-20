#include <iostream>
using namespace std; 

int main() {
    /*
     Pointers
     */
    
    int* applePointer;              // an int pointer, a type that holds memory address of integers
    int apple = 8;                  // a variable with an integer type
    
    applePointer = &apple;          // applePointer contains memory address of apple
                                    //applePointer now points to apple
    cout << "Address of apple: " << applePointer << endl;
    
    int appleValue;                 // a variable with the same type as apple
    appleValue = *applePointer;     // dereferencing apple pointer
                                    // accessing memory at other end of applePointer
    cout << "Value of apple: " << appleValue << endl;
    
    /*
     References
     */
    
    int& appleReference = apple;    // both apple & appleReference can access the value of apple
    applePointer = &appleReference; // applePointer points to memory address of apple
    cout << "Address of appleReference: " << applePointer << endl;
    
    /*
    Pointers and Arrays
    */
    
    int numbers[5];
    int * p;
    p = numbers;
    *p = 10;
    p++;
    *p = 20;
    p = &numbers[2];
    *p = 30;
    p = numbers + 3;
    *p = 40;
    p = numbers;
    *(p+4) = 50; // same thing as p[4]
    
    for (int n=0; n<5; n++)
      cout << numbers[n] << ", ";
    
    return 0; 
}
