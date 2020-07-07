/*
create a function substring that takes three parameters: an arrayString, a starting position integer, and an integer length of characters. 
The function returns a pointer to a new dynamically allocated string array. This string array contains the characters in the original string, 
starting at the specified position for the specified length. The original string is unaffected by the operation.
*/

#include <iostream>
#include <cmath>
using namespace std;

typedef char * arrayString; //pointer to an array of characters in HEAP

/*
 returns: a pointer to new dynamically allocated string array
 original string is unaffected
*/
arrayString substring(arrayString s, int start, int length){
    arrayString newS = new char[length+1];
    
    for(int i = 0; i < length; i++){
        newS[i] = s[start+i];
    }
    newS[length] = 0;
    
    return newS;
}

int main() {
    arrayString e = new char[7];
    e[0] = 'e'; e[1] = 'u'; e[2] = 'n'; e[3] = 'i'; e[4] = 'c'; e[5] = 'e'; e[6] = 0;
    
    arrayString newE = substring(e, 2, 4);
    
    cout << newE << endl << e << endl;

    return 0;
}
