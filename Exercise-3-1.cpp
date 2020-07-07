/*
 Excercise 3-1:
 To make sure you are comfortable with qsort, write code that uses the function to sort an
 array of our student struct. First have it sort by grade, and then try it again using the
 student ID.
 */

#include <iostream>
using std::cin;
using std::cout;
using std::string;

/*
 Comparator Function for qsort (Book Example)
 Parameters: two void pointers (always the case)
 Returns: an int, either positive, negative, or zero
 */
int compareFunc(const void * voidA, const void * voidB){
    //cast those void pointers to pointers to the element type in your array
    int * intA = (int *)(voidA);
    int * intB = (int *)(voidB);
    return *intA - *intB;
}

struct student {
    int grade;
    int studentID;
    string name;
};
 
//sorting by grade:
int compareFuncByGrade(const void * voidA, const void * voidB) {
   student* studentA = (student*)(voidA);
   student* studentB = (student*)(voidB);
   return studentA-> grade - studentB-> grade;
}

//sorting by ID:
int compareFuncByID(const void* A, const void* B){
    student* studentA = (student*) (A);
    student* studentB = (student*) (B);
    return studentA->studentID - studentB->studentID;
}

int main(int argc, const char * argv[]) {
    
    const int ARRAY_SIZE = 10;

    student studentArray[ARRAY_SIZE] = {
    {87, 10001, "Fred"},
    {28, 10002, "Tom"},
    {100, 10003, "Alistair"},
    {78, 10004, "Sasha"},
    {84, 10005, "Erin"},
    {98, 10006, "Belinda"},
    {75, 10007, "Leslie"},
    {70, 10008, "Candy"},
    {81, 10009, "Aretha"},
    {68, 10010, "Veronica"}
    };
    
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareFuncByGrade);
    
    cout << "Sort Student By Grade:" << "\n";
    for(int i = 0; i < ARRAY_SIZE; i++){
        cout << studentArray[i].name << "'s Grade : ";
        cout << studentArray[i].grade << "\n";
    }
    
    cout << "\n";
    qsort(studentArray, ARRAY_SIZE, sizeof(student), compareFuncByID);
    
    cout << "Sort Student by ID:" << "\n";
    for(int i = 0; i < ARRAY_SIZE; i++){
        cout << studentArray[i].name << "'s ID: ";
        cout << studentArray[i].studentID << "\n";
    }
    
}
