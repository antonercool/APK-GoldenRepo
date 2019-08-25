#include "constClass.hpp"
#include <iostream>

using namespace std;


ConstClass::ConstClass(int newData)
{
    data = newData;
}

void ConstClass::printData() {
    cout << "printing data : " << data << endl;
}

void ConstClass::printDataConst() const{
    cout << "printing data CONST : " << data << endl; 
}