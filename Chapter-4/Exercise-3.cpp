/*
 Exercise 4-3:
 For our dynamically allocated strings, create a function replaceString that takes three parameters, each of
 type arrayString: source, target, and replaceText. The function replaces every occurrence of target in source
 with replaceText. For example, if source points to an array containing abcdabee, target points to ab, and
 replaceText points to xyz, then when the function ends, source should point to an array containing xyzcdxyzee.
 */

#include <iostream>
#include <cmath>
using namespace std;

typedef char * arrayString; //pointer to an array of characters in HEAP

/*
 if a pointer is assigned the address of an array, we can access elements in the array using normal array
 notation
 */
char characterAt(arrayString s, int position){
    return s[position];
}

/*
 helper function: a function that encapsulates an operation common to several other functions
 */
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

arrayString substring(arrayString s, int start, int length){
    arrayString newS = new char[length+1];
    
    for(int i = 0; i < length; i++){
        newS[i] = s[start+i];
    }
    newS[length] = 0;
    
    return newS;
}

/*
 function that returns true if two strings are equal, otherwise, false
 */
bool isEqual(arrayString stringA, arrayString stringB, int length){
    bool match = true;
    for(int i = 0; i < length; i++){
        if(stringA[i] != stringB[i]){
            match = false;
        }
    }
    return match;
}

/*
 replaces every occurence of target in source with replaceText
 */
void replaceString(arrayString &source, arrayString target, arrayString replaceText){
    int sourceSize = length(source);
    int targetSize = length(target);
    int replaceSize = length(replaceText);
    
    for(int i = 0; i < sourceSize - 1;){
        
        arrayString substr = substring(source, i, targetSize);
        cout << substr << endl;
        
        bool aMatch = isEqual(substr, target, targetSize);
        
        if(aMatch){ // if the sequence of chars in substr is equal to that of target
            arrayString start = substring(source, 0, i);
            arrayString end = substring(source, i + targetSize, sourceSize - (i+targetSize));
            cout << "Start: " << start << " End: " << end << endl;
            
            concatenate(start, replaceText); // start = xyzcd
            concatenate(start, end);         // start = xyzcdabee
        
            source = start;              // source = xyzcdabee
        
            cout << "Updated String: " << source << endl;
            
            sourceSize = length(source); // update new source length
            i+= replaceSize; // replaceSize = 3
    
        } else {
            cout << "Substring not equal " << endl;
            i++;
        }
        
    }
}

int main() {
    
    // test
    arrayString f = new char[9];
    f[0] = 'a'; f[1] = 'b'; f[2] = 'c'; f[3] = 'd'; f[4] = 'a'; f[5] = 'b';  f[6] = 'e'; f[7] = 'e'; f[8] = 0;
    
    arrayString subF = new char[3];
    subF[0] = 'a'; subF[1] = 'b'; subF[2] = 0;
    
    arrayString newSubF = new char[4];
    newSubF[0] = 'x'; newSubF[1] = 'y'; newSubF[2] = 'z'; newSubF[3] = 0;
    
    replaceString(f, subF, newSubF);
    
    cout << "New Source String: " << f << endl;
 
    // another test
    arrayString test = new char [7];
    test[0] = 'e'; test[1] = 'u'; test[2] = 'n'; test[3] = 'i'; test[4] = 'c'; test[5] = 'e'; test[6] = 0;
    arrayString look = new char[5];
    look[0] = 'n'; look[1] = 'i'; look[2] = 'c'; look[3] = 'e'; look[4] = 0;
    arrayString replaceWith = new char[5];
    replaceWith[0] = 'm'; replaceWith[1] = 'e'; replaceWith[2] = 'a'; replaceWith[3] = 'n'; replaceWith[4] = 0;
    
    replaceString(test, look, replaceWith);
    
    cout << "New Source String: " << test << endl;
    
    return 0; 
}

