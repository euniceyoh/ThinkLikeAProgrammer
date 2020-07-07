/*
Using the same rule as the shapes programs from earlier in the chapter
(only two output statements—one that outputs the hash mark and
one that outputs an end-of-line),
write a program that produces the following shape:
 
########
 ######
  ####
   ##
 
 */
 
#include <iostream>
using std::cin;
using std::cout;

int main(int argc, const char * argv[]) {
    
    for(int rows = 1; rows <= 4; rows++){
        
        for(int hashMarks = 1; hashMarks <=  10 - (rows*2); hashMarks++){
            cout << "#";
        }
        cout << "\n";
        
        for(int space = 1; space <= rows; space++){
            cout << " ";
        }
      
    }
    return 0;
}
