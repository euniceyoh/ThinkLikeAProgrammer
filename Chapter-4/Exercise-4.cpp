
#include <iostream>
using namespace std;

typedef char * arrayString;

char characterAt(arrayString s, int position){
    return s[position+1];
}

void append(arrayString &s, char c){
    int length = s[0];                      // get size of array from location[0]
    arrayString newS = new char[length+2];  // add 2 to account for location[0] & new char
    for(int i = 1; i <= length; i++){       // actual string starts at index 1 and ends at same index of actual length
        newS[i] = s[i];
    }
    newS[length+1] = c;                     // append the char to end of string
    newS[0] = length + 1;                   // update the length of string
    delete[] s;
    s = newS;
}

void concatenate(arrayString & s1, arrayString s2){
    int s1Length = s1[0];
    int s2Length = s2[0];
    int s1_NewLength = s1Length + s2Length;
    arrayString newS = new char[++s1_NewLength];
    
    for(int i = 1; i <= s1Length; i++){
        newS[i] = s1[i];
    }
    for(int i = 1; i <= s2Length; i++){
        newS[s1Length+i] = s2[i];
    }
    
    newS[0] = s1_NewLength;
    delete[] s1;
    s1 = newS;
}

void print(arrayString s){
    int length = s[0];
    for(int i = 0; i < length; i++){
        cout << characterAt(s, i);
    }
    cout << endl;
}

int main(){
    arrayString myName = new char[7];
    myName[0] = 6;
    myName[1] = 'e';
    myName[2] = 'u';
    myName[3] = 'n';
    myName[4] = 'i';
    myName[5] = 'c';
    myName[6] = 'e';
    
    print(myName);

    append(myName, 'o');

    print(myName);
    
    arrayString lastName = new char[3];
    lastName[0] = 2;
    lastName[1] = 'o';
    lastName[2] = 'h';
    
    concatenate(myName, lastName);
    
    print(myName);

    
}
