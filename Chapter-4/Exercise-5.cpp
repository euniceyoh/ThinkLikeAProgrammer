/*
 Pointer Problem: TRACKING AN UNKNOWN QUANTITY OF STUDENT RECORDS
 */

#include <iostream>
using std::cin;
using std::cout;
using std::endl;

//Building a List of Nodes:
struct listNode {
    int studentNum;
    int grade;
    listNode * next; //needs to contain pointer to same struct
};

typedef listNode * studentCollection; //declaring typedef "studentCollection" for a pointer to our node type

//Adding Nodes to a List:
void addRecord(studentCollection &sc, int stuNum, int gr){ //sc is reference parameter b/c we change its value
    listNode * newNode = new listNode;
    newNode->studentNum = stuNum;
    newNode->grade = gr;
    newNode->next = sc;
    sc = newNode;
}

// removes record with student number "stuNum" from the collection
bool removeRecord(studentCollection &sc, int stuNum){
     
    // if collection is empty
    if(sc == NULL){
        return false;
    }
    
    // if record to be removed is head
    if(sc->studentNum == stuNum){
        listNode * temp = sc;
        sc = sc->next;
        delete temp;
        return true;
    }
    
    // if record to be removed is in middle or tail of collection
    listNode * prev = sc;
    listNode * curr = sc->next;

    while(curr != NULL && curr->studentNum != stuNum){
        curr = curr->next;
        prev = prev->next;
    }
    
    if(curr != NULL){
        prev->next = curr->next; // prev->next will be NULL if removed record is last node
        delete curr;
        return true;
    }
    
    return false;
}

}

bool printCollection(studentCollection sc){
    if(sc == NULL){
        return false;
    }
    
    listNode * loopPtr = sc;
    while(loopPtr != NULL){
        cout <<  "Student ID: " << loopPtr->studentNum << " Student Grade: " << loopPtr->grade << endl;
        loopPtr = loopPtr->next;
    }
    return true;
}

//List Traversal:
double averageRecord(studentCollection sc){
    //special case
    if(sc == NULL){
        return 0;
    }
    
    int count = 0;
    int sum = 0;
    listNode * loopPtr = sc; //storing a pointer to the current node
    while(loopPtr != NULL){
        sum += loopPtr->grade;
        count++;
        loopPtr = loopPtr->next;
    }
    double average = (sum*1.0)/count;
    return average;
}

int main() {
    //sample linked list:
    studentCollection sc;
    listNode * node1 = new listNode; //node1 is a pointer to a listNode
    node1->studentNum = 1001; node1->grade = 78; //-> indicate the field of a pointed-to struct or class
    
    listNode * node2 = new listNode;
    node2->studentNum = 1012; node2->grade = 93;
    
    listNode * node3 = new listNode;
    node3->studentNum = 1076; node3->grade = 85;
    
    sc = node1;
    node1->next = node2;
    node2->next = node3;
    node3->next = NULL; //we assign NULL (aka zero) to terminate the structure / indicate the end of listin
    
    node1 = node2 = node3 = NULL; //assign NULL to each individual node POINTER to avoid potential cross-linking

    addRecord(sc, 1274, 91);
    
    printCollection(sc);
    
    cout << "After removing a record: " << endl;
    
    removeRecord(sc,1274);

    printCollection(sc);
    
}
