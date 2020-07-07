// 13- Digit ISBN Verification 

#include <iostream>
using std::cin;
using std::cout;

int main(int argc, const char * argv[]) {
    // code
    char digit;
    int checkdigit;
    int checksum = 0;
    int validateCheckDigit;
    
    cout << "Enter a 13-digit number: ";
    
    for(int position = 1; position <= 12; position++){
        cin >> digit;
        if(position % 2 == 0){
            checksum += (digit - '0') * 3;
        }
        else {
            checksum += digit - '0';
        }
    }
    
    cin >> checkdigit;
    
    if(checksum % 10 == 0){
        validateCheckDigit = 0;
    }
    else {
        validateCheckDigit = 10 - (checksum % 10);
    }
    
    if(checkdigit == validateCheckDigit){
        cout << "Verified \n";
    }
    else {
        cout << "Unverified. " << checkdigit << " does not match " << validateCheckDigit << "\n";
    }
    
    return 0;
}
