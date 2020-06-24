/*
Desired Shape: 
    ##
   ####
  ######
 ########
 ########
  ######
   ####
    ##
 */
 
#include <iostream>
using std::cin;
using std::cout;

int main(int argc, const char * argv[]) {
    
    // top half
    for(int topRow = 1; topRow <= 4; topRow++){
        
        for(int spaceTop = 1; spaceTop <= 4 - topRow; spaceTop++){
            cout << ' ';
        }
        
        for(int hashMarks = 1; hashMarks <= 2 * topRow; hashMarks++){
            cout << "#";
        }
        cout << "\n";
    }
    
    //bottom half
    for(int rows = 1; rows <= 4; rows++){
        
        for(int hashMarks = 1; hashMarks <=  10 - (rows*2); hashMarks++){
            cout << "#";
        }
        cout << "\n";
        
        for(int space = 1; space <= rows; space++){
            cout << ' ';
        }
    
    }
    return 0;
}
