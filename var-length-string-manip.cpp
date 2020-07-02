
/*
 [Book Example] Pointer Problem: Variable-Length String Manipulation
 * append
 * concatenate
 * characterAt
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

typedef char * arrayString; //pointer to an array of characters in HEAP

// if a pointer is assigned the address of an array, we can access elements in the array using normal array
// notation
char characterAt(arrayString s, int position){
    return s[position];
}

//helper function: a function that encapsulates an operation common to several other functions
int length(arrayString s){
    int count = 0;
    while(s[count] != 0){
        count++;
    }
    return count;
}

void append(arrayString &s, char c){
    int oldLength = length(s);
    arrayString newS = new char[oldLength + 2];
    for(int i = 0; i < oldLength; i++){
        newS[i] = s[i];
    }
    newS[oldLength] = c;
    newS[oldLength + 1] = 0;
    delete[] s; //array s previously pointed to is deallocated
    s = newS; //repoint the first parameter at the newly allocated string
}

void concatenate(arrayString & s1, arrayString s2){
    int s1_OldLength = length(s1);
    int s2_OldLength = length(s2);
    int s1_NewLength = s1_OldLength + s2_OldLength;
    
    arrayString newS = new char[s1_NewLength + 1];
    
    for(int i = 0; i < s1_OldLength; i++){
        newS[i] = s1[i];
    }
    
    for(int i = 0; i < s2_OldLength; i++){
        newS[s1_OldLength + i] = s2[i];
    }
    
    newS[s1_NewLength] = 0;
    delete[] s1;
    s1 = newS;
}

int main() {
    
    //test case 1 :
    
    arrayString a = new char[5];
    a[0] = 't'; a[1] = 'e'; a[2] = 's'; a[3] = 't'; a[4] = 0;
    
    arrayString b = new char[4];
    b[0] = 'b'; b[1] = 'e'; b[2] = 'd'; b[3] = 0;
    
    concatenate(a, b);
    
    cout << a << endl << b << endl;
    
    //test case 2:
    
    arrayString c = new char[6];
    c[0] = 'h'; c[1] = 'e'; c[2] = 'l'; c[3] = 'l'; c[4] = 'o'; c[5] = 0;
    
    arrayString d = new char[1];
    d[0] = 0;
    
    concatenate(d,c);
    
    cout << c << endl << d << endl;
    cout << (void * ) c << endl << (void *) d << endl; //forces output to display raw values of pointers
}

    

