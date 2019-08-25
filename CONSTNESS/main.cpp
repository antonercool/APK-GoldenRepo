#include "constClass.hpp"
#include <string>
#include <iostream>

using namespace std;

int main(){

    int testNumber = 42;
    int const constTestNumber = 43;

    int * intPtr = &testNumber;               // int pointer to int
    int * const intConstPtr = &testNumber;    // const int pointer to int // meaning we can move the intPtr
    // NO! constIntPtr = &testNumber2;        // Cannot move PTR
    *intConstPtr = 45;
      cout <<  "const int pointer to int, we can change : " <<   *intConstPtr << endl;
   
    int const * constIntPtr = &constTestNumber;    // int ptr pointer to const int
    //we cannot change value of the int
    const int* const constIntPtrConstInt = &constTestNumber; 
    // We cannot change value // *constIntPtrConstInt = 45;              
    // We cannot moce the ptr // constIntPtrConstInt = &testNumber;

    cout << "local value testNumber : " << testNumber << endl;
 
    // ############## testing const methods on const objects #######
    const ConstClass thisIsConst(54);
    ConstClass thisIsNoneConst(42);

    // None const objects can call both const and none const methods
    thisIsNoneConst.printData();
    thisIsNoneConst.printDataConst();

    // const objects can ONLY call const methods
    thisIsConst.printDataConst();
    // thisIsConst.printData(); !! No not possible


    return 0;
}