/*
 Pointer Problem: Implementation for strings that uses a linked list of characters instead of dynamically allocated arrays. 
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

struct charNode {
    char letter;
    charNode * next;
};

typedef charNode * growingString;

void append(growingString gs, char c){
    charNode * newNode = new charNode;
    newNode->letter = c;
    newNode->next = NULL;
    
    charNode * loopPtr = gs;
    while(loopPtr->next != NULL){
        loopPtr = loopPtr->next;
    }
    loopPtr->next = newNode;
}

char characterAt(growingString gs, int position){
    charNode * loopPtr = gs;
    for(int i = 0; i < position; i++){
        loopPtr = loopPtr->next;
    }
    return loopPtr->letter;
}

bool printString(growingString gs){
    if(gs == NULL){
        return false;
    }
    
    charNode * loopPtr = gs;
    while(loopPtr != NULL){
        cout << loopPtr ->letter;
        loopPtr = loopPtr->next;
    }
    cout << endl;
    return true;
}

int main() {
    growingString gs;
    charNode * first = new charNode;
    first->letter = 'a';
    
    gs = first;
    first->next = NULL;
    
    first = NULL;
    
    printString(gs);
    append(gs, 'b');
    append(gs, 'c');
    append(gs, 'd');
    printString(gs);
    
}
