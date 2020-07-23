#include <iostream>
using namespace std; 

int main(int argc, const char * argv[]) {
    // insert code here...
    int * foo;
    foo = new (nothrow) int[5];
    if(foo == nullptr) {
        cout << "Memory allocation not successful." << endl;
    } else {
        cout << "Memory dynamically allocated." << endl;
    }
    delete foo;
    
    return 0;
}
