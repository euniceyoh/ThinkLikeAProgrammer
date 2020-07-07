/*
 
  #            #
   ##        ##
    ###    ###
     ########
     ########
    ###    ###
   ##        ##
  #            #
 
 */
  
#include <iostream>
using std::cin;
using std::cout;

int main(int argc, const char * argv[]) {
    
    //top third
 
    int difference = 0;
    
    for(int topRow = 1; topRow <= 3; topRow++){
        
        for(int outerSpace = 1; outerSpace <= topRow - 1; outerSpace++){
            cout << ' ';
            difference+=2;
        }
        
        for(int leftHashMarks = 1; leftHashMarks <= topRow; leftHashMarks++){
            cout << "#";
            difference+=2;
        }
        
        for(int innerSpace = 1; innerSpace <= 14 - difference; innerSpace++){
            cout << ' ';
        }
        
        for(int rightHashMarks = 1; rightHashMarks <= topRow; rightHashMarks++){
            cout << "#";
        }
        
        cout << "\n";
        difference = 0;
    }
    
    //middle third
    
    for(int middleRow = 1; middleRow <= 2; middleRow++){
        
        for(int middleSpace = 1; middleSpace <= 3; middleSpace++){
            cout << ' ';
        }

        for(int middleHashMarks = 1; middleHashMarks <= 8; middleHashMarks++){
            cout << "#";
        }
        cout << "\n";
    }
    
    // bottom third
    
    difference = 0;
    
    for(int bottomRow = 1; bottomRow <= 3; bottomRow++){
        
        for(int outerSpace = 1; outerSpace <= 3 - bottomRow; outerSpace++) {
            cout << ' ';
            difference+=2;
        }
        
        for(int leftHashMarks = 1; leftHashMarks <= 4 - bottomRow; leftHashMarks ++){
            cout << "#";
            difference+=2;
        }
        
        for(int innerSpace = 1; innerSpace <= 14 - difference; innerSpace++) {
            cout << ' ';
        }
        
         for(int rightHashMarks = 1; rightHashMarks <= 4 - bottomRow; rightHashMarks ++){
             cout << "#";
         }
        cout << "\n";
        difference = 0;
        
    }
    
    return 0;
}
