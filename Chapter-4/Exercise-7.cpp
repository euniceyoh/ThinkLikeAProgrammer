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

/*
 parameters: pointers to first nodes of linked lists
 function: create a copy of nodes in s2 & append them to end of s1
 */
void concatenate(growingString s1, growingString s2){
    charNode * loopPtr = s2;
    charNode * copy = new charNode;
    while(loopPtr != NULL){
        copy->letter = loopPtr->letter;
        append(s1, copy->letter);
        loopPtr = loopPtr->next;
    }
    delete copy;
}
/*
 remove 'length' # of chars starting from character at 'position'
 make sure removed nodes are properly deallocated
 */
void removeChars(growingString s, int position, int length){
    charNode * loopPtr = s;
    for(int i = 0; i < position - 1; i++){
        loopPtr = loopPtr->next;
    }
    for(int i = 0; i < length; i++){
        charNode * current = loopPtr->next;
        loopPtr->next = loopPtr->next->next;
        delete current;
        loopPtr = loopPtr->next;
    }
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
    first->letter = 'e';
    
    gs = first;
    first->next = NULL;
    //first = NULL;
    //printString(gs);
    append(gs, 'u');
    append(gs, 'n');
    append(gs, 'i');
    append(gs, 'c');
    append(gs, 'e');
    //printString(gs);
    
    growingString gsTwo;
    charNode * begin = new charNode;
    begin->letter = 'o';
    
    gsTwo = begin;
    begin->next = NULL;
    begin = NULL;
    
    //printString(gsTwo);
    append(gsTwo, 'm');
    append(gsTwo, 'g');
    //printString(gsTwo);
    
    concatenate(gs, gsTwo);
    printString(gs);
    printString(gsTwo);
    
    removeChars(gs, 2, 4);
    printString(gs);
}
