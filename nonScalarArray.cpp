/*
 Chapter 3 Example: Non-Scalar Arrays
 Code directly from the book
 */

#include <iostream>
using std::cin;
using std::cout;
using std::string;

int main(int argc, const char * argv[]) {
    struct student {
        int grade;
        int studentID;
        string name;
    };
    
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
    
    int highPosition = 0;
    for(int i = 1; i < ARRAY_SIZE; i++){
        if(studentArray[i].grade > studentArray[highPosition].grade){
            //tracking the location of the array with the highest grade
            //more general data -> allows to retrive any information from the student later
            highPosition = i;
        }
    }

    cout << studentArray[highPosition].name << "\n";
    cout << studentArray[highPosition].studentID << "\n";
    cout << studentArray[highPosition].grade << "\n";
    
}
    
